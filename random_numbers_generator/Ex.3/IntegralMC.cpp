#include "IntegralMC.h"
#include <iostream>


double IntegralMC::IntegralAVE(double min, double max, unsigned int N, FunzioneBase& f){

	if (max < min){
		double swap = max;
		max = min;
		min = swap;
	}

	double somma=0;
	for (int i=0; i<N; i++){
		somma += f.Eval(m_myrand->Unif(min, max));
	}

	return (max-min)*somma/double(N);
}


double IntegralMC::IntegralHoM(double min, double max, unsigned int Ntot, double fmax, FunzioneBase& f){

	if (max < min){
		double swap = max;
		max = min;
		min = swap;
	}

	unsigned int Nhit = 0;
	for (int i=0; i<Ntot; i++){
		if(m_myrand->Unif(0, fmax) < f.Eval(m_myrand->Unif(min, max))) Nhit++;		
	}

	return (max-min)*fmax*double(Nhit)/double(Ntot);
}