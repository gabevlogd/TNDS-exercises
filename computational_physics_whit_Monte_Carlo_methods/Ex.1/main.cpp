#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TAxis.h"

#include <iostream>

#include "EsperimentoPrisma.h"

using namespace std;

int main() {

  TApplication app("app",0,0);

  EsperimentoPrisma* Exp = new EsperimentoPrisma(); //oggetto esperimento

  //costruisco istogrammi delle misure da plottare:

  TH1F Theta0("Theta_0","Theta_0",250,1.571-5*29.95e-5, 1.571+4*29.95e-5);
	TH1F Theta1("Theta_1","Theta_1",250,2.549-4*30.09e-5, 2.549+5*30.09e-5);
  TH1F Theta2("Theta_2","Theta_2",250,2.657-5*30.37e-5,2.657+4*30.37e-5);
	Theta0.StatOverflows( kTRUE );
  Theta1.StatOverflows( kTRUE );
  Theta2.StatOverflows( kTRUE );

  TH1F DeltaMin1("Delta_min_1","Delta_min_1",250,0.9789-5*42.85e-5,0.9789+4*42.85e-5);
	TH1F DeltaMin2("Delta_min_2","Delta_min_2",250,1.086-4*42.74e-5,1.086+4*42.74e-5);
  DeltaMin1.StatOverflows( kTRUE );
  DeltaMin2.StatOverflows( kTRUE );

  TH1F N1("N_1","N_1",250,1.697-5*22.69e-5, 1.697+4*22.69e-5 );
	TH1F N2("N_2","N_2",250,1.751-4*20.65e-5,1.751+4*20.65e-5);
  N1.StatOverflows( kTRUE );
  N2.StatOverflows( kTRUE );

  TH1F a("A","A",250, 2.7-4*0.001305, 2.7+4*0.001305);
	TH1F b("B","B",250,pow(10,-14),1*pow(10,-14));
  a.StatOverflows( kTRUE );
  b.StatOverflows( kTRUE );

  TH2F AB("Residui A-B", "Residui A-B", 250, 2.7-4*0.001305, 2.7+4*0.001305, 250, pow(10,-14),1*pow(10,-14) );
	TH2F N1N2("Residui N_1,2", "Residui N_1,2", 250, 18.03e-5-8*13.77e-5, 18.03e-5+4*13.77e-5, 250, 53.36e-3-1*20.65e-5, 53.36e-3+9*20.65e-5);
	TH2F DeltaMin_1_2("Residui DeltaMin_1_2", "Residui DeltaMin_1_2", 250, 34.06e-5-8*26e-5,34.06e-5+6*26e-5, 250, 34.05e-5-8*25.85e-5,34.05e-5+6*25.85e-5);
  AB.StatOverflows( kTRUE );
  N1N2.StatOverflows( kTRUE );
  N1N2.StatOverflows( kTRUE );

  //eseguo l'esperimento e metto i risultati negli istogrammi:

  double DeltaMin_coef_corr = 0;
  double N_1_2_coef_corr = 0;
  double ab_coef_corr = 0;
  
  for(int i=0; i<10000; i++){
	  Exp->Esegui();
	  Exp->Analizza();

	  Theta0.Fill(Exp->GetTh0mis());
	  Theta1.Fill(Exp->GetTh1mis());
	  Theta2.Fill(Exp->GetTh2mis());

	  DeltaMin1.Fill(Exp->GetTh1mis()-Exp->GetTh0mis());
	  DeltaMin2.Fill(Exp->GetTh2mis()-Exp->GetTh0mis());
		
	  N1.Fill(Exp->GetN1mis());
	  N2.Fill(Exp->GetN2mis());

	  a.Fill(Exp->GetAmis());
	  b.Fill(Exp->GetBmis());
		
	  AB.Fill(Exp->GetAmis()-Exp->GetAin(), Exp->GetBmis()-Exp->GetBin());
	  N1N2.Fill(Exp->GetN1mis()-Exp->GetN1in(), Exp->GetN2mis()-Exp->GetN2in());
	  DeltaMin_1_2.Fill(Exp->GetDm1mis()-Exp->GetDm1in(), Exp->GetDm2mis()-Exp->GetDm2in());

	  DeltaMin_coef_corr += (Exp->GetDm1mis()*Exp->GetDm2mis());
	  N_1_2_coef_corr += Exp->GetN1mis() * Exp->GetN2mis();
	  ab_coef_corr += Exp->GetAmis() * Exp->GetBmis();
  }

  //stampo medie e deviazioni standard:

  cout << "θ_0 = " << Theta0.GetMean(1) << " +/- " << Theta0.GetStdDev(1) <<"  [rad]"<< endl;
  cout << "θ_1 = " << Theta1.GetMean(1) << " +/- " << Theta1.GetStdDev(1) <<"  [rad]"<< endl;
  cout << "θ_2 = " << Theta2.GetMean(1) << " +/- " << Theta2.GetStdDev(1) <<"  [rad]"<< endl;
  cout << "δmin_1 = " << DeltaMin1.GetMean(1) << " +/- " << DeltaMin1.GetStdDev(1) <<"  [rad]"<< endl;
  cout << "δmin_2 = " << DeltaMin2.GetMean(1) << " +/- " << DeltaMin2.GetStdDev(1) <<"  [rad]"<< endl;
  cout << "n(λ_1) = " << N1.GetMean(1) << " +/- " << N1.GetStdDev(1) << endl;
  cout << "n(λ_2) = " << N2.GetMean(1) << " +/- " << N2.GetStdDev(1) << endl;
  cout << "Α = " << a.GetMean(1) << " +/- " << a.GetStdDev(1) << endl;
  cout << "Β = " << b.GetMean(1) << " +/- " << b.GetStdDev(1) <<"  [m^2]"<< endl; 

  //coefficienti di correlazione: 

  cout << "ρ(δmin_1, δmin_2) = " << ((DeltaMin_coef_corr/10000)-(DeltaMin1.GetMean(1)*DeltaMin2.GetMean(1)))/(DeltaMin1.GetStdDev(1)*DeltaMin2.GetStdDev(1)) << endl;

  cout << "ρ(n(λ_1), n(λ_2)) = " << ((N_1_2_coef_corr/10000)-(N1.GetMean(1)*N2.GetMean(1)))/(N1.GetStdDev(1)*N2.GetStdDev(1)) << endl;

  cout << "ρ(A, B) = " << ((ab_coef_corr/10000)-(a.GetMean(1)*b.GetMean(1)))/(a.GetStdDev(1)*b.GetStdDev(1)) << endl;

  //info istogramma Theta0:
  TCanvas can1("Theta_0", "Theta_0");
  can1.cd();
  Theta0.GetXaxis()->SetTitle("Theta_0 [rad]");
  Theta0.GetYaxis()->SetTitle("N");
  Theta0.SetTitle("Distribuzione risultati Theta0");
  Theta0.Draw();

  //info istogramma Theta1:
  TCanvas can2("Theta_1", "Theta_1");
  can2.cd();
  Theta1.GetXaxis()->SetTitle("Theta_1 [rad]");
  Theta1.GetYaxis()->SetTitle("N");
  Theta1.SetTitle("Distribuzione risultati Theta1");
  Theta1.Draw();

  //info istogramma Theta2:
  TCanvas can3("Theta_2", "Theta_2");
  can3.cd();
  Theta2.GetXaxis()->SetTitle("Theta_2 [rad]");
  Theta2.GetYaxis()->SetTitle("N");
  Theta2.SetTitle("Distribuzione risultati Theta2");
  Theta2.Draw();

  //info istogramma DeltaMin1:
  TCanvas can4("Delta_min_1", "Delta_min_1");
  can4.cd();
  DeltaMin1.GetXaxis()->SetTitle("DeltaMin_1 [rad]");
  DeltaMin1.GetYaxis()->SetTitle("N");
  DeltaMin1.SetTitle("Distribuzione risultati Delta_min_1");
  DeltaMin1.Draw();

  //info istogramma DeltaMin2:
  TCanvas can5("Delta_min_2", "Delta_min_2");
  can5.cd();
  DeltaMin2.GetXaxis()->SetTitle("DeltaMin_2 [rad]");
  DeltaMin2.GetYaxis()->SetTitle("N");
  DeltaMin2.SetTitle("Distribuzione risultati Delta_min_2");
  DeltaMin2.Draw();

  //info istogramma N1:
  TCanvas can6("N_1", "N_1");
  can6.cd();
  N1.GetXaxis()->SetTitle("N1");
  N1.GetYaxis()->SetTitle("N");
  N1.SetTitle("Distribuzione risultati N1");
  N1.Draw();

  //info istogramma N2:
  TCanvas can7("N_2", "N_2");
  can7.cd();
  N2.GetXaxis()->SetTitle("N2");
  N2.GetYaxis()->SetTitle("N");
  N2.SetTitle("Distribuzione risultati N2");
  N2.Draw();

  //info istogramma A:
  TCanvas can8("A", "A");
  can8.cd();
  a.GetXaxis()->SetTitle("A");
  a.GetYaxis()->SetTitle("N");
  a.SetTitle("Distribuzione risultati A");
  a.Draw();

  //info istogramma B:
  TCanvas can9("B", "B");
  can9.cd();
  b.GetXaxis()->SetTitle("B [m^2]");
  b.GetYaxis()->SetTitle("N");
  b.SetTitle("Distribuzione risultati B");
  b.Draw();

  //info istogramma AB:
  TCanvas can10("Residui A-B", "Residui A-B");
  can10.cd();
  AB.GetXaxis()->SetTitle("A");
  AB.GetYaxis()->SetTitle("B [m^2]");
  AB.SetTitle("Residui A-B");
  AB.Draw();

  //info istogramma N1N2:
  TCanvas can11("Residui N_1,2", "Residui N_1,2");
  can11.cd();
  N1N2.GetXaxis()->SetTitle("N1");
  N1N2.GetYaxis()->SetTitle("N2");
  N1N2.SetTitle("Residui N_1,2");
  N1N2.Draw();

  //info istogramma DeltaMin_1_2:
  TCanvas can12("Residui DeltaMin_1_2", "Residui DeltaMin_1_2");
  can12.cd();
  DeltaMin_1_2.GetXaxis()->SetTitle("DeltaMin_1 [rad]");
  DeltaMin_1_2.GetYaxis()->SetTitle("DeltaMin_2 [rad]");
  DeltaMin_1_2.SetTitle("Residui DeltaMin_1_2");
  DeltaMin_1_2.Draw();


  app.Run();
  return 0;



	
}