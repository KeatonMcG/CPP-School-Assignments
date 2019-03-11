/*
Purpose: Design a program that resembles a small university through as well as to demonstrate the use of inheritance.
Inputs: The user gives the program a transaction file to process, the program does not prompt the user for any values.
Outputs: The program outputs the information retrieved and processed by the functions created in the University.cpp file

*/


#ifndef Main_C
#define Main_C
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#include "BasicInfo.h"
#include "Student.h"
#include "Faculty.h"
#include "Course.h"
#include "Department.h"
#include "University.h"

int main()
{
  University csusm;
  csusm.ProcessTransactionFile("TransactionFile.txt");
  return 0;
}
#endif
