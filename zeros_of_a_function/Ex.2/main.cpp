#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "parabola.h"
#include "bisezione.h"

using namespace std;

int main (int argc, char** argv) {

  if(argc < 4) {
    cout << "Using Program: " << argv[0] << " <min> <max> <prec> " << endl;
    exit(-1);
  }

  double min = atof(argv[1]);
  double max = atof(argv[2]);
  double prec = atof(argv[3]);

  FunzioneBase* P = new Parabola(3., 5., -2.);
  Solutore* B = new Bisezione(); 


  int cifre_significative = -log10(prec);
  cout << setprecision(cifre_significative) << B->CercaZeri(min, max, P, prec) << endl; 


  return 0;


}
