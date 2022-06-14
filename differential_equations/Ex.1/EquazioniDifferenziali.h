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

#endif // __EquazioniDifferenziali_h__
