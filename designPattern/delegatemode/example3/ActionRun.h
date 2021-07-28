#ifndef ACTIONRUN_H
#define ACTIONRUN_H

#include <string> 
#include "Delegate.h"

class ActionRun : public Delegate {  
  public: 
    ActionRun(){};
    int delegateFunction(void * arg);
  private: 
      
};

#endif
