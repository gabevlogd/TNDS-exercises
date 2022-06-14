#include "Particella.h"
#include <iostream> 

using namespace std;

int main() {

  Particella *a   = new Particella(1.,1.6E-19);
  Elettrone *e    = new Elettrone();
  
  // Metodi della classe base
  cout << "Particella " << a->getCarica() << "," << a->getMassa() << endl;
  a->print(); 

  // Metodi della classe derivata
  cout << "Elettrone " << e->getCarica() << "," << e->getMassa() << endl;
  e->print(); 

  Particella b(*a) ;  // costruisco una Particella a partire da una Particella
  Particella d(*e);   // costruisco una Particella a partire da un Elettrone
  //Elettrone f(*d);    // costruisco un Elettrone a partire da una Particella 

  return 0;

}
