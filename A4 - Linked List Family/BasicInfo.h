#ifndef BasicInfo_H
#define BasicInfo_H
#include<iostream>
#include<fstream>
using namespace std;

class BasicInfo
{
 protected:
  long SSN;
  string FirstName;
  string LastName;
 public:
  BasicInfo();
  BasicInfo(long id, string firstName, string lastName);
  ~BasicInfo();
#endif
