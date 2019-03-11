#ifndef Family_H
#define Family_H
#include<iostream>
#include<fstream>
using namespace std;

#include "Person.h"
#include "Child.h"
#include "Wife.h"
#include "Husband.h"

class Family // this class holds all the functtion for the transactionfile
{
 protected: 
  HusbandPtr top;
 public:
  Family();
  void AddHusband(long SSN, string Fname, string Lname);
  bool SearchForHusband(long SSN);
  void RemoveHusband(long sSN);
  void AddWife(long SSN, string Fname, string Lname, long husbandSSN);
  void RemoveWife(long husbandSSN);
  void AddAChild(long ssn, string Fname, string Lname, long fatherSSN);
  void RemoveAChild(long FatherSSN, long childSSN);
  void PrintAFamily(long fatherSSN);
  void PrintAllFamilies();
  void ReadTransactionFile();
};
#endif
