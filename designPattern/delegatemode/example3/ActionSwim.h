#ifndef ACTIONSWIM_H
#define ACTIONSWIM_H

#include <string> 
#include "Delegate.h"

class ActionSwim : public Delegate {  
  public: 
    ActionSwim(){};
    int delegateFunction(void * arg);
  private: 
      
};

#endif