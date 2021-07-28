#include "Person.h"

void Person::setAction(Delegate * action)
{
  Person::action = action;   
}
void Person::performAction()
{
    Person::action->delegateFunction((void*)(0));
}

