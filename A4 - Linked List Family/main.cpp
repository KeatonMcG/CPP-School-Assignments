/*
Purpose: Design a program that creates a directory of families
and places them into a link list.

Inputs: The user gives the program a transaction file to process,
the program does not prompt the user for any additional inputs.

Outputs: The program outputs the information retrieved and
processed by the functions in the Family.cpp file


*/

#ifndef Main_C
#define Main_C
#include<iostream>
#include<fstream>
using namespace std;

#include "Person.h"
#include "Child.h"
#include "Wife.h"
#include "Husband.h"
#include "Family.h"

int main()
{
  Family USAFamilies;
  USAFamilies.ReadTransactionFile();
  return 0;
} 
#endif 
