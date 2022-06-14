#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

#include <cmath>

class RandomGen{

  public:

  	RandomGen(const unsigned int&);

   	void SetA(unsigned int a) {m_a = a;}
   	void SetC(unsigned int c) {m_c = c;}
   	void SetM(unsigned int m) {m_m = m;}

   	double Rand();
   	double Unif(double xmin, double xmax);
   	double Exp(double mean);
   	double Gauss(double mean, double sigma);
   	double GaussAR(double mean, double sigma);

  private:
	
    unsigned int m_a, m_c, m_m;
    unsigned int m_seed;
};

#endif
