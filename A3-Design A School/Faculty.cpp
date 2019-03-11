#ifndef Faculty_C
#define Faculty_C
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#include "BasicInfo.h"
#include "Faculty.h"

long Faculty:: NextFacultyId = 600;

Faculty :: Faculty()
{
  Salary = 0;
  YearOfExp = 0;
  DepartId = 0;
  NextFacultyId++;
}

Faculty :: Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
  Id = NextFacultyId++;
  Name = fName;
  Email = fEmail;
  Address = fAddress;
  DateOfBirth = fDateOfBirth;
  Gender = fGender;
  Salary = fSalary;
  YearOfExp = fYearOfExp;
  DepartId = fDepId;
}

Faculty :: ~Faculty()
{
}
void Faculty :: printFaculty() const
{
  cout << "Id is: " << Id << endl;
  cout << "Name is: " << Name << endl;
  cout << "Email is: " << Email << endl;
  cout << "Address is: " << Address << endl;
  cout << "DateOfBirth is: " << DateOfBirth << endl;
  cout << "Gender is: " << Gender << endl;
  cout << "Salary is: " << Salary << endl;
  cout << "YearOfExp is: " << YearOfExp << endl;
  cout << "DeparyId is " << DepartId << endl;
}
#endif
