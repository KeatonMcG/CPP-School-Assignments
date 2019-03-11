#ifndef Child_H
#define Child_H
#include<iostream>
#include<fstream>
using namespace std;

#include "Person.h"

class Child;
typedef Child* ChildPtr;

class Child: public Person  //this class creates nodes of type Child
{
  friend class Family;

 protected:
  ChildPtr mySibling;

 public:
  Child();
  Child(long sSN, string firstName, string lastName);
  ~Child();
};
#endif
