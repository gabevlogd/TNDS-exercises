#ifndef __Particella_h__
#define __Particella_h__

#include <iostream>

/***********************************************************
 * Classe astratta per una generica particella
 * definisce i metodi che ogni particella 
 * deve implementare e delle funzioni di utilizzo generale.
 ***********************************************************/

class Particella {

public:

  // costruttori
	Particella(const Particella& P){m_massa=P.getMassa(); m_carica=P.getCarica();}
	Particella(){m_carica=0; m_massa=0;};
	Particella(double m, double c){m_massa=m; m_carica=c;}     

  // distruttore
  ~Particella(){};

  // metodi
  double getMassa()const{ return m_massa;  };
	double getCarica()const{ return m_carica; };
	void print(){
		std::cout << "carica: "<< m_carica << " massa: " << m_massa << std::endl;}

protected:

	double m_massa, m_carica;


};

/*********************************************************
 * Implementazione concreta di una particella elementare
 * in questo caso tutte le proprietà della particella 
 * sono costanti, definite nel costruttore di default.
 ***********************************************************/

class Elettrone : public Particella {

public:

  Elettrone() : Particella(9.1093826E-31, -1.60217653E-19){};
	~Elettrone(){};

	void prin(){
		std::cout << "elettrone: massa=" << getMassa() << " carica=" << getCarica() << std::endl;
	}
};

#endif // __Particella_h__
