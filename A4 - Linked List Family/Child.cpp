#ifndef Child_C
#define Child_C
#include<iostream>
#include<fstream>
using namespace std;

#include "Person.h"
#include "Child.h"

Child :: Child()
{
  mySibling = NULL;
}
//------------------------------------------------------------
Child :: Child(long sSn, string firstName, string lastName)
{
  SSN = sSn;
  FirstName = firstName;
  LastName = lastName;
  mySibling = NULL;
}
//-----------------------------------------------------------
Child :: ~Child()
{
}

#endif
