#include "PuntoMateriale.h"

PuntoMateriale::PuntoMateriale(const Particella& Pa, const Posizione& Po) : Particella(Pa) , Posizione(Po){}

PuntoMateriale::PuntoMateriale(double massa, double carica, const Posizione& Po) : Posizione(Po){
	m_massa=massa;
	m_carica=carica;
}

PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z){
	m_massa=massa;
	m_carica=carica;
	m_x=x;
	m_y=y;
	m_z=z;
}

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& P)const{
	const double eps0 = 8.8541878E-12;
	double r=getDistance(P);
	double k=m_carica/(4*M_PI*eps0*pow(r,3));
	double Ex = k*(P.getX()-m_x);
	double Ey = k*(P.getY()-m_y);
	double Ez = k*(P.getZ()-m_z);
	return CampoVettoriale(P, Ex, Ey, Ez);
}

CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione& P)const{
	const double GR = 6.674E-11;
	double r=getDistance(P);
	double k=GR*m_carica/pow(r,3);
	double Gx = k*(P.getX()-m_x);
	double Gy = k*(P.getY()-m_y);
	double Gz = k*(P.getZ()-m_z);
	return CampoVettoriale(P, Gx, Gy, Gz);
}