#ifndef Husband_H
#define Husband_H
#include<iostream>
#include<fstream>
using namespace std;

#include "Person.h"

class Husband;
typedef Husband* HusbandPtr;

class Wife;
typedef Wife* WifePtr;

class Husband: public Person  //this class creates nodes of type husband
{
  friend class Family;

 protected:
  HusbandPtr nextFamily;
  WifePtr myWife;
 public:
  Husband();
  Husband(long sSn, string firstName, string lastName);
 ~Husband();
};
#endif
