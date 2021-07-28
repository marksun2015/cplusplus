#include <iostream>
#include <stdlib.h> 
#include "Person.h"
#include "Delegate.h"
#include "ActionRun.h"
#include "ActionWalk.h"
#include "ActionSwim.h"

using namespace std;

int main() {    
    Person person; 
    
    /*create action*/
    Delegate *action = new ActionRun();
    person.setAction(action);
    person.performAction();
    
    /*create new behavior*/
    free(action);
    action = new ActionWalk();
    person.setAction(action);
    person.performAction();
    /*clean up*/
    
    /*create new behavior*/
    free(action);
    action = new ActionSwim();
    person.setAction(action);
    person.performAction();
    /*clean up*/
    
    return 0;
}
