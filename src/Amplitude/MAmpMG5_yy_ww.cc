//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph5_aMC@NLO v. 3.0.0, 2018-05-01
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================
// Modified from the MadGraph C++ Standalone output
// Mikael Mieskolainen, 2018

#include <cmath>
#include <complex>
#include <vector>

// Own
#include "Graniitti/Amplitude/HelAmps_sm_yy_ww.h"
#include "Graniitti/Amplitude/MAmpMG5_yy_ww.h"
#include "Graniitti/Amplitude/Parameters_sm.h"

#include "Graniitti/MAux.h"
#include "Graniitti/MForm.h"
#include "Graniitti/MKinematics.h"
#include "Graniitti/MMath.h"

MAmpMG5_yy_ww::MAmpMG5_yy_ww() {
  std::string param_card_name = gra::aux::GetBasePath(2) + "/MG5cards/" + "yy_ww_param_card.dat";

  // Instantiate the model class and set parameters that stay fixed
  // during run
  pars = Parameters_sm();
  SLHAReader slha(param_card_name);
  pars.setIndependentParameters(slha);
  pars.setIndependentCouplings();

  // pars.printIndependentParameters();
  // pars.printIndependentCouplings();

  // Set external particle masses for this matrix element
  mME.push_back(pars.ZERO);
  mME.push_back(pars.ZERO);
  mME.push_back(pars.ZERO);
  mME.push_back(pars.ZERO);

  jamp2 = std::vector<std::vector<double>>(nprocesses, std::vector<double>(1));
}

MAmpMG5_yy_ww::~MAmpMG5_yy_ww() {
}


// Get amplitude squared
double MAmpMG5_yy_ww::CalcAmp2(gra::LORENTZSCALAR &lts) {
  const double mgamma1 = 0;  // on-shell
  const double mgamma2 = 0;

  // *** Set masses for HELAS ***
  const std::vector<double> masses = {mgamma1, mgamma2, lts.decaytree[0].p4.M(),
                                      lts.decaytree[1].p4.M()};
  mME = masses;
  
  // *** Set particle 4-momentum: [E,px,py,pz] convention here! ***
  gra::M4Vec p1_ = lts.q1;
  gra::M4Vec p2_ = lts.q2;
  std::vector<gra::M4Vec> pf = {lts.decaytree[0].p4, lts.decaytree[1].p4};
  
  // Do kinematic transform
  gra::kinematics::OffShell2LightCone(p1_, p2_, pf);
  
  // Set components
  double p1[] = {p1_.E(), p1_.Px(), p1_.Py(), p1_.Pz()};
  double p2[] = {p2_.E(), p2_.Px(), p2_.Py(), p2_.Pz()};
  double p3[] = {pf[0].E(), pf[0].Px(), pf[0].Py(), pf[0].Pz()};
  double p4[] = {pf[1].E(), pf[1].Px(), pf[1].Py(), pf[1].Pz()};

  p.clear();
  p.push_back(&p1[0]);
  p.push_back(&p2[0]);
  p.push_back(&p3[0]);
  p.push_back(&p4[0]);
  // --------------------------------------------------------------------

  // Helicity combinations
  static const int ncomb = 36;
  lts.hamp               = std::vector<std::complex<double>>(ncomb);

  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {
      {-1, -1, -1, -1}, {-1, -1, -1, 0}, {-1, -1, -1, 1}, {-1, -1, 0, -1}, {-1, -1, 0, 0},
      {-1, -1, 0, 1},   {-1, -1, 1, -1}, {-1, -1, 1, 0},  {-1, -1, 1, 1},  {-1, 1, -1, -1},
      {-1, 1, -1, 0},   {-1, 1, -1, 1},  {-1, 1, 0, -1},  {-1, 1, 0, 0},   {-1, 1, 0, 1},
      {-1, 1, 1, -1},   {-1, 1, 1, 0},   {-1, 1, 1, 1},   {1, -1, -1, -1}, {1, -1, -1, 0},
      {1, -1, -1, 1},   {1, -1, 0, -1},  {1, -1, 0, 0},   {1, -1, 0, 1},   {1, -1, 1, -1},
      {1, -1, 1, 0},    {1, -1, 1, 1},   {1, 1, -1, -1},  {1, 1, -1, 0},   {1, 1, -1, 1},
      {1, 1, 0, -1},    {1, 1, 0, 0},    {1, 1, 0, 1},    {1, 1, 1, -1},   {1, 1, 1, 0},
      {1, 1, 1, 1}};

  // Permutations
  int perm[nexternal];

  // Define permutation
  for (int i = 0; i < nexternal; ++i) { perm[i] = i; }

  // Loop over helicity combinations
  for (int ihel = 0; ihel < ncomb; ++ihel) {
    calculate_wavefunctions(perm, helicities[ihel]);

    // Sum of subamplitudes (s,t,u,...)
    for (int k = 0; k < namplitudes; ++k) { lts.hamp[ihel] += amp[k]; }
  }

  // Total amplitude squared over all helicity combinations individually
  double amp2 = 0.0;
  for (int ihel = 0; ihel < ncomb; ++ihel) { amp2 += gra::math::abs2(lts.hamp[ihel]); }
  amp2 /= 4.0;  // spin average matrix element squared

  return amp2;  // amplitude squared
}

// ------------------------------------------------------------------------------------------------
// From MadGraph automatic output

// MadGraph wavefunctions
void MAmpMG5_yy_ww::calculate_wavefunctions(const int perm[], const int hel[]) {
  // Calculate wavefunctions for all processes
  // int i, j;

  // Calculate all wavefunctions
  MG5_sm_yy_ww::vxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]);
  MG5_sm_yy_ww::vxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]);
  MG5_sm_yy_ww::vxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]);
  MG5_sm_yy_ww::vxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]);
  MG5_sm_yy_ww::VVV1_2(w[0], w[2], pars.GC_4, pars.mdl_MW, pars.mdl_WW, w[4]);
  MG5_sm_yy_ww::VVV1_3(w[0], w[3], pars.GC_4, pars.mdl_MW, pars.mdl_WW, w[5]);

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  MG5_sm_yy_ww::VVVV2_0(w[0], w[1], w[3], w[2], pars.GC_5, amp[0]);
  MG5_sm_yy_ww::VVV1_0(w[1], w[3], w[4], pars.GC_4, amp[1]);
  MG5_sm_yy_ww::VVV1_0(w[1], w[5], w[2], pars.GC_4, amp[2]);
}

// THIS IS NOT USED
double MAmpMG5_yy_ww::matrix_1_aa_wpwm() {
  int i, j;
  // Local variables
  // const int ngraphs = 3;
  const int            ncolor = 1;
  std::complex<double> ztemp;
  std::complex<double> jamp[ncolor];
  // The color matrix;
  static const double denom[ncolor]      = {1};
  static const double cf[ncolor][ncolor] = {{1}};

  // Calculate color flows
  jamp[0] = +amp[0] + amp[1] + amp[2];

  // Sum and square the color flows to get the matrix element
  double matrix = 0;
  for (i = 0; i < ncolor; i++) {
    ztemp = 0.;
    for (j = 0; j < ncolor; j++) ztemp = ztemp + cf[i][j] * jamp[j];
    matrix                             = matrix + real(ztemp * conj(jamp[i])) / denom[i];
  }

  // Store the leading color flows for choice of color
  for (i = 0; i < ncolor; i++) jamp2[0][i] += real(jamp[i] * conj(jamp[i]));

  return matrix;
}
