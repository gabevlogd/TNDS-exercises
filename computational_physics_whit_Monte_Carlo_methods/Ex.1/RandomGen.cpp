#include "RandomGen.h"

RandomGen::RandomGen(const unsigned int& seed){
	m_seed = seed;
	m_a = 1664525;
	m_m = pow(2, 31);
	m_c = 1013904223;
}

double RandomGen::Rand(){
	m_seed = (m_a*m_seed+m_c)%m_m;
	return m_seed/double(m_m);
}

double RandomGen::Unif(double Xmin, double Xmax){
	return Xmin + Rand()*(Xmax-Xmin);
}

double RandomGen::Exp(double mean){
	return (-1./mean)*log(1.-Rand());
}

double RandomGen::Gauss(double mean, double sigma){
	return mean + sigma * sqrt(-2*log(1-Rand()))*cos(2*M_PI*Rand());
}

double RandomGen::GaussAR(double mean, double sigma){
	redo:
	double x = Unif(mean-3*sigma, mean+3*sigma);
	double y = Rand() * (1./(sigma*sigma*sqrt(2*M_PI))+0.1); //max{Gauss(x)}=1/[sigma*sqrt(2PI)];
	if ( y < exp( -pow(x-mean, 2) / ( 2*pow(sigma, 2) ) )/(sigma*sigma*sqrt(2*M_PI)) )
		return x;
	else goto redo; 
	}