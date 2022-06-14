#include <iostream>
#include <iomanip>

#include "Seno.h"
#include "integral.h"

using namespace std;

int main(int argc, const char ** argv){
  
  if (argc != 2) {
    cout << "Usage: ./main [precision]" << endl;
    return -1;
  }

  double prec = atof(argv[1]);
	int cifre_significative = -log10(prec);

  double a = M_PI;
  double b = M_PI; //DEG M_PI*0.5;
  unsigned int valore_atteso = 2;

  FunzioneBase *mysin=new Seno();
  Trapezoidi I{a,b,mysin};

	cout << "I = " << setprecision(cifre_significative) << I.Integra(prec) << endl;  

	return 0;

}