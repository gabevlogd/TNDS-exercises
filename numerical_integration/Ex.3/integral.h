#ifndef __Intergal_h__
#define __Intergal_h__

#include <algorithm>
#include <iostream>
#include "FunzioneBase.h"

using namespace std;


class Integral{

	public:

		Integral(double a, double b, const FunzioneBase* f){
			m_a=min(a,b);
			m_b=max(a,b);
			m_f=f;
			m_h=0.;
			m_sum=0.;
			m_integral=0.;

			if(a > b) m_sign=-1;
			else m_sign=1;
		}

		~Integral(){;};

		virtual double Integra(unsigned int) = 0;
		double getIntegral(){return m_integral;};
		double getH(){return m_h;};

	protected:

		double m_a, m_b, m_h, m_sum;
  		int m_sign;
  		double m_integral;
  		const FunzioneBase* m_f;

};


class MidPoint : public Integral {

	public:

	MidPoint(double a, double b, const FunzioneBase* f) : Integral(a, b, f) {;};

	double Integra(unsigned int N) override{
		m_h = (m_b - m_a)/double(N);

		for (int k=0; k<N; k++) m_sum += m_f->Eval(m_a + (k+0.5)*m_h);

		m_integral=m_sign*m_sum*m_h;
		m_sum=0.;
		return m_integral;
	}

};


class Simpson : public Integral {

	public:

	Simpson(double a, double b, const FunzioneBase* f) : Integral(a, b, f) {;};

	double Integra(unsigned int N) override{

		if (N%2!=0) N++;

		m_h = (m_b - m_a)/double(N);
		m_sum=0;

		for (unsigned int k=1; k<N; k++){

			if(k%2==0){ m_sum += 2*m_f->Eval(m_a + k*m_h); }

			else { m_sum += 4*m_f->Eval(m_a + k*m_h); }
		}

		m_integral = m_sign * m_h/3 * ( m_sum + m_f->Eval(m_a) + m_f->Eval(m_b) );
		return m_integral;
	}

};


class Trapezoidi : public Integral {

	public:

	Trapezoidi(double a, double b, const FunzioneBase* f) : Integral(a, b, f) {
		m_integral2N=0;
	};

	double Integra(unsigned int N) override{;}

	double Integra(double prec) {
	
		unsigned int j=1;
		m_N=pow(2, j);
		m_h = (m_b-m_a)/double(m_N);

		m_sum = ( m_f->Eval(m_a) + m_f->Eval(m_b) ) *0.5;  //step one
		m_integral = m_sum * (m_b-m_a);

		m_sum += m_f->Eval(m_a+m_h); //step two
		m_integral2N = m_sum * m_h;

		while(4./3. * fabs(m_integral-m_integral2N) > prec) {
			
			j++;
			m_N = pow(2,j);
			m_h = (m_b-m_a)/m_N;

			for(int i=0; i<m_N/2; i++) m_sum += m_f->Eval(m_a + ((2.*i)+1)*m_h );

			m_integral = m_integral2N;
			m_integral2N = m_sum*m_h;
		}
		
		return m_integral2N*m_sign; 
		
	}

	unsigned int getN(){return m_N;};
	double getI(){return m_integral2N;};

	private:

	double m_integral2N;
	unsigned int m_N;

};


#endif
