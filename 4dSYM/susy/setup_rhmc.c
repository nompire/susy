// -----------------------------------------------------------------
// Coefficients for (Mdag M)^(-1 / 4) and (Mdag M)^(1 / 8)
// Note the relative sign between fractional powers!
// For now simply copy in remez-milc output, switch using DEGREE
#include "susy_includes.h"
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Original (15, 15) approximation for spectral range [1e-7, 1000]
// gives errors 1.975834e-05 and 1.066076e-05
void setup_rhmc15() {
#if (DEGREE==15)
  // awk '/res_MD/{print("amp4["$2"] =",$3";")}' < out.00000001-1000
  ampdeg4 = 9.5797060554725838e-02;
  amp4[0] = 1.7701746700099842e-06;
  amp4[1] = 5.8705983656937455e-06;
  amp4[2] = 1.9961158693570120e-05;
  amp4[3] = 6.9125367600088173e-05;
  amp4[4] = 2.4032965323696816e-04;
  amp4[5] = 8.3620125835371663e-04;
  amp4[6] = 2.9099006745502945e-03;
  amp4[7] = 1.0126504714418652e-02;
  amp4[8] = 3.5241454044660878e-02;
  amp4[9] = 1.2266034741624667e-01;
  amp4[10] = 4.2721681852328125e-01;
  amp4[11] = 1.4932820692676758e+00;
  amp4[12] = 5.3188766358452595e+00;
  amp4[13] = 2.0944763089672641e+01;
  amp4[14] = 1.4525770103354523e+02;

  // awk '/pole_MD/{print("shift4["$2"] =",$3";")}' < out.00000001-1000
  shift4[0] = 3.1085594175442315e-08;
  shift4[1] = 3.2994455960441383e-07;
  shift4[2] = 1.9424842756552213e-06;
  shift4[3] = 1.0453359626231250e-05;
  shift4[4] = 5.5337819905761986e-05;
  shift4[5] = 2.9204178440857227e-04;
  shift4[6] = 1.5403300046437174e-03;
  shift4[7] = 8.1233558140562465e-03;
  shift4[8] = 4.2840454273820550e-02;
  shift4[9] = 2.2594500626442715e-01;
  shift4[10] = 1.1921171782283737e+00;
  shift4[11] = 6.3026182343759860e+00;
  shift4[12] = 3.3683411978650057e+01;
  shift4[13] = 1.9083658214156412e+02;
  shift4[14] = 1.5386784635765257e+03;

  // awk '/res_GR/{print("amp8["$2"] =",$3";")}' < out.00000001-1000
  ampdeg8 = 3.2148873149863206e+00;
  amp8[0] = -2.2977600408751347e-09;
  amp8[1] = -1.6898103706901084e-08;
  amp8[2] = -1.1099658368596436e-07;
  amp8[3] = -7.2162146587729939e-07;
  amp8[4] = -4.6841070484595924e-06;
  amp8[5] = -3.0396303865820389e-05;
  amp8[6] = -1.9723870959636086e-04;
  amp8[7] = -1.2798599250624023e-03;
  amp8[8] = -8.3051856063983548e-03;
  amp8[9] = -5.3904877281192094e-02;
  amp8[10] = -3.5026088217184553e-01;
  amp8[11] = -2.2893521967679966e+00;
  amp8[12] = -1.5436668340425719e+01;
  amp8[13] = -1.2297861076048798e+02;
  amp8[14] = -2.6252652966414048e+03;

  // awk '/pole_GR/{print("shift8["$2"] =",$3";")}' < out.00000001-1000
  shift8[0] = 5.5367335615411457e-08;
  shift8[1] = 4.6910257304582898e-07;
  shift8[2] = 2.6768223190551614e-06;
  shift8[3] = 1.4319657256375662e-05;
  shift8[4] = 7.5694473187855338e-05;
  shift8[5] = 3.9922490005559548e-04;
  shift8[6] = 2.1046795395127538e-03;
  shift8[7] = 1.1094832053548640e-02;
  shift8[8] = 5.8486687698920667e-02;
  shift8[9] = 3.0834388405073770e-01;
  shift8[10] = 1.6264534005778293e+00;
  shift8[11] = 8.6030459456576764e+00;
  shift8[12] = 4.6179583183155444e+01;
  shift8[13] = 2.6854965277696181e+02;
  shift8[14] = 2.6004158696112045e+03;
#endif
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// (11, 11) approximation for spectral range [0.00001, 50]
// gives errors 1.064032e-05 and 5.735037e-06
void setup_rhmc11() {
#if (DEGREE==11)
  // awk '/res_MD/{print("amp4["$2"] =",$3";")}' < out.000001-50
  ampdeg4 = 1.9748180236103505e-01;
  amp4[0] = 5.1088365802723218e-05;
  amp4[1] = 1.6003338487834137e-04;
  amp4[2] = 5.1036966915755293e-04;
  amp4[3] = 1.6597921340084090e-03;
  amp4[4] = 5.4234722425496587e-03;
  amp4[5] = 1.7742709041750043e-02;
  amp4[6] = 5.8113137000818688e-02;
  amp4[7] = 1.9124921824328966e-01;
  amp4[8] = 6.4404937803804974e-01;
  amp4[9] = 2.4284312000973571e+00;
  amp4[10] = 1.6558885067283203e+01;

  // awk '/pole_MD/{print("shift4["$2"] =",$3";")}' < out.000001-50
  shift4[0] = 2.7818179678949325e-06;
  shift4[1] = 2.8238764993579120e-05;
  shift4[2] = 1.5531382235812910e-04;
  shift4[3] = 7.7317635540915576e-04;
  shift4[4] = 3.7741083934698738e-03;
  shift4[5] = 1.8350836737594658e-02;
  shift4[6] = 8.9203180943308050e-02;
  shift4[7] = 4.3471535522870142e-01;
  shift4[8] = 2.1465885440424688e+00;
  shift4[9] = 1.1322523014309711e+01;
  shift4[10] = 8.6660800228024399e+01;

  // awk '/res_GR/{print("amp8["$2"] =",$3";")}' < out.000001-50
  ampdeg8 = 2.2391954658813749e+00;
  amp8[0] = -3.5363622101017518e-07;
  amp8[1] = -2.4024443111274285e-06;
  amp8[2] = -1.4414646320691006e-05;
  amp8[3] = -8.5452752390562025e-05;
  amp8[4] = -5.0563198975080701e-04;
  amp8[5] = -2.9917201595653243e-03;
  amp8[6] = -1.7728072906135327e-02;
  amp8[7] = -1.0586065354081924e-01;
  amp8[8] = -6.5625958559320219e-01;
  amp8[9] = -4.8970608140017928e+00;
  amp8[10] = -1.0154172043999166e+02;

  // awk '/pole_GR/{print("shift8["$2"] =",$3";")}' < out.000001-50
  shift8[0] = 4.9243473302622236e-06;
  shift8[1] = 3.9671800968449227e-05;
  shift8[2] = 2.1090234404452169e-04;
  shift8[3] = 1.0426007462641042e-03;
  shift8[4] = 5.0800004851836514e-03;
  shift8[5] = 2.4682287075428813e-02;
  shift8[6] = 1.1994027687958879e-01;
  shift8[7] = 5.8487501074377135e-01;
  shift8[8] = 2.9029811669526673e+00;
  shift8[9] = 1.5754881262197461e+01;
  shift8[10] = 1.4560448531198813e+02;
#endif
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// (9, 9) approximation for spectral range [0.0001, 45]
// gives errors 1.928152e-05 and 1.038366e-05
void setup_rhmc9() {
#if (DEGREE==9)
  // awk '/res_MD/{print("amp4["$2"] =",$3";")}' < out.00001-45
  ampdeg4 = 2.0777859903387064e-01;
  amp4[0] = 3.1361646774095720e-04;
  amp4[1] = 1.0376047912755866e-03;
  amp4[2] = 3.5188116165401893e-03;
  amp4[3] = 1.2155937785551100e-02;
  amp4[4] = 4.2190013023882304e-02;
  amp4[5] = 1.4707389241596666e-01;
  amp4[6] = 5.2261160990536404e-01;
  amp4[7] = 2.0541440716938171e+00;
  amp4[8] = 1.4235435645059507e+01;

  // awk '/pole_MD/{print("shift4["$2"] =",$3";")}' < out.00001-45
  shift4[0] = 3.0945740855689258e-05;
  shift4[1] = 3.2784330944557943e-04;
  shift4[2] = 1.9246508827843313e-03;
  shift4[3] = 1.0324786841812992e-02;
  shift4[4] = 5.4499729309375029e-02;
  shift4[5] = 2.8737303500233369e-01;
  shift4[6] = 1.5309893112867550e+00;
  shift4[7] = 8.6482893683193165e+00;
  shift4[8] = 6.9576998834492443e+01;

  // awk '/res_GR/{print("amp8["$2"] =",$3";")}' < out.00001-45
  ampdeg8 = 2.1830271620728054e+00;
  amp8[0] = -5.4143795366382000e-06;
  amp8[1] = -3.9676818015731586e-05;
  amp8[2] = -2.5958109726990279e-04;
  amp8[3] = -1.6811247632604292e-03;
  amp8[4] = -1.0882543862047362e-02;
  amp8[5] = -7.0847423319728930e-02;
  amp8[6] = -4.7591272677901392e-01;
  amp8[7] = -3.7801496263213803e+00;
  amp8[8] = -8.0587284363165352e+01;

  // awk '/pole_GR/{print("shift8["$2"] =",$3";")}' < out.00001-45
  shift8[0] = 5.5083850325016191e-05;
  shift8[1] = 4.6563686474799176e-04;
  shift8[2] = 2.6486486150264711e-03;
  shift8[3] = 1.4120708057479768e-02;
  shift8[4] = 7.4420558484424110e-02;
  shift8[5] = 3.9242609363745878e-01;
  shift8[6] = 2.0993041046459315e+00;
  shift8[7] = 1.2170425789307121e+01;
  shift8[8] = 1.1759944538524526e+02;
#endif
}
// -----------------------------------------------------------------




// -----------------------------------------------------------------
// (8, 8) approximation for spectral range [0.001, 50]
// gives errors 1.205192e-05 and 6.486560e-06
void setup_rhmc8() {
#if (DEGREE==8)
  // awk '/res_MD/{print("amp4["$2"] =",$3";")}' < out.0001-50
  ampdeg4 = 1.9847855485120461e-01;
  amp4[0] = 1.6447767692749293e-03;
  amp4[1] = 5.2091545016137450e-03;
  amp4[2] = 1.6823654204678816e-02;
  amp4[3] = 5.5444365469241169e-02;
  amp4[4] = 1.8437888053401108e-01;
  amp4[5] = 6.2746826716341830e-01;
  amp4[6] = 2.3852840251249825e+00;
  amp4[7] = 1.6315143889652543e+01;

  // awk '/pole_MD/{print("shift4["$2"] =",$3";")}' < out.0001-50
  shift4[0] = 2.8432460169357867e-04;
  shift4[1] = 2.9108780584128227e-03;
  shift4[2] = 1.6221830544213445e-02;
  shift4[3] = 8.2026799734265451e-02;
  shift4[4] = 4.0801052401031673e-01;
  shift4[5] = 2.0476062496901357e+00;
  shift4[6] = 1.0951562209548896e+01;
  shift4[7] = 8.4659732253886020e+01;

  // awk '/res_GR/{print("amp8["$2"] =",$3";")}' < out.0001-50
  ampdeg8 = 2.2336270511419518e+00;
  amp8[0] = -6.4667060419709420e-05;
  amp8[1] = -4.4599197309502802e-04;
  amp8[2] = -2.7234661408815967e-03;
  amp8[3] = -1.6461958362314753e-02;
  amp8[4] = -1.0004750758332101e-01;
  amp8[5] = -6.3021119918448276e-01;
  amp8[6] = -4.7606598099602264e+00;
  amp8[7] = -9.9243921490085825e+01;

  // awk '/pole_GR/{print("shift8["$2"] =",$3";")}' < out.0001-50
  shift8[0] = 5.0374382496533006e-04;
  shift8[1] = 4.0970063350602185e-03;
  shift8[2] = 2.2077737619020866e-02;
  shift8[3] = 1.1088619746225478e-01;
  shift8[4] = 5.5108791671543900e-01;
  shift8[5] = 2.7782277485822364e+00;
  shift8[6] = 1.5278036140176734e+01;
  shift8[7] = 1.4244275240229373e+02;
#endif
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// (7, 7) approximation for spectral range [0.01, 100]
// gives errors 1.188882e-05 and 6.394091e-06
void setup_rhmc7() {
#if (DEGREE==7)
  // awk '/res_MD/{print("amp4["$2"] =",$3";")}' < out.001-100
  ampdeg4 = 1.6680930159627730e-01;
  amp4[0] = 9.2315042547519051e-03;
  amp4[1] = 2.9206939207961472e-02;
  amp4[2] = 9.4285084559539406e-02;
  amp4[3] = 3.1171511747749442e-01;
  amp4[4] = 1.0585431386617659e+00;
  amp4[5] = 4.0195484710232714e+00;
  amp4[6] = 2.7482766324809404e+01;

  // awk '/pole_MD/{print("shift4["$2"] =",$3";")}' < out.001-100
  shift4[0] = 2.8365741993749403e-03;
  shift4[1] = 2.9016226289869523e-02;
  shift4[2] = 1.6155431595051262e-01;
  shift4[3] = 8.1766730726365711e-01;
  shift4[4] = 4.1123714170984407e+00;
  shift4[5] = 2.1978736524783130e+01;
  shift4[6] = 1.6974419572848183e+02;

  // awk '/res_GR/{print("amp8["$2"] =",$3";")}' < out.001-100
  ampdeg8 = 2.4364856187355568e+00;
  amp8[0] = -8.5960572037391606e-04;
  amp8[1] = -5.9197826428335331e-03;
  amp8[2] = -3.6130161833894163e-02;
  amp8[3] = -2.1954889107383632e-01;
  amp8[4] = -1.3808750834267134e+00;
  amp8[5] = -1.0416917545008650e+01;
  amp8[6] = -2.1702341293846166e+02;

  // awk '/pole_GR/{print("shift8["$2"] =",$3";")}' < out.001-100
  shift8[0] = 5.0243523780111191e-03;
  shift8[1] = 4.0823798913732195e-02;
  shift8[2] = 2.1979722304082525e-01;
  shift8[3] = 1.1058245673439986e+00;
  shift8[4] = 5.5809450762563433e+00;
  shift8[5] = 3.0661264352234980e+01;
  shift8[6] = 2.8560387942222809e+02;
#endif
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// (6, 6) approximation for spectral range [0.02, 50]
// gives errors 1.515132e-05 and 8.140949e-06
void setup_rhmc6() {
#if (DEGREE==6)
  // awk '/res_MD/{print("amp4["$2"] =",$3";")}' < out.002-50
  ampdeg4 = 2.0035838418319055e-01;
  amp4[0] = 1.6089619700034339e-02;
  amp4[1] = 5.2075939216247140e-02;
  amp4[2] = 1.7299810700423821e-01;
  amp4[3] = 5.9783724002907257e-01;
  amp4[4] = 2.3063654482894740e+00;
  amp4[5] = 1.5868596323671357e+01;

  // awk '/pole_MD/{print("shift4["$2"] =",$3";")}' < out.002-50
  shift4[0] = 5.9246187607994976e-03;
  shift4[1] = 6.1679058754489605e-02;
  shift4[2] = 3.5332103905499312e-01;
  shift4[3] = 1.8640825764563929e+00;
  shift4[4] = 1.0275478485280116e+01;
  shift4[5] = 8.1016349994659194e+01;

  // awk '/res_GR/{print("amp8["$2"] =",$3";")}' < out.002-50
  ampdeg8 = 2.2231956780463324e+00;
  amp8[0] = -1.9829856353425174e-03;
  amp8[1] = -1.4094809881415832e-02;
  amp8[2] = -8.9639421822227741e-02;
  amp8[3] = -5.8322796414232880e-01;
  amp8[4] = -4.5123946696300674e+00;
  amp8[5] = -9.5059971756102911e+01;

  // awk '/pole_GR/{print("shift8["$2"] =",$3";")}' < out.002-50
  shift8[0] = 1.0516496796568211e-02;
  shift8[1] = 8.7160697505863152e-02;
  shift8[2] = 4.8363725652222034e-01;
  shift8[3] = 2.5473481002404794e+00;
  shift8[4] = 1.4405517772037626e+01;
  shift8[5] = 1.3666238033906589e+02;
#endif
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// (5, 5) approximation for spectral range [0.1, 50]
// gives errors 1.548364e-05 and 8.308677e-06
void setup_rhmc5() {
#if (DEGREE==5)
  // awk '/res_MD/{print("amp4["$2"] =",$3";")}' < out.01-50
  ampdeg4 = 2.0057814828187764e-01;
  amp4[0] = 5.4026803430958975e-02;
  amp4[1] = 1.7590005470348138e-01;
  amp4[2] = 5.9772503229277774e-01;
  amp4[3] = 2.2997285767889570e+00;
  amp4[4] = 1.5819178342283395e+01;

  // awk '/pole_MD/{print("shift4["$2"] =",$3";")}' < out.01-50
  shift4[0] = 2.9769772029903337e-02;
  shift4[1] = 3.1110339537434900e-01;
  shift4[2] = 1.8074132732436818e+00;
  shift4[3] = 1.0165968473383909e+01;
  shift4[4] = 8.0573715946619146e+01;

  // awk '/res_GR/{print("amp8["$2"] =",$3";")}' < out.01-50
  ampdeg8 = 2.2220375827770185e+00;
  amp8[0] = -1.2204111391487278e-02;
  amp8[1] = -8.7538464213535880e-02;
  amp8[2] = -5.7743852008615837e-01;
  amp8[3] = -4.4849784135647406e+00;
  amp8[4] = -9.4603555440254667e+01;

  // awk '/pole_GR/{print("shift8["$2"] =",$3";")}' < out.01-50
  shift8[0] = 5.2850306687580832e-02;
  shift8[1] = 4.4009623019926597e-01;
  shift8[2] = 2.4868497380830941e+00;
  shift8[3] = 1.4278758280275570e+01;
  shift8[4] = 1.3600523930215593e+02;
#endif
}
// -----------------------------------------------------------------



// -----------------------------------------------------------------
// Switch between different sets of coefficients
// for (Mdag M)^(-1 / 4) and (Mdag M)^(1 / 8),
// For given spectral range, set DEGREE in defines.h
// as the smallest value that keeps remez errors < 2e-5
void setup_rhmc() {
  Norder = DEGREE;
  node0_printf("RHMC Norder %d for spectral range ", Norder);

  switch(Norder) {
    case 5:
      node0_printf("[0.1, 50]\n");
      setup_rhmc5();
      break;
    case 6:
      node0_printf("[0.02, 50]\n");
      setup_rhmc6();
      break;
    case 7:
      node0_printf("[0.01, 100]\n");
      setup_rhmc6();
      break;
    case 8:
      node0_printf("[0.001, 50]\n");
      setup_rhmc8();
      break;
    case 9:
      node0_printf("[0.0001, 45]\n");
      setup_rhmc9();
      break;
    case 11:
      node0_printf("[0.00001, 50]\n");
      setup_rhmc11();
      break;
    case 15:
      node0_printf("[0.0000001, 1000]\n");
      setup_rhmc15();
      break;
    default:
      node0_printf("setup_rhmc: unrecognized degree\n");
      terminate(1);
  }

  // Test by zeroing out all amp4 and amp8, optionally setting Norder to 1
//  int i;
//  Norder = 1;
//  for (i = 0; i < Norder; i++) {
//    amp4[i] = 0;
//    amp8[i] = 0;
//  }
//  node0_printf("TEST VERSION: internal Norder %d\n", Norder);
//  ampdeg4 = 0;
//  amp4[0] = 1;
//  shift4[0] = 1e-3;
//  ampdeg8 = 1;
//  amp8[0] = 0;
//  shift8[0] = 1;

#ifdef DEBUG_CHECK
  int i;
  node0_printf("RHMC ampdeg4 %e\n", ampdeg4);
  for (i = 0; i < Norder; i++)
    node0_printf("RHMC params %d amp4 %e shift4 %e\n", i, amp4[i], shift4[i]);

  node0_printf("RHMC ampdeg8 %e\n", ampdeg8);
  for (i = 0; i < Norder; i++)
    node0_printf("RHMC params %d amp8 %e shift8 %e\n", i, amp8[i], shift8[i]);
#endif
}
// -----------------------------------------------------------------
