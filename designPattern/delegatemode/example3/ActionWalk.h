#ifndef ACTIONWLK_H
#define ACTIONWLK_H

#include <string> 
#include "Delegate.h"

class ActionWalk: public Delegate {  
  public: 
    ActionWalk(){};
    int delegateFunction(void * arg);
  private: 
      
};

#endif