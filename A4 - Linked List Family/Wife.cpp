#ifndef Wife_C
#define Wife_C
#include<iostream>
#include<fstream>
using namespace std;

#include "Person.h"
#include "Wife.h"

Wife :: Wife()
{
  myChildren = NULL;
}
//------------------------------------------------------------
Wife :: Wife(long sSn, string firstName, string lastName)
{
  SSN = sSn;
  FirstName = firstName;
  LastName = lastName;
  myChildren = NULL;
}
//-----------------------------------------------------------
Wife :: ~Wife()
{
}

#endif

