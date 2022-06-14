#include "CampoVettoriale.h"

CampoVettoriale::CampoVettoriale(const CampoVettoriale& E){
	m_Fx = E.getFx();
	m_Fy = E.getFy();
	m_Fz = E.getFz();
}

CampoVettoriale::CampoVettoriale(const Posizione &P) : Posizione(P){
	m_Fx=0;
	m_Fy=0;
	m_Fz=0;
}

CampoVettoriale::CampoVettoriale(const Posizione &P, double Fx, double Fy, double Fz) : Posizione(P){
m_Fx=Fx;
m_Fy=Fy;
m_Fz=Fz;
}

CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz){
	m_x=x;
	m_y=y;
	m_z=z;
	m_Fx=Fx;
	m_Fy=Fy;
	m_Fz=Fz;
}

CampoVettoriale & CampoVettoriale::operator+=( const CampoVettoriale & E){
	return (*this)=(*this) + E;
}

CampoVettoriale CampoVettoriale::operator+( const CampoVettoriale & E) const{
	CampoVettoriale sum(E);
	sum.m_Fx += getFx();
	sum.m_Fy += getFy();
	sum.m_Fz += getFz();
	return sum;
}

double CampoVettoriale::Modulo(){
	return sqrt(pow(m_Fx,2)+pow(m_Fy,2)+pow(m_Fz,2));
}