#ifndef Student_C
#define Student_C
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#include "BasicInfo.h"
#include "Student.h"

long Student:: NextStId = 500;

Student :: Student()
{
  YearOfStudy = 0;
  Major = " ";
  AdvisorId = 0;
  NextStId++;

}
Student ::  Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  Id = NextStId++;
  Name = sName;
  Email = sEmail;
  Address = sAddress;
  DateOfBirth = sDateOfBirth;
  Gender = sGender;
  YearOfStudy = sYearOfStudy;
  Major = sMajor;
  AdvisorId = sAdvisorId;
 }

Student :: ~Student()
{
}
void Student :: printStudent() const
{
  cout << "Id is: " << Id << endl;
  cout << "Name is: " << Name << endl;
  cout << "Email is: " << Email << endl;
  cout << "Address is: " << Address << endl;
  cout << "DateOfBirth is: " << DateOfBirth << endl;
  cout << "Gender is: " << Gender << endl;
  cout << "Year of study is: " << YearOfStudy << endl;
  cout << "Major is: " << Major << endl;
  cout << "AdvisorId: " << AdvisorId << endl;
}
#endif
