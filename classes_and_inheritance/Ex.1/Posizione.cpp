#include "Posizione.h"

Posizione::Posizione(){
		m_x=0;
		m_y=0;
		m_z=0;
}

Posizione::Posizione(double x, double y, double z){
	m_x=x;
	m_y=y;	
	m_z=z;
}

double Posizione::getX()const{ return m_x; }
double Posizione::getY()const{ return m_y; }
double Posizione::getZ()const{ return m_z; }

double Posizione::getR()const{
	return sqrt(pow(m_x,2)+pow(m_y,2)+pow(m_z,2));
}

double Posizione::getTheta()const{
	return acos(m_z/getR());
}

double Posizione::getPhi()const{
	if(m_x==0 && m_y>0) return M_PI/2.;
	else if (m_x==0 && m_y<0) return 3.*M_PI/2.;
	else if(m_x==0 && m_y==0) {
		std::cout << "Phi non definito(x=0, y=0)" << std::endl;
		exit(-1); }
	else if(m_x>0 && m_y>=0) return atan(m_y/m_x);
	else if(m_x>0 && m_y<0)  return atan(m_y/m_x)+M_PI*2.;
	else if(m_x<0 && m_y>0)  return atan(m_y/m_x)+M_PI*2.;
	else if(m_x<0 && m_y<=0)  return atan(m_y/m_x)+M_PI;
}

double Posizione::getRho()const{
	return sqrt(pow(m_x, 2)+pow(m_y,2)); }

double Posizione::getDistance (const Posizione& P)const{
	double norma=0;
	norma = sqrt(pow(m_x-P.getX(),2)+pow(m_y-P.getY(),2)+pow(m_z-P.getZ(),2));
	return norma;
}
	


