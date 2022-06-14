#include "Esperimento.h"
#include "RandomGen.h"
#include <cmath>


Esperimento::Esperimento(double R) : m_rgen(1), m_rho(2700), m_rho0(1250), m_g(9.81),
m_eta_in(0.83), m_x_in(0.4), m_sigma_t(0.01), m_sigma_x(0.001), m_sigma_R(0.0001) {

	//raggio della sfera (passato da fuori per poter ripetere con raggi differenti)
	m_R_in = R;

	//velocità limite:
	m_v_in = (2.*pow(m_R_in,2))/(9.*m_eta_in) * (m_rho-m_rho0) * m_g;

	//tempo necessario a percorrere lo spazio x:
	m_t_in = m_x_in/m_v_in;
	
}

void Esperimento::Esegui(){

	m_t_mis = m_rgen.Gauss(m_t_in, m_sigma_t);
	m_x_mis = m_rgen.Gauss(m_x_in, m_sigma_x);
	m_R_mis = m_rgen.Gauss(m_R_in, m_sigma_R);

}

void Esperimento::Analizza(){

	//calcolo velocità misurata:
	m_v_mis = m_x_mis/m_t_mis;

	//calcolo eta misurato:
	m_eta_mis = (2.*pow(m_R_mis,2))/(9.*m_v_mis) * (m_rho-m_rho0) * m_g;
}