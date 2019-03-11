#ifndef Student_H
#define Student_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Student:public BasicInfo
{
  friend class University;
  protected:
  //inheritance objects
  int YearOfStudy;
  string Major;
  long AdvisorId;
  vector<long> CoursesTaken;
  static long NextStId;

 public:
  Student();
  Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  ~Student();
  void printStudent() const;
};
#endif
