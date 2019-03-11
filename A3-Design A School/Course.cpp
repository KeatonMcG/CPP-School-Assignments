#ifndef Course_C
#define Course_C
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#include "Course.h"

long Course:: NextCRN = 200;

Course :: Course()
{
  CRN = NextCRN++;
  MaxAvailableSeats = 0;
  Name = " ";
  DepartId = 0;
  AssignedSeats = 0;
  IsTaughtBy = 0;
}

Course :: Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  CRN = NextCRN++;
  MaxAvailableSeats = cMaxSeat;
  Name = cName;
  DepartId = cDepId;
  AssignedSeats = 0;
  IsTaughtBy = cTaughtBy;

}

Course :: ~Course()
{

}

void Course :: printCourse() const
{
  cout << "Course CRN is: " << CRN << endl;
  cout << "Course MaxAvailableSeats are: " <<  MaxAvailableSeats << endl;
  cout << "Course Name is: " << Name << endl;
  cout << "Course DepartId is: " << DepartId << endl;
  cout << "Course AssignedSeats are: " << AssignedSeats << endl;
  cout << "Course IsTaughtBy is: " <<  IsTaughtBy << endl;
}
#endif
