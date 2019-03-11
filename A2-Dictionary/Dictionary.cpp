#ifndef Dictionary_C
#define Dictionary_C
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

#include "Dictionary.h"

bool Dictionary::failure = false;
bool Dictionary::success = true;

Dictionary::Dictionary():maxWordsPerFile(100), maxWordsInDict(100000)
{
     totalWordsInDict = 0;
     for(int i = 0; i < 26; i++)
     numOfWordsInFile[i] = 0;
}

Dictionary::Dictionary(int MaxF, int MaxD):maxWordsPerFile(MaxF), maxWordsInDict(MaxD)
{
     totalWordsInDict = 0;
     for(int i = 0; i < 26; i++)
       numOfWordsInFile[i] = 0;
}

bool Dictionary:: AddAWord(string word)
{
  bool ok = SearchForWord(word);
  if(ok==false)
    return(Dictionary::failure);
  else
    {
  string fileName = "?.txt";
  char ch = toupper(word[0]);
  fileName[0] = ch;

    ofstream fout;
    fout.open(fileName.data(), ios::app);
    fout << word << " ";
    totalWordsInDict++;
    int index = ch - 'A';
    numOfWordsInFile[index]++;
    fout.close();
    return(Dictionary::success);
    }
}

bool Dictionary:: SearchForWord(string word)
{
  vector<string>content;
  string w;
  string fileName = "?.txt";
  char ch = toupper(word[0]);
  fileName[0] = ch;

  ifstream fin;
  fin.open(fileName.data()); //open file where word might be
  while(fin>>w)
    {
      content.push_back(w);                 //fill up array to check for doubles
    }
  fin.close();
   for(int i =0; i<content.size(); i++)
    {
            if(word == content[i])
	     {
	       return(Dictionary::failure); //if word is found
	     }          
    }
  return(Dictionary::success); //if word not found
}

bool Dictionary:: DeleteAWord(string word)
{
  bool ok = SearchForWord(word);
  if(ok==true)
    return(Dictionary::failure);
  else
    {
      vector<string>deletionV;          //deletion vector
      string w;
      string fileName = "?.txt";
      char ch = toupper(word[0]);
      fileName[0] = ch;

      ifstream fin;
      fin.open(fileName.data());

      while(fin>>w)
	{
	  deletionV.push_back(w);
	}
      fin.close();

      ofstream fout;
      fout.open(fileName.data());
      
      for(int x=0; x<deletionV.size(); x++)
	{
	  if(word == deletionV[x])        //if word found erase it from
            {                             //the vector
              deletionV[x] = " ";
            }
	  fout << deletionV[x] << " ";
	}
      fout.close();

      totalWordsInDict--;
      int index = ch - 'A';
      numOfWordsInFile[index]--;
      return(Dictionary::success);
    }

}

bool Dictionary:: PrintAFileInDict(string fileName)
{
  int wordsPerLine = 0;      //counter so that no more than 5 words per line
  vector<string>content;
  string w;

  ifstream fin;

  fin.open(fileName.data()); //open file where word might be

  if(!fin)
    return(Dictionary::failure);    //returns failure if file was not found
  else
    {
  while(fin>>w)
     {
      content.push_back(w);                 //fill up array to check for doubles
     }
  fin.close();
   for(int i =0; i<content.size(); i++)
     {
      cout << content[i] << " ";
      wordsPerLine++;
      if(wordsPerLine>4)
	{
	  cout << endl;
	  wordsPerLine = 0;
	}
     }
  cout << endl;
  return(Dictionary::success);
    }
}

bool Dictionary:: SpellChecking(string fileName)
{
  vector<string>content;
  string w;

  ifstream fin;

  fin.open(fileName.data()); //open file where word might be

  if(!fin)
    return(Dictionary::failure);    //returns failure if file was not found
  else
    {
        while(fin>>w)
	{
	  content.push_back(w);             
	}
      fin.close();
 
      for(int i =0; i<content.size(); i++)
	{
	  if(SearchForWord(content[i]) == success)    //if word was found cout message
	  cout << content[i] << " is not in the dictionary" << endl;
	}
      cout << endl;
      return(Dictionary::success);
    }
}

bool Dictionary:: InsertWordsIntoDict(string fileName)
{
  vector<string>content;
  string w;

  ifstream fin;
  fin.open(fileName.data()); //open file where word might be

  if(!fin)
    return(Dictionary::failure);    //returns failure if file was not found
  else
    {
      while(fin>>w)
        {
          content.push_back(w);
        }
      fin.close();

      for(int i =0; i<content.size(); i++)
	AddAWord(content[i]);     //calls add word function to insert word
    }                             //onw by one into the dictionary
       return(Dictionary::success);

}

void Dictionary:: ProcessTransactionFile()
{
  string userFile = "?.txt";
  string command="";
  string action="";

  cout << "Please enter a transactionfile: ";
  cin >> userFile;

  ifstream fin;
  fin.open(userFile.data());
  if(!fin)
    {
      cout << "File does not exist" << endl;
    }

  while(fin >> command)
    {
      if(command == "AddW")
	{
	  fin >> action;
	  AddAWord(action);
	}
      else if(command == "InsertF")
	{
	  fin >> action;
	  InsertWordsIntoDict(action);
	}
      else if(command == "PrintF")
	{
	  cout <<endl;
	  fin >> action;
	  PrintAFileInDict(action);
	}
      else if(command == "DeleteW")
	{
	  fin >> action;
	  DeleteAWord(action);
	}
      else if(command == "SpellCheck")
	{
	  cout <<endl;
	  fin >> action;
	  SpellChecking(action);
	}
      else  //if SearchW command
	{
	  fin >> action;
	  SearchForWord(action);
	}
    }
  fin.close();

}



#endif
