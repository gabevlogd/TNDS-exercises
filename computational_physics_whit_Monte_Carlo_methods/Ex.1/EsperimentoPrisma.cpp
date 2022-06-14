#include "EsperimentoPrisma.h"
#include <cmath>

EsperimentoPrisma::EsperimentoPrisma() :
  m_rgen(1),
  m_lambda1(579.1E-9),
  m_lambda2(404.7E-9),
  m_alpha(60.*M_PI/180.),
  m_sigmat(0.3E-3),
  m_A_input(2.7),
  m_B_input(60000E-18)
{
  // calcolo degli indici di rifrazione
  m_n1_input = sqrt(m_A_input + m_B_input / (m_lambda1*m_lambda1) );
  m_n2_input = sqrt(m_A_input + m_B_input / (m_lambda2*m_lambda2) );

  // theta0 e' arbitrario, scelgo M_PI/2.

  m_th0_input = M_PI/2.;

  // determino theta1 e theta2

	m_dm1_input = 2.*asin( m_n1_input * sin (0.5 * m_alpha) ) - m_alpha ;
  m_th1_input = m_th0_input + m_dm1_input ;
  m_dm2_input = 2.*asin( m_n2_input * sin (0.5 * m_alpha) ) - m_alpha ;
  m_th2_input = m_th0_input + m_dm2_input ;
  	
}  


void EsperimentoPrisma::Esegui(){
	m_th0_misurato = m_rgen.Gauss(m_th0_input, m_sigmat);
	m_th1_misurato = m_rgen.Gauss(m_th1_input, m_sigmat);
	m_th2_misurato = m_rgen.Gauss(m_th2_input, m_sigmat);
}

void EsperimentoPrisma::Analizza(){
	m_dm1_misurato = m_th1_misurato - m_th0_misurato;
	m_dm2_misurato = m_th2_misurato - m_th0_misurato;

	m_n1_misurato = sin((m_dm1_misurato+m_alpha)*0.5)/sin(m_alpha*0.5);
	m_n2_misurato = sin((m_dm2_misurato+m_alpha)*0.5)/sin(m_alpha*0.5);

	m_A_misurato = (pow(m_lambda2,2)*pow(m_n2_misurato,2)-pow(m_lambda1,2)*pow(m_n1_misurato,2))/(pow(m_lambda2,2)-pow(m_lambda1,2));
	m_B_misurato = (pow(m_n2_misurato,2)-pow(m_n1_misurato,2))/(1./pow(m_lambda2,2)-1./pow(m_lambda1,2));
}
