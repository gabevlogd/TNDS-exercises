#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "funzione.h"
#include "bisezione.h"

using namespace std;

int main (int argc, char** argv) {

  if(argc < 2) {
    cout << "Using Program: " << argv[0] << " <prec> " << endl;
    exit(-1);
  }

  double prec = atof(argv[1]);

  FunzioneBase* P = new xTanx();
  Solutore* B = new Bisezione(); 


  int cifre_significative = -log10(prec);

	for (int i=1; i<21; i++){
	cout << fixed;
  cout << setprecision(cifre_significative) << B->CercaZeri(i*M_PI, (i*M_PI)+(M_PI*0.5), P, prec) << endl; 
	}

  return 0;


}