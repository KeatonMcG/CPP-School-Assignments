#ifndef Husband_C
#define Husband_C
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include "Person.h"
#include "Husband.h"

Husband :: Husband()
{
  nextFamily = NULL;
  myWife = NULL;
}
//------------------------------------------------------------
Husband :: Husband(long sSn, string firstName, string lastName)
{
  SSN = sSn;
  FirstName = firstName;
  LastName = lastName;
  nextFamily = NULL;
  myWife = NULL;
}
//-----------------------------------------------------------
Husband :: ~Husband()
{
}

#endif 
