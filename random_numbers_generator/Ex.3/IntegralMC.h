#ifndef __INTEGRALMC_H__
#define __INTEGRALMC_H__

#include "FunzioneBase.h"
#include "RandomGen.h"

class IntegralMC {
	public:
	IntegralMC(unsigned int seed) { m_myrand = new RandomGen(seed); };
	IntegralMC(){;};

	double IntegralAVE(double min, double max, unsigned int N, FunzioneBase& f);
	double IntegralHoM(double min, double max, unsigned int N, double fmax, FunzioneBase& f );

	private:
	RandomGen * m_myrand;
};

#endif


