#ifndef Family_C
#define Family_C
#include<iostream>
#include<fstream>
using namespace std;

#include "Person.h"
#include "Child.h"
#include "Wife.h"
#include "Husband.h"
#include "Family.h"

//----------------------------------------------------------
Family :: Family()
{
  top = NULL;
}
//----------------------------------------------------------
void Family :: AddHusband(long SSN, string Fname, string Lname) //puts new husband into the list
{
       if(top == NULL)             // if nothing is in the list start here
	{
	  HusbandPtr P = new Husband(SSN, Fname, Lname); 
	  top = P;
	  P -> nextFamily = NULL;
	  P -> myWife = NULL;
	  return;
	}
       HusbandPtr P = new Husband(SSN, Fname, Lname); //if there is already a Husband in the list start here
       P -> nextFamily = top;  //set next family to the top pointer
      P -> myWife = NULL;
      top = P;                 // makes P the new top
}
//------------------------------------------------------------
void Family :: RemoveHusband(long sSN)  //removes husband and his family from the list
{
  if(SearchForHusband(sSN) == false)    //make sure the husband is in the list
    {
      HusbandPtr P = top;

      if(P -> SSN == sSN)      // if its the 1st husband in the list
	{
	  P = P -> nextFamily;
	  if(top -> myWife != NULL)
	    {
	     RemoveWife(sSN); //calls function to delete husbands family
	    }
	  delete top;
	  top = P;
	  return;
	}

      HusbandPtr Q = top -> nextFamily; // creates 2nd pointer
      while(Q -> SSN != sSN)            //finds the husband
	{
	  P = Q;
	  Q = Q -> nextFamily;
	}

      if(Q -> nextFamily == NULL)   //if husband is last one in the list
	{
          if(top -> myWife != NULL)
            {
	      RemoveWife(sSN); //calls function to delete husbands family
            }
	  delete Q;
	  P -> nextFamily = NULL;
	  return;
	}
      else                        //else husband must be in the middle of the list
	{
	  HusbandPtr Y = Q;      //creates 3rd pointer 
	  Q = Q -> nextFamily;   //moves second pointer to nextHusband
          if(top -> myWife != NULL)
            {
              RemoveWife(sSN); //calls function to delete husbands family
            }
	  delete Y;              //deletes 3rd pointer
	  P -> nextFamily = Q;   //reconnects 1st pointer to 2nd pointer
	  return;
	}
    }
  cout << sSN << " was not in the list" << endl; //if husband wasnt found message 
}

//------------------------------------------------------------
bool Family :: SearchForHusband(long ssn)  //checks to see if the husband is in the list
{
  HusbandPtr P = top;
  while(P != NULL)
    {
      if(P -> SSN == ssn)
	{
	  return false;
	}
      P = P -> nextFamily;
    }
  return true;
}
//-------------------------------------------------------------------------
void Family :: AddWife(long SSN, string Fname, string Lname, long husbandSSN) // attaches a wife to her husband
{
  if(SearchForHusband(husbandSSN) == false) //makes sure her husband exists
    {
      HusbandPtr P = top;
      while(P -> SSN != husbandSSN)  //finds the last Husband
        {
          P  = P -> nextFamily;
        }

      WifePtr Q =  new Wife(SSN, Fname, Lname);
      P -> myWife = Q;
      Q -> myChildren = NULL;
      return;
    }
  else
    cout << "\n" << SSN  <<" does not have a matching husband" << endl;
}
//------------------------------------------------------------------
void Family :: RemoveWife(long husbandSSN) // removes a wife and her children from the list
{
  if(SearchForHusband(husbandSSN) == false)
    {
      HusbandPtr P = top;
      while(P -> SSN != husbandSSN)  //finds the Husband
        {
          P  = P -> nextFamily;
        }

      WifePtr Q =  P -> myWife;
      if(Q -> myChildren == NULL) // if no children execute this
	{
	  delete Q;
	  P -> myWife = NULL;
	  return;
	}

      ChildPtr Z = Q -> myChildren; // if one child execute this
      if(Z -> mySibling == NULL)
	{
	  delete Z;
	  delete Q;
	  P -> myWife = NULL;
	  return;
	}

      ChildPtr Y = Z -> mySibling;
      while(Y -> mySibling != NULL) // keeps removing kids until none remain
	{
	  delete Z;            //deletes a child
	  Z =Y;               // moves to the next child
	  Y = Y -> mySibling;
	}
      delete Z;
      delete Y;
      delete Q;
      P -> myWife = NULL;
      return;
    }
  cout << husbandSSN << " was not found" << endl;
} 
//------------------------------------------------------------------
void Family :: AddAChild(long ssn, string Fname, string Lname, long fatherSSN) // adds a child to the list
{
  if(SearchForHusband(fatherSSN) == false)  // makes sure the childs father exists
    {
      HusbandPtr P = top;
      while(P -> SSN != fatherSSN)  //finds the childs father
        {
          P  = P -> nextFamily;
        }

      if(P -> myWife == NULL)  //makes sure the child has a mother
	{
	  cout << fatherSSN << " has no wife" << endl;
	  return;
	}

      WifePtr Q = P -> myWife;

      if(Q -> myChildren == NULL) // if no kids are in the list yet
	{
	  ChildPtr Z = new Child(ssn, Fname, Lname);
	  Q -> myChildren = Z;
	  Z -> mySibling = NULL;
	  return;
	}

      ChildPtr Z = new Child(ssn, Fname, Lname);
      ChildPtr Y = Q -> myChildren;

      while(Y -> mySibling != NULL) //finds the last child in the family
	{
	  Y = Y -> mySibling;
	}
      Y -> mySibling = Z;        //attaches the last child to the new child
      Z -> mySibling = NULL;    //sets new childs sibling to NULL
      return;
    }
  cout << fatherSSN << " was not found" << endl;
}
//------------------------------------------------------------------
void Family :: RemoveAChild(long FatherSSN, long childSSN) // removes a child from the list
{
  if(SearchForHusband(FatherSSN) == false)
    {
      HusbandPtr P = top;
      while(P -> SSN != FatherSSN)  //finds the childs father
        {
          P  = P -> nextFamily;
        }

      WifePtr Q = P -> myWife;
      ChildPtr Z = Q -> myChildren;  //first pointer for child deletion

      if((Z -> SSN == childSSN) && (Z -> mySibling == NULL)) //if only one child in Family
	{
	  delete Z;
	  Q -> myChildren = NULL;
	  return;
	}

      ChildPtr Y = Q -> myChildren; //second pointer for child deletion

      if((Z -> SSN == childSSN) && (Z -> mySibling != NULL)) //if first child of multiple kids
        {
	  Y = Y -> mySibling;
          delete Z;
          Q -> myChildren = Y;
          return;
        }

      while(Y -> SSN != childSSN)   //finds the child
	{
	  if(Y -> mySibling == NULL)
	    {
	      cout << "\n" << childSSN << " is not in the list" << endl;
	      return;
	    }
	  Z = Y;
	  Y = Y -> mySibling;
	}

      if(Y -> mySibling != NULL)  //if child is a middle child
	{                        
	  ChildPtr X = Y;        //third pointer set to the same spot as 2nd
	  Y = Y -> mySibling;   // moves 2nd pointer to the child in front 
	  delete X;             // deletes 3rd pointer
	  Z -> mySibling = Y;  //reconnects 1st pointer to 2nd pointer
	  return;
	}

      else // else it must be the last child in the family
	{
	  delete Y;
	  Z -> mySibling = NULL;
	  return;
	}
    }
  cout << "Childs Father does not exist" << endl;
}
//------------------------------------------------------------------
void Family :: PrintAFamily(long fatherSSN)  //prints one family based on the husbands SSN
{
  cout << "\n";
  if(SearchForHusband(fatherSSN) == false)  // makes sure the husbands SSN is in the list
    {
      HusbandPtr P = top;
      while(P -> SSN != fatherSSN)  //finds the Husband
        {
          P  = P -> nextFamily;
        }
      cout << "Fathers information is:      ";
      cout << P -> SSN << "\t";
      cout << P -> FirstName << "\t";  
      cout << P -> LastName << "\t" << endl;

      WifePtr Q = P -> myWife;

      if(P -> myWife == NULL) // if no wife execute this
	{
	  return;
        }
	
      else
	{
	  cout << "Mothers information is:      ";
	  cout << Q -> SSN << "\t";
	  cout << Q -> FirstName << "\t";
	  cout << Q -> LastName << "\t" << endl;
	}

      ChildPtr Z = Q -> myChildren;

      if(Q -> myChildren != NULL) //execute this if the family has children
	{

	  while(Z -> mySibling != NULL) // prints all the kids tin the list
	 {
          cout << "Childs information is:      ";
          cout << Z -> SSN << "\t";
          cout << Z -> FirstName << "\t";
          cout << Z -> LastName << "\t" << endl;
	  Z = Z -> mySibling;
	 }
      cout << "Childs information is:      ";
      cout << Z -> SSN << "\t";
      cout << Z -> FirstName << "\t";
      cout << Z -> LastName << "\t" << endl;
      return;
	}
      cout << "There are no children" << endl;
      return;
    }
  cout << "No family matches " << fatherSSN << endl;
}
//---------------------------------------------------------------
void Family :: PrintAllFamilies() //prints the entire list
{
  cout << "\n";
  HusbandPtr P = top;

  while(P -> nextFamily != NULL) // loop prints family then moves to the next one
    {
      PrintAFamily(P -> SSN); //calls function to print one family at a time
      P = P -> nextFamily;
    }
  PrintAFamily(P -> SSN);
}

//---------------------------------------------------------------
void Family :: ReadTransactionFile() //reads in the information from the transaction file
{
  string command = "";
  string fName, Lname;
  long firstSSN, fatherSSN;

  ifstream fin;
  fin.open("TransactionFile.txt");

  while(fin >> command)
    {
      if(command == "AddHusband")
	{
       	  fin >> firstSSN >> fName >> Lname;
	  AddHusband(firstSSN, fName, Lname);
	}
      else if(command == "PrintAllFamilies")
	{
	  PrintAllFamilies();
	  }
      else if(command == "AddWife")
	{
	  fin >> firstSSN >> fName >> Lname >> fatherSSN;
	  AddWife(firstSSN, fName, Lname, fatherSSN);
	}
      else if(command == "AddAChild")
        {
          fin >> firstSSN >> fName >> Lname >> fatherSSN;
          AddAChild(firstSSN, fName, Lname, fatherSSN);
	  }
      else if(command == "RemoveAChild")
	{
	  fin >> fatherSSN >> firstSSN;
	  RemoveAChild(fatherSSN, firstSSN);
	}
      else
	{
	  fin >> fatherSSN;
	  PrintAFamily(fatherSSN);
	}
    }
      fin.close();
}
#endif
