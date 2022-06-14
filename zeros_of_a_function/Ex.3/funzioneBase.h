#ifndef __FunzioneBase__
#define __FunzioneBase__

#include <cmath>

class FunzioneBase {

  public:

  virtual double Eval (double) const=0;
  virtual ~FunzioneBase() {;};

};

#endif // __FunzioneBase__