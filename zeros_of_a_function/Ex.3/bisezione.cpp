#include "bisezione.h"

double Bisezione::CercaZeri (double xmin, double xmax, const FunzioneBase* f, double prec) {

	m_prec=prec;
	m_niterations=0;
	double xmedio = 0;

	//controlllo che xmin sia minore di xmax
	if(xmax<xmin){m_b=xmin; m_a=xmax;} 
	else {m_a=xmin; m_b=xmax;}

	//controllo che l'intervallo iniziale non sia più piccolo della precisione inserita
	if(m_b-m_a<=m_prec) { cout << "higher precision required" << endl; exit(-1); }

	//metodo della bisezione
	while(m_b-m_a>m_prec){
		xmedio = (m_a+m_b)*0.5;
		if(sign(f->Eval(m_a))*sign(f->Eval(xmedio))<=0) m_b=xmedio;
		else if(sign(f->Eval(m_b))*sign(f->Eval(xmedio))<=0) m_a=xmedio;
		else { cout << "there're no zeros in (" << m_a << ", " << m_b << ")" << endl; exit(-1); }

		m_niterations++;	
	if (m_nmax<m_niterations) { cout << "too many iterations" << endl; exit(-1); }
	}

	return xmedio;
}


double Bisezione::CercaZeri (double xmin, double xmax, const FunzioneBase& f, double prec)  {

	m_prec=prec;
	m_niterations=0;
	double xmedio = 0;

	//controlllo che xmin sia minore di xmax
	if(xmax<xmin){m_b=xmin; m_a=xmax;}
	else {m_a=xmin; m_b=xmax;}

	//controllo che l'intervallo iniziale non sia più piccolo della precisione inserita
	if(m_b-m_a<=m_prec) { cout << "higher precision required" << endl; exit(-1); }

	//metodo della bisezione
	while(m_b-m_a>m_prec){
		xmedio = (m_a+m_b)*0.5;
		if(sign(f.Eval(m_a))*sign(f.Eval(xmedio))<=0) m_b=xmedio;
		else if(sign(f.Eval(m_b))*sign(f.Eval(xmedio))<=0) m_a=xmedio;
		else { cout << "there're no zeros in (" << m_a << ", " << m_b << ")" << endl; exit(-1); }

		m_niterations++;	
		if (m_nmax<m_niterations) { cout << "too many iterations" << endl; exit(-1); }
	}

	return xmedio;
}