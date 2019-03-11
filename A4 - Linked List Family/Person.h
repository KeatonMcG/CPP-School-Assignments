#ifndef Person_H
#define Person_H
#include<iostream>
#include<fstream>
using namespace std;

class Person  //this class contains the objects inherited by husband, Wife, and Child
{
 protected:
  long SSN;
  string FirstName;
  string LastName;
 public:
  Person();
  Person(long sSn, string firstName, string lastName);
  ~Person();
};
#endif
