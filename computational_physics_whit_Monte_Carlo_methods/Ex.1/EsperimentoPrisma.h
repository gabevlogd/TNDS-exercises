#ifndef _Esperimento_Prisma_h_
#define _Esperimento_Prisma_h_

#include "RandomGen.h"

class EsperimentoPrisma {

 public :

  EsperimentoPrisma() ;
  ~EsperimentoPrisma() {;} ;

  void Esegui() ;
  void Analizza() ;

  
	double GetAin(){return m_A_input;};
	double GetAmis() { return m_A_misurato ; } ;

   double GetBin(){return m_B_input;};
   double GetBmis(){return m_B_misurato;};

   double GetN1in(){return m_n1_input;};
   double GetN1mis(){return m_n1_misurato;};

   double GetN2in(){return m_n1_input;};
   double GetN2mis(){return m_n2_misurato;};

   double GetDm1in(){return m_dm1_input;};
   double GetDm1mis(){return m_dm1_misurato;};

   double GetDm2in(){return m_dm2_input;};
   double GetDm2mis(){return m_dm2_misurato;};

   double GetTh0mis(){return m_th0_misurato;};
   double GetTh1mis(){return m_th1_misurato;};
   double GetTh2mis(){return m_th2_misurato;};

  // aggiungere eventuali altri get                                                                 

 private:

  // generatore di numeri casuali                                           
  RandomGen m_rgen;

  // parametri dell'apparato sperimentale                                                                                        
  double m_lambda1, m_lambda2, m_alpha, m_sigmat;

  // valori delle quantita' misurabili :                                     
	// input    : valori assunti come ipotesi nella simulazione               
	// misurato : valore dopo la simulazione di misura                                                                                     
	double m_A_input, m_A_misurato;
  double m_B_input, m_B_misurato;
  double m_n1_input, m_n1_misurato;
  double m_n2_input, m_n2_misurato;
  double m_dm1_input, m_dm1_misurato;
  double m_dm2_input, m_dm2_misurato;
  double m_th0_input, m_th0_misurato;
  double m_th1_input, m_th1_misurato;
  double m_th2_input, m_th2_misurato;

};

#endif

