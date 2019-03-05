// Tensor Pomeron amplitudes
//
// (c) 2017-2019 Mikael Mieskolainen
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.

#ifndef MTENSORPOMERON_H
#define MTENSORPOMERON_H

// C++
#include <complex>
#include <random>
#include <vector>

// Tensor algebra
#include "FTensor.hpp"

// Own
#include "Graniitti/MKinematics.h"
#include "Graniitti/M4Vec.h"
#include "Graniitti/MDirac.h"
#include "Graniitti/MMath.h"


namespace gra {


// Matrix element dimension: " GeV^" << -(2*external_legs - 8)
class MTensorPomeron : public MDirac {

public:
	
	MTensorPomeron() {
		CalcRTensor(); // Pre-Calculate
	}
	~MTensorPomeron() {}

	std::complex<double> ME4(gra::LORENTZSCALAR& lts) const;

	// Spin state collectors
	std::array<std::vector<std::complex<double>>, 2> 	   SpinorStates(const M4Vec& p, std::string type) const;
	std::array<FTensor::Tensor1<std::complex<double>,4>, 3> Spin1States(const M4Vec& p, std::string type) const;


	// Vertex functions
	FTensor::Tensor2<std::complex<double>,4,4>     iG_PppHE(const M4Vec& prime, const M4Vec p) const;

	FTensor::Tensor1<std::complex<double>,4>       iG_yee(const M4Vec& prime, const M4Vec& p,
		const std::vector<std::complex<double>>& ubar, const std::vector<std::complex<double>>& u) const;

	FTensor::Tensor1<std::complex<double>,4>       iG_ypp(const M4Vec& prime, const M4Vec& p, 
		const std::vector<std::complex<double>>& ubar, const std::vector<std::complex<double>>& u) const;
	
	FTensor::Tensor2<std::complex<double>,4,4>     iG_Ppp(const M4Vec& prime, const M4Vec& p, 
		const std::vector<std::complex<double>>& ubar, const std::vector<std::complex<double>>& u) const;

	FTensor::Tensor4<std::complex<double>,4,4,4,4> iG_PppbarP(const M4Vec& prime, 
		const std::vector<std::complex<double>>& ubar, const M4Vec& pt, const MMatrix<std::complex<double>>& iSF,
		const std::vector<std::complex<double>>& v, const M4Vec& p) const;
	
	FTensor::Tensor2<std::complex<double>,4,4>     iG_Ppsps(const M4Vec& prime, const M4Vec& p) const;
	FTensor::Tensor4<std::complex<double>,4,4,4,4> iG_Pvv(const M4Vec& prime, const M4Vec& p) const;

	FTensor::Tensor1<std::complex<double>,4>       iG_rhopipi(const M4Vec& k1, const M4Vec& k2) const;
	FTensor::Tensor2<std::complex<double>,4,4>     iG_f2pipi(const M4Vec& k1, const M4Vec& k2) const;
	FTensor::Tensor4<std::complex<double>,4,4,4,4> iG_f2yy(const M4Vec& k1, const M4Vec& k2) const;
	FTensor::Tensor2<std::complex<double>,4,4>     yV(std::string type) const;


	// Propagators
	FTensor::Tensor4<std::complex<double>,4,4,4,4> iD_P(double s, double t) const;
	FTensor::Tensor4<std::complex<double>,4,4,4,4> iD_2R(double s, double t) const;
	FTensor::Tensor2<std::complex<double>,4,4>     iD_O(double s, double t) const;
	FTensor::Tensor2<std::complex<double>,4,4>     iD_1R(double s, double t) const;

	std::complex<double>                  		   iD_MES0(const M4Vec& p, double M0) const;
	std::complex<double>                  		   iD_MES(const M4Vec& p, double M0, double Gamma) const;
	FTensor::Tensor2<std::complex<double>,4,4>     iD_VMES(const M4Vec& p, double M0, double Gamma) const;
	FTensor::Tensor4<std::complex<double>,4,4,4,4> iD_TMES(const M4Vec& p, double M0, double Gamma) const;


	// Tensor functions
	FTensor::Tensor4<std::complex<double>,4,4,4,4> Gamma0(const M4Vec& k1, const M4Vec& k2) const;
	FTensor::Tensor4<std::complex<double>,4,4,4,4> Gamma2(const M4Vec& k1, const M4Vec& k2) const;
	void CalcRTensor();

	// Trajectories
	double  alpha_P(double t) const;
	double  alpha_O(double t) const;
	double alpha_1R(double t) const;
	double alpha_2R(double t) const;

	// Form factors
	double F1(double t) const;
	double F2(double t) const;
	double GD(double t) const;
	double FM(double t) const;
	
	
	// Trajectory parameters
	static constexpr double delta_P  =  0.0808;
	static constexpr double delta_O  =  0.0808;
	static constexpr double delta_1R = -0.5475;
	static constexpr double delta_2R = -0.5475;
	
	static constexpr double ap_P     = 0.25;   // GeV^{-2}
	static constexpr double ap_O     = 0.25;   // GeV^{-2}
	static constexpr double ap_1R    = 0.9;    // GeV^{-2}
	static constexpr double ap_2R    = 0.9;	// GeV^{-2}
	
	static constexpr double eta_O    = 1.0;    // +- 1

	// Mass scales
	static constexpr double M_O      = 1.00;   // GeV
	static constexpr double M_1R     = 1.41;   // GeV
	static constexpr double mp       = 0.938;  // GeV
	static constexpr double mu_ratio = 2.7928; // mu_p / mu_N

	// Couplings
	static constexpr double betaPNN  = 1.87;   // GeV^{-1}
	
	// alpha_QED at q^2 ~ 0
	static constexpr double alpha_QED = 1.0 / 137.035999139;

private:

	FTensor::Tensor4<std::complex<double>,4,4,4,4> TR;

	// Nothing
};


} // gra namespace ends


#endif
