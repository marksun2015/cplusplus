#ifndef PERSON_H
#define PERSON_H

#include <string> 
#include "Delegate.h"

class Person {  
  public: 
  
    void setAction(Delegate * action);
    void performAction();
     
  private: 
  
    Delegate * action;        
    
};

#endif
