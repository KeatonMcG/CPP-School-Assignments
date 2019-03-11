#ifndef Faculty_H
#define Faculty_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Faculty:public BasicInfo
{
  friend class University;
 protected:
  //inheritance objects
  float Salary;
  int YearOfExp;
  long DepartId;
  static long NextFacultyId;

 public:
  Faculty();
  Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  ~Faculty();
  void printFaculty() const;
};
#endif
