#ifndef Course_H
#define Course_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Course
{
  friend class University;
 protected:
  long CRN;
  int MaxAvailableSeats;
  string Name;
  long DepartId;
  long AssignedSeats;
  long IsTaughtBy;
  static long NextCRN;

 public:
  Course();
  Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  ~Course();
  void printCourse() const;
};
#endif
