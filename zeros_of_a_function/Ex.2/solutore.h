#ifndef __solutore__
#define __solutore__

#include "funzioneBase.h"

class Solutore {

public:

  virtual double CercaZeri (double, double, const FunzioneBase*, double)=0;
  virtual double CercaZeri (double, double, const FunzioneBase&, double)=0;

  void SetPrecision (double epsilon) { m_prec=epsilon; }
	void SetNMaxiterations (unsigned int n) { m_nmax=n; }
	void SetNiterations (unsigned int n) { m_niterations=n; }
	
  double GetPrecisione () { return m_prec; }
  unsigned int GetNMaxiterations () {return m_nmax; }
  unsigned int GetNiterations () {return m_niterations; }

protected:
  double m_a, m_b;
  double m_prec;
  unsigned int m_nmax=1000, m_niterations;
};

#endif // __solutore__
