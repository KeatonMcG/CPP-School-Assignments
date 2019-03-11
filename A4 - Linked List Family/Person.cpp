#ifndef Person_C
#define Person_C
#include<iostream>
#include<fstream>
using namespace std;

#include "Person.h"

Person :: Person()
{
  SSN = 0;
  FirstName = " ";
  LastName = " ";
}
//-------------------------------------------------------------
Person :: Person(long sSn, string firstName, string lastName)
{
  SSN = sSn; 
  FirstName = firstName;
  LastName = lastName;
}
//------------------------------------------------------------
Person :: ~Person()
{
}
#endif
