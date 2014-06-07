// -----------------------------------------------------------------
// Eigenvalue computation and helper functions
#include "susy_includes.h"
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Gaussian random Twist_Fermion
void rand_TFsource(Twist_Fermion *src) {
  register int i, j, mu, nu;
  register site *s;

  // Begin with pure gaussian random numbers
  FORALLSITES(i, s) {
    for (j = 0; j < DIMF; j++) {                // Site fermions
#ifdef SITERAND
      src[i].Fsite.c[j].real = gaussian_rand_no(&(s->site_prn));
      src[i].Fsite.c[j].imag = gaussian_rand_no(&(s->site_prn));
#else
      src[i].Fsite.c[j].real = gaussian_rand_no(&node_prn);
      src[i].Fsite.c[j].imag = gaussian_rand_no(&node_prn);
#endif
      for (mu = 0; mu < NUMLINK; mu++) {        // Link fermions
#ifdef SITERAND
        src[i].Flink[mu].c[j].real = gaussian_rand_no(&(s->site_prn));
        src[i].Flink[mu].c[j].imag = gaussian_rand_no(&(s->site_prn));
#else
        src[i].Flink[mu].c[j].real = gaussian_rand_no(&node_prn);
        src[i].Flink[mu].c[j].imag = gaussian_rand_no(&node_prn);
#endif

        src[i].Fplaq[mu][mu].c[j] = cmplx(0.0, 0.0);
        for (nu = mu + 1; nu < NUMLINK; nu++) {  // Plaquette fermions
#ifdef SITERAND
          src[i].Fplaq[mu][nu].c[j].real = gaussian_rand_no(&(s->site_prn));
          src[i].Fplaq[mu][nu].c[j].imag = gaussian_rand_no(&(s->site_prn));
#else
          src[i].Fplaq[mu][nu].c[j].real = gaussian_rand_no(&node_prn);
          src[i].Fplaq[mu][nu].c[j].imag = gaussian_rand_no(&node_prn);
#endif
          CNEGATE(src[i].Fplaq[mu][nu].c[j], src[i].Fplaq[nu][mu].c[j]);
        }
      }
    }
  }
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Get Nvec vectors (stored consecutively) and hit them by the matrix
void av_ov (void *x, void *y, int *Nvec, primme_params *primme) {
  int i, j, mu, nu, iter, ivec, Ndat = 16 * DIMF;
  Complex_Z *xx;
  Twist_Fermion src[sites_on_node], res[sites_on_node];

  for (ivec = 0; ivec < *Nvec; ivec++) {
    // Copy double precision complex vector x
    // into Real precision Twist_Fermion src
    // Each Twist_Fermion has Ndat=16DIMF non-trivial complex components
    xx = ((Complex_Z*) x) + Ndat * ivec * sites_on_node;   // This vector in x
    iter = 0;
    for (i = 0; i < sites_on_node; i++) {
      for (j = 0; j < DIMF; j++) {
        src[i].Fsite.c[j].real = xx[iter].r;
        src[i].Fsite.c[j].imag = xx[iter].i;
        iter++;
        for (mu = 0; mu < NUMLINK; mu++) {
          src[i].Flink[mu].c[j].real = xx[iter].r;
          src[i].Flink[mu].c[j].imag = xx[iter].i;
          iter++;

          src[i].Fplaq[mu][mu].c[j] = cmplx(0.0, 0.0);
          for (nu = mu + 1; nu < NUMLINK; nu++) {
            src[i].Fplaq[mu][nu].c[j].real = xx[iter].r;
            src[i].Fplaq[mu][nu].c[j].imag = xx[iter].i;
            iter++;
            CNEGATE(src[i].Fplaq[mu][nu].c[j], src[i].Fplaq[nu][mu].c[j]);
          }
        }
      }
    }

#ifdef DEBUG_CHECK
    if (iter != Ndat * sites_on_node)
      printf("av_ov: iter = %d after source\n", iter);

    // Check that src is the same magnitude as x[ivec]
    register site *s;
    double xmag = 0.0, src_mag = 0.0;
    xx = ((Complex_Z*) x) + Ndat * ivec * sites_on_node;   // This vector in x
    for (i = 0; i < sites_on_node * Ndat; i++)
      xmag += xx[i].r * xx[i].r + xx[i].i * xx[i].i;
    FORALLSITES(i, s)
      src_mag += magsq_TF(&(src[i]));
    if (fabs(xmag - src_mag) > eig_tol * eig_tol) {
      node0_printf("av_ov: |x[%d]|^2 = %.4g but |src|^2 = %.4g (%.4g)\n",
                   ivec, xmag, src_mag, fabs(xmag - src_mag));
    }
#endif

#ifdef DEBUG_CHECK
    // Check that src is being copied appropriately
    node0_printf("eigVec[0] copy check:\n");
    dump_TF(&(src[0]));
#endif

    hdelta0_field(src, res);    // D^2 + fmass^2

    // Copy the resulting Twist_Fermion res back to complex vector y
    // Each Twist_Fermion has Ndat=16DIMF non-trivial complex components
    xx = ((Complex_Z*) y) + Ndat * ivec * sites_on_node;   // This vector in y
    iter = 0;
    for (i = 0; i < sites_on_node; i++) {
      for (j = 0; j < DIMF; j++) {
        xx[iter].r = (double)res[i].Fsite.c[j].real;
        xx[iter].i = (double)res[i].Fsite.c[j].imag;
        iter++;
        for (mu = 0; mu < NUMLINK; mu++) {   // Do all links before any plaqs
          xx[iter].r = (double)res[i].Flink[mu].c[j].real;
          xx[iter].i = (double)res[i].Flink[mu].c[j].imag;
          iter++;
          for (nu = mu + 1; nu < NUMLINK; nu++) {
            xx[iter].r = (double)res[i].Fplaq[mu][nu].c[j].real;
            xx[iter].i = (double)res[i].Fplaq[mu][nu].c[j].imag;
            iter++;
          }
        }
      }
    }

#ifdef DEBUG_CHECK
    if (iter != Ndat * sites_on_node)
      printf("av_ov: iter = %d after source\n", iter);

    // Check that res is the same magnitude as y[ivec]
    double ymag = 0.0, res_mag = 0.0;
    xx = ((Complex_Z*) y) + Ndat * ivec * sites_on_node;   // This vector in x
    for (i = 0; i < sites_on_node * Ndat; i++)
      ymag += xx[i].r * xx[i].r + xx[i].i * xx[i].i;
    FORALLSITES(i, s)
      res_mag += magsq_TF(&(res[i]));
    if (fabs(ymag - res_mag) > eig_tol * eig_tol) {
      node0_printf("av_ov: |y[%d]|^2 = %.4g but |res|^2 = %.4g (%.4g)\n",
                   ivec, ymag, res_mag, fabs(ymag - res_mag));
    }
#endif
  }
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Function par_GlobalSumDouble is set as primme.globalSumDouble
void par_GlobalSumDouble(void *sendBuf, void *recvBuf,
                         int *count, primme_params *primme) {

  int i;
  for (i = 0; i < *count; i++)
    *((double*)recvBuf + i) = *((double*)sendBuf + i);

  g_vecdoublesum((double*)recvBuf, *count);
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Function make_evs computes eigenvalues through PRIMME
// Prints them with a quick check of |D^dag D phi - lambda phi|^2
// If flag==1 we calculate the smallest eigenvalues
// If flag==-1 we calculate the largest eigenvalues
int make_evs(int Nvec, Twist_Fermion **eigVec, double *eigVal, int flag) {
  register site* s;
  int i, j, mu, nu, ivec, iter = 0, ret, Ndat = 16 * DIMF;
  int maxn = sites_on_node * Ndat;
  double check, *rnorms = malloc(Nvec * sizeof(*rnorms));
  Complex_Z *workVecs = malloc(Nvec * maxn * sizeof(*workVecs));;
  static primme_params primme;
  Twist_Fermion tTF, *tmpTF = malloc(sites_on_node * sizeof(*tmpTF));

  // Check memory allocations
  if (workVecs == NULL) {
    node0_printf("ERROR in make_evs: couldn't allocate workVecs\n");
    exit(1);
  }
  if (rnorms == NULL) {
    node0_printf("ERROR in make_evs: couldn't allocate rnorms\n");
    exit(1);
  }

  // Initialize all the eigenvectors to random vectors
  for (ivec = 0; ivec < Nvec; ivec++) {
    eigVal[ivec] = 1e16;
    rand_TFsource(eigVec[ivec]);
  }

  // Copy initial guesses into double-precision temporary fields
  // Each Twist_Fermion has Ndat = 16DIMF non-trivial complex components
  for (ivec = 0; ivec < Nvec; ivec++) {
    iter = Ndat * ivec * sites_on_node;   // This vector in workvecs
    for (i = 0; i < sites_on_node; i++) {
      for (j = 0; j < DIMF; j++) {
        workVecs[iter].r = eigVec[ivec][i].Fsite.c[j].real;
        workVecs[iter].i = eigVec[ivec][i].Fsite.c[j].imag;
        iter++;
        for (mu = 0; mu < NUMLINK; mu++) {
          workVecs[iter].r = eigVec[ivec][i].Flink[mu].c[j].real;
          workVecs[iter].i = eigVec[ivec][i].Flink[mu].c[j].imag;
          iter++;
          for (nu = mu + 1; nu < NUMLINK; nu++) {
            workVecs[iter].r = eigVec[ivec][i].Fplaq[mu][nu].c[j].real;
            workVecs[iter].i = eigVec[ivec][i].Fplaq[mu][nu].c[j].imag;
            iter++;
          }
        }
      }
    }
  }
#ifdef DEBUG_CHECK
  if (iter != Nvec * maxn)
    printf("make_evs: iter = %d after input\n", iter);
#endif

  // Set the parameters of the EV finder
  primme_initialize(&primme);
  primme.n = maxn * number_of_nodes;              // Global size of matrix
  primme.nLocal = maxn;                           // Local volume
  primme.maxOuterIterations = maxIter;
  primme.maxMatvecs = maxIter + 5;
  primme.numProcs = number_of_nodes;
  primme.procID = this_node;
  primme.globalSumDouble = par_GlobalSumDouble;   // Wrapped function
  primme.matrixMatvec = av_ov;                    // Mat-vec wrapper

  primme_set_method(DEFAULT_MIN_MATVECS, &primme);
  primme.printLevel = 1;
  primme.eps = eig_tol;                   // Maximum residual
  primme.numEvals = Nvec;
  primme.initSize = 0;                    // Number of initial guesses
  if (flag == 1)
    primme.target = primme_smallest;
  else if (flag == -1)
    primme.target = primme_largest;
  else {
    node0_printf("make_evs: Unrecognized flag %d\n", flag);
    terminate(1);
  }
//  primme_display_params(primme);

  // Call the actual EV finder and check return value
  ret = zprimme(eigVal, workVecs, rnorms, &primme);
  if (ret != 0) {
    node0_printf("PRIMME failed with return value %d\n", ret);
    terminate(1);
  }

  // Copy double-precision temporary fields back into output
  // Each Twist_Fermion has Ndat = 16DIMF non-trivial complex components
  for (ivec = 0; ivec < Nvec; ivec++) {
    iter = Ndat * ivec * sites_on_node;   // This vector in workvecs
    for (i = 0; i < sites_on_node; i++) {
      for (j = 0; j < DIMF; j++) {
        eigVec[ivec][i].Fsite.c[j].real = workVecs[iter].r;
        eigVec[ivec][i].Fsite.c[j].imag = workVecs[iter].i;
        iter++;
        for (mu = 0; mu < NUMLINK; mu++) {
          eigVec[ivec][i].Flink[mu].c[j].real = workVecs[iter].r;
          eigVec[ivec][i].Flink[mu].c[j].imag = workVecs[iter].i;
          iter++;

          eigVec[ivec][i].Fplaq[mu][mu].c[j] = cmplx(0.0, 0.0);
          for (nu = mu + 1; nu < NUMLINK; nu++) {
            eigVec[ivec][i].Fplaq[mu][nu].c[j].real = workVecs[iter].r;
            eigVec[ivec][i].Fplaq[mu][nu].c[j].imag = workVecs[iter].i;
            iter++;
            CNEGATE(eigVec[ivec][i].Fplaq[mu][nu].c[j],
                    eigVec[ivec][i].Fplaq[nu][mu].c[j]);
          }
        }
      }
    }
  }
#ifdef DEBUG_CHECK
  if (iter != Nvec * maxn)
    printf("make_evs: iter = %d after output\n", iter);
#endif

  // Print results and check |D^dag D phi - lambda phi|^2
  for (ivec = 0; ivec < Nvec; ivec++) {
    check = 0.0;
    hdelta0_field(eigVec[ivec], tmpTF);
    FORALLSITES(i, s) {
      // tTF = tmpTF - eigVal[ivec] * eigVec[ivec]
      scalar_mult_add_TF(&(tmpTF[i]), &(eigVec[ivec][i]),
                                      -1.0 * eigVal[ivec], &tTF);
      check += magsq_TF(&tTF);
    }
    g_doublesum(&check);    // Accumulate across all nodes
    if (flag == 1)  {       // Braces suppress compiler warning
      node0_printf("EIGENVALUE %d %.8g %.8g\n", ivec, eigVal[ivec], check);
    }
    else if (flag == -1)
      node0_printf("BIGEIGVAL  %d %.8g %.8g\n", ivec, eigVal[ivec], check);
  }
  fflush(stdout);

  // Clean up
  free(workVecs);
  free(rnorms);
  primme_Free(&primme);
  return primme.stats.numOuterIterations;
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Check matrix elements and eigenvalues of <psi_j | D | psi_i>
// where the psi are eigenvectors of DDag.D
// Have checked that <psi_j | Ddag | psi_i> produces conjugate eigenvalues
void check_Dmat(int Nvec, Twist_Fermion **eigVec) {
  register int i;
  register site *s;
  char N = 'N';
  int ivec, jvec, stat = 0, unit = 1, doub = 2 * Nvec;
  double *store, *work, *eigs, *dum;
  double_complex tc, check;
  Twist_Fermion *tmpTF = malloc(sites_on_node * sizeof(*tmpTF));

  // Allocate double arrays expected by LAPACK
  store = malloc(2 * Nvec * Nvec * sizeof(*store));
  work = malloc(4 * Nvec * sizeof(*work));
  eigs = malloc(2 * Nvec * sizeof(*eigs));
  dum = malloc(2 * sizeof(*dum));

  // Hit each eigVec with D, then contract with every other eigVec
  for (ivec = 0; ivec < Nvec; ivec++) {
    fermion_op(eigVec[ivec], tmpTF, PLUS);

    for (jvec = 0; jvec < Nvec; jvec++) {
      check = cmplx(0.0, 0.0);
      FORALLSITES(i, s) {
        tc = TF_dot(&(eigVec[jvec][i]), &(tmpTF[i]));
        CSUM(check, tc);
      }
      g_dcomplexsum(&check);    // Accumulate across all nodes
//      node0_printf("D[%d, %d] (%.8g, %.4g)\n",
//                   ivec, jvec, check.real, check.imag);

      // Save in column-major double array expected by LAPACK
      store[2 * (jvec + Nvec * ivec)] = check.real;
      store[2 * (jvec + Nvec * ivec) + 1] = check.imag;
    }
  }
  free(tmpTF);

  // Diagonalize <psi|D|psi> using LAPACK
  // Arguments summarized in susy_includes.h
  node0_printf("Using LAPACK to diagonalize <psi_j | D | psi_i>\n");
  zgeev_(&N, &N, &Nvec, store, &Nvec, eigs,
         dum, &unit, dum, &unit, work, &doub, work, &stat);

  // Print resulting eigenvalues
  for (ivec = 0; ivec < Nvec; ivec++)
    node0_printf("D_eig %d (%.6g, %.6g)\n",
                 ivec, eigs[2 * ivec], eigs[2 * ivec + 1]);

  // Free double arrays expected by LAPACK
  free(store);
  free(work);
  free(eigs);
  free(dum);
}
// -----------------------------------------------------------------