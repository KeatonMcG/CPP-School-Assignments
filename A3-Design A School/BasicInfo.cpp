#ifndef Faculty_C
#define Faculty_C
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#include "BasicInfo.h"

BasicInfo :: BasicInfo()
{
  Id = 0;
  Name = " ";
  Email = " ";
  Address = " ";
  DateOfBirth = " ";
  Gender = " ";
}

BasicInfo :: BasicInfo(long id, string name, string email, string address, string dateOfBirth, string gender)
{
  Id = id;
  Name = name;
  Email = email;
  Address = address;
  DateOfBirth = dateOfBirth;
  Gender = gender;
}

BasicInfo :: ~BasicInfo()
{

}
#endif
