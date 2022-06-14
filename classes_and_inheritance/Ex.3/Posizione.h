#ifndef __Posizione_h__
#define __Posizione_h__

#include <iostream>
#include <cmath>


class Posizione {

public:

  // costruttori
  Posizione();
  Posizione(double x, double y, double z);
	Posizione(const Posizione &);

  // distruttore
  ~Posizione(){};

  // metodi
  double getX() const;       // Coordinate cartesiane
  double getY() const;
  double getZ() const;

  double getR() const;       // Coordinate sferiche
  double getPhi() const;
  double getTheta() const;

	double getRho()const;     // Coordinate cilindriche

  double getDistance(const Posizione&) const;

protected:

  double m_x, m_y, m_z;  

};

#endif // __Posizione_h__