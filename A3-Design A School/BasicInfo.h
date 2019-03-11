#ifndef BasicInfo_H
#define BasicInfo_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class BasicInfo
{
 protected:
  long Id;
  string Name;
  string Email;
  string Address;
  string DateOfBirth;
  string Gender;
 public:
  BasicInfo();
  BasicInfo(long id, string name, string email, string address, string dateOfBirth, string gender);
  ~BasicInfo();
};
#endif
