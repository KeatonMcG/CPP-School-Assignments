#ifndef Department_H
#define Department_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Department
{
  friend class University;
 protected:
  long Id;
  string Name;
  string Location;
  long ChairId;
  static long NextDepartId;

 public:
  Department();
  Department(string depName, string depLoc, long depChairId);
  ~Department();
  void printDepartment() const;
};
#endif
