#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__

#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"

class PuntoMateriale: public Particella, Posizione {

public:

	PuntoMateriale(const Particella&, const Posizione&);
  PuntoMateriale(double, double, const Posizione&);
	PuntoMateriale(double, double, double, double, double);
	~PuntoMateriale(){};

	CampoVettoriale CampoElettrico(const Posizione&)const;
	CampoVettoriale CampoGravitazionale(const Posizione&)const;

};

#endif // __PuntoMateriale_h__
