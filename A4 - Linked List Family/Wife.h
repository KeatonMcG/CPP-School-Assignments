#ifndef Wife_H
#define Wife_H
#include<iostream>
#include<fstream>
using namespace std;

#include "Person.h"


class Child;    
typedef Child* ChildPtr;

class Wife: public Person   //this class creates nodes of type Wife

{
  friend class Family;

 protected:
  ChildPtr myChildren;
 
 public:
  Wife();
  Wife(long sSN, string firstName, string lastName);
  ~Wife();
};
#endif

