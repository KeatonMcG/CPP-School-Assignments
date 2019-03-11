/*The purpose of this program is to either encrypt or a decrypt a document.  Encryption and decryption 
are performed by either a rotation method or a cryptogram method.  The user will input an encryption and
decryption key for the root method while the cryptogram method requires no additional inputs.  All
results of either encryption or decryption are sent to output files.


#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std;

void chooseEorD(char& choice, char& method);
vector<string>getwords();
string changeToLow(string w);
vector<string>EncryptRot(vector<string>words);
int getRotNumber();
vector<string>DecryptRot();
int getDecryptionNum();
void placeTheFile1(vector<string>encryptWordsUsingRot); // creates encrypt01.txt
void placeTheFile2(vector<string>decryptWordsUsingRot); // creates decrypt01.txt
vector<string>EncryptCrypto(vector<string>words);
vector<string>DecryptCrypto();
void placeTheFile3(vector<string>encryptWordsUsingCrypto); // creates encrypt02.txt
void placeTheFile4(vector<string>decryptWordsUsingCrypto); // creates decrypt02.txt

int main()
{
  char choice, method;
  vector<string>words = getwords();
  chooseEorD(choice, method);
  if(choice == 'e')
    {
      if(method == 'r')
	{
	  vector<string>encryptWordsUsingRot = EncryptRot(words);
	  placeTheFile1(encryptWordsUsingRot);
	}
      else
	{
	  vector<string>encryptWordsUsingCrypto = EncryptCrypto(words);
	  placeTheFile3(encryptWordsUsingCrypto);
	}
    }
  else
    {
      if(method == 'r')
        {
	  vector<string>decryptWordsUsingRot = DecryptRot();
	  placeTheFile2(decryptWordsUsingRot);
	}
      else
	{
      	  vector<string>decryptWordsUsingCrypto = DecryptCrypto();
	  placeTheFile4(decryptWordsUsingCrypto);
	}
    }
  return 0;
}

void chooseEorD(char& choice, char& method)  // determines if user wants to encrypt or decrypt and what 
                                            // method to use
{
  cout << "Would you like to perform encryption or decryption(please enter e or d): ";
  cin >> choice;
  while(choice != 'e' && choice != 'd')
    {
      cout << "\nInvalid choice (please enter e or d): ";
      cin >> choice;
    }

  cout << "\nWould you like to use the rot or cryptogram method(please enter r or c): ";
  cin >> method;
  while(method != 'r' && method != 'c')
    {
      cout << "\nInvalid choice (please enter r or c): ";
      cin >> method;
    }
}

vector<string>getwords() // moves info from file into a vector called words
{
  vector<string>words;
  string w;
  ifstream fin;
  fin.open("original.txt");
  while(fin>>w)
    {
      w = changeToLow(w);
      words.push_back(w);
    }
  return words;
}

string changeToLow(string w) // chabges all uppercase letters from the original file to lowercase
{
  for(int i = 0; i < w.size(); i++)
    w[i] = tolower(w[i]);

  return w;
}

vector<string>EncryptRot(vector<string>words)
{
  vector<string>v;
  int rotNum = getRotNumber();
  string iword;
  int letter;
    for(int i=0; i<words.size(); i++)
    {
      iword = words[i];
      for(int x=0; x<iword.size(); x++)
	{
	  letter = iword[x];
	  if(iword[x] >= 97 && iword[x] <= 122)
	    {
	      letter = letter + rotNum; //adds rotNum to shift character that many spaces
	    }
	  if(letter > 122)
	    {
	    letter = letter - 26;
	    }
	  iword[x]=letter;
 	}
       v.push_back(iword);   
     }
    cout << endl;
  return v;
}  

int getRotNumber()
{
  int num;
  cout << "For the encryption key please enter a number between 0 and 25: ";
  cin >> num;
  while(num > 25 || num < 0)
    {
  if(num > 25 )
    cout << "\nThe number you entered is too big. Please enter another number: ";
  else if(num < 0)
    cout << "\nThe number you entered is too small. Please enter another number: ";
  else{
      }
  cin >> num;
    }
  return num;
}

vector<string> DecryptRot()
{
  vector<string>v;
  int rotNum = getDecryptionNum();
  string iword;
  int letter;

  vector<string>temp;       //temporary vector that moves words from encrypted file
  string m, eword;          // so that they can be decrypted
  ifstream fin;
  fin.open("encrypt01.txt"); 
  while(fin >> m)
    {
      temp.push_back(m);
    }
  for(int i=0; i<temp.size(); i++)
     {
      iword = temp[i];
      for(int x=0; x<iword.size(); x++)
        {
          letter = iword[x];
	  if(letter < 97)
            {
             iword[x]=letter;
            }
	  else
	    {
             if(iword[x] >= 97 && iword[x] <= 122)
              {
	       letter = letter - rotNum;
              }
             if(letter < 97)
              {
	       letter = letter + 26;
              }
          iword[x]=letter;
            }
	}
      v.push_back(iword);
     }
  return v;
}

int getDecryptionNum()
{
  int num;
  cout << "For the decryption key please enter a number between 0 and 25: ";
  cin >> num;
  while(num > 25 || num < 0)
    {
      if(num > 25 )
	cout << "\nThe number you entered is too big. Please enter another number: ";
      else if(num < 0)
	cout << "\nThe number you entered is too small. Please enter another number: ";
      else{
      }
      cin >> num;
    }
  return num;
}

void placeTheFile1(vector<string>encryptWordsUsingRot)
{
  ofstream  fout;
  fout.open("encrypt01.txt");
  for(int i=0; i< encryptWordsUsingRot.size(); i++)
    {
     fout << encryptWordsUsingRot[i] << " ";
    }
  fout.close(); 
}

void placeTheFile2(vector<string>decryptWordsUsingRot)
{
  ofstream  fout;
  fout.open("decrypt01.txt");
  for(int i=0; i< decryptWordsUsingRot.size(); i++)
    {
      fout << decryptWordsUsingRot[i] << " ";
    }
  fout.close();
}


vector<string>EncryptCrypto(vector<string>words)
{
  vector<string>v;
  string iword;
  char letter;
  char index;
  string w;

  ifstream fin;
  fin.open("key.txt");
  while(fin>>w)
    {
  for(int i=0; i<words.size(); i++)
     {
      iword = words[i];
      for(int x=0; x<iword.size(); x++)
        {
          letter = iword[x];
          if(letter < 'a' || letter > 'z') // for non letter characters
            {
	      iword[x] = letter;
            }
          else
            {
	      index = letter - 'a'; // determines which character iword[x] will recieve 
	      iword[x] = w[index];
            }
	}
      v.push_back(iword);
     }
    }
  return v;
}

vector<string>DecryptCrypto()
{
  vector<string>v;
  string iword;
  char letter;
  string w;
  
  vector<string>temp;             //temporary vector that moves words from encrypted file
  string m, eword;                // so that they can be decrypted
  ifstream infile;
  infile.open("encrypt02.txt");
  while(infile >> m)
    {
      temp.push_back(m);
    }

  ifstream fin;
  fin.open("key.txt");
  while(fin>>w)
    {
      for(int i=0; i<temp.size(); i++)
	{
	  iword = temp[i];
	  for(int x=0; x<iword.size(); x++)
	    {
	      letter = iword[x];
	      if(letter < 'a' || letter > 'z')
		{
		  iword[x] = letter;
		}
	      else
		{
		  for(int z=0; z < 26; z++)
		    {
		      if(letter == w[z]) // searches for the matching character then converts
			{                // it back to the original message
			  iword[x] = z + 'a';
			}
		    }
		}
	    }
	      v.push_back(iword);
	}
    }
  return v;
}

void placeTheFile3(vector<string>encryptWordsUsingCrypto)
{
  ofstream  fout;
  fout.open("encrypt02.txt");
  for(int i=0; i< encryptWordsUsingCrypto.size(); i++)
    {
      fout << encryptWordsUsingCrypto[i] << " ";
    }
  fout.close();
}

void placeTheFile4(vector<string>decryptWordsUsingCrypto)
{
  ofstream  fout;
  fout.open("decrypt02.txt");
  for(int i=0; i< decryptWordsUsingCrypto.size(); i++)
    {
      fout << decryptWordsUsingCrypto[i] << " ";
    }
  fout.close();
}
