/* This program creates a dictionary with access to 26 files. The user inputs
a transaction file and the program executes the instructions within the
file.  This can include things such as adding, deleting, printing, or searching for words as
well as inserting words into the dictionary.
 */
#ifndef main_C
#define main_C
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

#include"Dictionary.h"

int main()
{
  string value;
  Dictionary oxford(100, 10000);
    oxford.ProcessTransactionFile();

  return 0;
}
#endif
