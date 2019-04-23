//==========================================================================
// This file has been automatically generated for C++ Standalone
// MadGraph5_aMC@NLO v. 3.0.0, 2018-05-01
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef MAMPMG5_yy_ll_2to4_H
#define MAMPMG5_yy_ll_2to4_H

#include "Graniitti/Amplitude/Parameters_sm.h"
#include "Graniitti/MForm.h"

class MAmpMG5_yy_ll_2to4 {
  public:
	MAmpMG5_yy_ll_2to4();
	~MAmpMG5_yy_ll_2to4();
	std::complex<double> CalcAmp(gra::LORENTZSCALAR& lts);

  private:
	// Constants for array limits
	static const int ninitial = 2;
	static const int nexternal = 6;
	static const int nprocesses = 1;

	// Private functions to calculate the matrix element for all
	// subprocesses
	// Calculate wavefunctions
	void calculate_wavefunctions(const int perm[], const int hel[]);
	static const int nwavefuncs = 14;
	std::complex<double> w[nwavefuncs][18];
	static const int namplitudes = 4;
	std::complex<double> amp[namplitudes];
	double matrix_1();

	// Store the matrix element value from sigmaKin
	double matrix_element[nprocesses];

	// Color flows, used when selecting color
	double* jamp2[nprocesses];

	// Pointer to the model parameters
	Parameters_sm* pars;

	// vector with external particle masses
	vector<double> mME;

	// vector with momenta (to be changed each event)
	vector<double*> p;

	// Initial particle ids
	int id1, id2;
};

#endif