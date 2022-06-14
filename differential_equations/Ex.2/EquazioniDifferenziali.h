#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__

#include "VectorOperations.h"

using namespace std;

// ===============================================================
// Classe astratta, restituisce la derivata nel punto x al tempo t
// ===============================================================

class FunzioneVettorialeBase {

public:
  virtual vector<double> Eval(double t, const vector<double> & x) const = 0;
};

// ===============================================================
// Caso fisico concreto: oscillatore armonico; etc.etc.
// ===============================================================

class OscillatoreArmonico : public FunzioneVettorialeBase {

public:
  OscillatoreArmonico(double omega0) { m_omega0 = omega0; };
  vector<double> Eval(double t, const vector<double> &x) const override {
		vector<double> Result { x[1] , -pow(m_omega0,2)*x[0] };
	  return Result;
  }

private:
  double m_omega0;
};

// ===============================================================
// Classe astratta per un integratore di equazioni differenziali
// ===============================================================

class EquazioneDifferenzialeBase {
public:
  virtual vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase &f) const = 0;
};

// ===============================================================
// Integratore concreto, metodo di Eulero
// ===============================================================

class Eulero : public EquazioneDifferenzialeBase {
public:
  vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase &f) const override {
		vector<double> Result = x + h*f.Eval(t,x);
		return Result;	
  }
};

class RungeKutta : public EquazioneDifferenzialeBase {
public:
  vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase &f) const override {
		vector<double> k1 = f.Eval(t,x);
		vector<double> k2 = f.Eval(t+h*0.5, x+h*0.5*k1);
		vector<double> k3 = f.Eval(t+h*0.5, x+h*0.5*k2);
		vector<double> k4 = f.Eval(t+h, x+h*k3);
		vector<double> Result = x + h/6. * (k1+2.*k2+2.*k3+k4);
		return Result;	
  }
};

#endif // __EquazioniDifferenziali_h__