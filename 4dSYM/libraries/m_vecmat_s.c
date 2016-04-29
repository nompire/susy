// -----------------------------------------------------------------
// Add result of irrep vector--matrix operation with no adjoints
// c <-- c + b * a
#include "../include/config.h"
#include "../include/complex.h"
#include "../include/su3.h"

void mult_su3_vec_mat_sum(su3_vector *b, su3_matrix *a, su3_vector *c) {
  register int i, j;
  register complex y;
  for (i = 0; i < DIMF; i++) {
    for (j = 0; j < DIMF; j++) {
      CMUL(a->e[j][i], b->c[j], y);
      CSUM(c->c[i], y);
    }
  }
}
// -----------------------------------------------------------------