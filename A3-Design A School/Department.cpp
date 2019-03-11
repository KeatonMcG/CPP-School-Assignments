#ifndef Department_C
#define Department_C
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#include "Department.h"

long Department:: NextDepartId = 100;

Department :: Department()
{
  Id = NextDepartId++;
  Name = " ";
  Location = " ";
  ChairId = 0;
}

Department :: Department(string depName, string depLoc, long depChairId)
{
  Id = NextDepartId++;
  Name = depName;
  Location = depLoc;
  ChairId = depChairId;
  long departId = Id;
}

Department :: ~Department()
{

}

void Department :: printDepartment() const
{
  cout << "Department Id is: " << Id << endl;
  cout << "Department Name is: " << Name << endl;
  cout << "Department Location is: " << Location << endl;
  cout << "Department ChairId is: " << ChairId << endl;
}
#endif
