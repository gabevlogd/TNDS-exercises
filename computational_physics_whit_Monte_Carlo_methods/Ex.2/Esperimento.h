#ifndef _Esperimento_h_
#define _Esperimento_h_

#include "RandomGen.h"

class Esperimento {

 public:
   Esperimento(double R);
   ~Esperimento(){;};

   void Esegui();
   void Analizza();

	 double GetRho(){return m_rho;};
   double GetRho0(){return m_rho0;};
   double GetG(){return m_g;};
   //double GetR(){return m_R;};
   //double GetX(){return m_x;};
   double GetEtaIn(){return m_eta_in;};
   double GetEtaMis(){return m_eta_mis;};
   double GetTIn(){return m_t_in;};
   double GetTMis(){return m_t_mis;};
   

 private:

   // generatore di numeri casuali
   RandomGen m_rgen;

   // parametri dell'apparato sperimentale
	 double m_rho, m_rho0, m_g;

   // valori delle quantita' misurabili:
   // *_in    : valori assunti come ipotesi nella simulazione
   // *_mis : valore dopo la simulazione di misura

	 double m_eta_in, m_eta_mis;
	 double m_v_in, m_v_mis;
	 double m_t_in, m_t_mis;
	 double m_x_in, m_x_mis;
	 double m_R_in, m_R_mis;

	 //valori incertezze delle misure:

	 double m_sigma_t, m_sigma_x, m_sigma_R;
   

};

#endif