#include <iostream>
#include <iomanip>

#include "Seno.h"
#include "integral.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

using namespace std;

int main(int argc, const char ** argv){
  
  if (argc != 2) {
    cout << "Usage: ./main [Nstep]" << endl;
    return -1;
  }

  unsigned int N = atoi(argv[1]);

  double a = 0;
  double b = M_PI;
  unsigned int valore_atteso = 2;

  FunzioneBase *mysin=new Seno();
  Simpson I{a,b,mysin};



//========= tabella andamento dell'errore in funzione degli N passi: ==========

	cout << "CALCOLATO" << "\t" << "ERRORE" << "\t\t" << "PASSI" << endl;
  for (int i=2; i<=N; i++){

		if (i%2==0){
	  	cout << fixed << I.Integra(i);
	  	cout << "\t"  << abs(I.getIntegral()-valore_atteso);
			cout << "\t"  << i << endl; }
		else {
			i++;
			cout << fixed << I.Integra(i);
	  	cout << "\t"  << abs(I.getIntegral()-valore_atteso);
			cout << "\t"  << i << endl;
		}
  } 

	//=============================ROOT=============================

	TApplication app("app",0,0);
  TCanvas canvas_1 ("Plot1","Plot1");
  TGraph errore;
	errore.GetXaxis()->SetTitle("PASSO H");
  errore.GetYaxis()->SetTitle("ERROR");
  errore.SetTitle("andamento dell'errore in funzione del passo H");

	double counter=2;
  for (int i=2; i<=N; i++){
		if(i%2==0){
	  errore.SetPoint(i-counter, I.getH(), abs(I.Integra(i)-valore_atteso)); }
		else {
			i++;
			counter++;
			errore.SetPoint(i-counter, I.getH(), abs(I.Integra(i)-valore_atteso));
		}
	}
  
  errore.Draw("A*L");
  app.Run();  

	return 0;

}