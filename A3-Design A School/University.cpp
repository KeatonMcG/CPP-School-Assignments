#ifndef University_C
#define University_C
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


bool University:: failure = false;
bool University:: success = true;

University :: University()
{

}

University :: ~University()
{

}

bool University :: CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  if(depChairId != 0)
    {
      bool valid = checkDeptExists(depChairId);  // passes chair Id to a check function
      if(valid == false)
	{
	  cout << "\nSorry department chair " << depChairId << " isnt a valid faculty" << endl; //depChairId error message
        return failure;
	}
    }
  else
    {
  Department D1(depName, depLoc, depChairId);
  Departments.push_back(D1);

  return success;
    }
}

bool University :: checkDeptExists(long depChairId)
{
  for(int i = 0; i < Faculties.size(); i++)
    {

      if(depChairId == Faculties[i].Id)
        return success;
    }
  return failure;
}
//-------------------------------------------------------------------------------------
bool University :: CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  if(sMajor != " ")
    {
      bool valid = checkStudentExists(sMajor);  //passes major to a check function
      if(valid == false)
        {
          cout << "\nSorry students major isn't a valid major" << endl; //sMajor error message
	  return failure;
        }
    }
  Student S1(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
  Students.push_back(S1);

  return success;
}

bool University :: checkStudentExists(string sMajor)
{
  for(int i = 0; i < Departments.size(); i++)
    {

      if(sMajor == Departments[i].Name)
        return success;
    }

  return failure;
}
//-------------------------------------------------------------------------------
bool University :: CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  if(cTaughtBy != 0)
    {
      bool valid = checkCourseExists(cTaughtBy);  // passes taught by to check function
      if(valid == false)
        {
          cout << "\nSorry " << cTaughtBy << " isn't a valid Course Number" << endl; //cTaughtBy error message
	  return failure;
        }
    }
  Course C1(cName, cDepId, cTaughtBy, cMaxSeat);
  Courses.push_back(C1);

  return success;
}

bool University :: checkCourseExists(long cTaughtBy)
{
  for(int i = 0; i < Faculties.size(); i++)
    {

      if(cTaughtBy == Faculties[i].Id)
        return success;
    }

  return failure;
}
//-------------------------------------------------------------------------------
bool University :: CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
  if(fDepId != 0)
    {
      bool valid = checkFacultyExists(fDepId);  //passes faculty id to a check function
      if(valid == false)
        {
          cout << "\nSorry departmentID " << fDepId << " isn't valid" << endl; //cTaughtBy error message
          return failure;
        }
    }
  Faculty F1(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);
  Faculties.push_back(F1);

  return success;
}

bool University :: checkFacultyExists(long fDepId)
{
  for(int i = 0; i < Departments.size(); i++)
    {

      if(fDepId == Departments[i].Id)
        return success;
    }
  return failure;

}
//---------------------------------------------------------------------------
bool University :: ListCoursesTaughtByFaculty(long fFactId)
{
  bool valid = checkFacultyIdValidity(fFactId);
  if(valid == false)
    {
      cout << "Sorry " << fFactId << " isnt a valid faculty Id" << endl; // error message
      return failure;
    }

  cout << "Courses taught by Faculty Id " << fFactId << ":" << endl;  //header for outputs

    for(int i = 0; i < Courses.size(); i++)
      {
	if(fFactId == Courses[i].IsTaughtBy)                            
	  {  
        cout << "Course ID: " << Courses[i].CRN << endl;
        cout << "Course Name: " << Courses[i].Name << endl;
	  }
      }
    return success;
}

bool University :: checkFacultyIdValidity(long fFactId)
{
  for(int i = 0; i < Faculties.size(); i++)
    {
      if(fFactId == Faculties[i].Id)
	return success;
    }
  return failure;
} 
//----------------------------------------------------------------------------
bool University::ListCoursesTakenByStudent(long studentId)
{
  bool valid = checkStudentIdValidity(studentId);
  if(valid == false)
    {
      cout << "\nStudent " << studentId << " isn't a valid student ID" << endl; // error message
      return failure;
    }

  for(int i = 0; i < Courses.size(); i++)
    {
      if(studentId == Courses[i].IsTaughtBy)
	{
	  cout << "Course ID: " << Courses[i].CRN << endl;
	  cout << "Course Name: " << Courses[i].Name << endl;
	}
    }
  return success;
}

bool University :: checkStudentIdValidity(long studentId)
{
  for(int i = 0; i < Students.size(); i++)
    {
      if(studentId == Students[i].Id)
        return success;
    }
  return failure;
}
//----------------------------------------------------------------------------
bool University::ListFacultiesInDepartment (long departId)
{
  bool valid = checkDepartmentIdValidity(departId);
  if(valid == false)
    {
      cout  << departId << " isn't a valid department ID" << endl; // error message
      return failure;
    }

  cout << "Faculties from department: " << departId << ":" <<endl; //header for the outputs

  for(int i = 0; i < Faculties.size(); i++)
    {
      if(departId == Faculties[i].DepartId)
        {
          cout << "Faculty ID: " << Faculties[i].Id << endl;
          cout << "Faculty Name: " << Faculties[i].Name << endl;
        }
    }
  return success;
}

bool University:: checkDepartmentIdValidity(long departId)
{
  for(int i = 0; i < Departments.size(); i++)
    {
      if(departId == Departments[i].Id)
        return success;
    }
  return failure;
}
//----------------------------------------------------------------------------
bool University:: ListStudentsOfAFaculty(long facultyId)
{
  bool valid = checkFacultyIdValidity(facultyId);
  if(valid == false)
    {
      cout  << facultyId << " isn't a valid faculty ID" << endl; // error message
      return failure;
    }

  cout << "Students of Faculty  " << facultyId << ":" <<endl; // header for the outputs

  for(int i = 0; i < Students.size(); i++)
    {
      if(facultyId == Students[i].AdvisorId)
        {
          cout << "Student ID: " << Students[i].Id << endl;
          cout << "Student Name: " << Students[i].Name << endl;
        }
    }
  return success;
}
//----------------------------------------------------------------------------
bool University::ListCoursesOfADepartment(long departId)
{
  bool valid = checkDepartmentIdValidity(departId);
  if(valid == false)
    {
      cout  << departId << " isn't a valid department ID" << endl; // error message
      return failure;
    }

  cout << "Courses in Department  " << departId << ":" <<endl;

  for(int i = 0; i < Courses.size(); i++)
    {
      if(departId == Courses[i].DepartId)
        {
          cout << "Course ID: " << Courses[i].CRN << endl;
          cout << "Course Name: " << Courses[i].Name << endl;
        }
    }
  return success;

}

//---------------------------------------------------------------------------- 
bool University :: AddACourseForAStudent(long courseId, long stId)
{/*
  bool valid = checkStudentIdValidity(stId);
  if(valid == false)
    {
      cout << "\nStudent " << stId << " isn't a valid student ID" << endl; // error message
      return failure;
    }
  bool check = checkCourseIdValidity(courseId);
  if(valid == false)
    {
      cout << "\nCourse " << courseId << " isn't a valid course ID" << endl; // error message
      return failure;
    }
  else
    {
      for(int i = 0; i < Courses.size(); i++)
	{
	  if(Courses[i].AssignedSeats < Courses[i].MaxAvailableSeats) //makes sure there are enough seats
	    {
	      Courses[i].AssignedSeats++;
	      CoursesTaken.push_back(Courses[i].courseId);
	    }
	}
	}*/
    return success;
}
//----------------------------------------------------------------------------

bool University :: checkCourseIdValidity(long courseId)
{
  for(int i = 0; i < Courses.size(); i++)
    {
      if(courseId == Courses[i].CRN)
        return success;
    }
  return failure;
  }
//----------------------------------------------------------------------------

  bool University :: AssignDepartmentChair(long facultyId, long departId)
{
  bool valid = checkFacultyIdValidity(facultyId);
  if(valid == false)
    {
      cout << "\nFaculty " << facultyId << " isn't a valid faculty ID" << endl; // error message
      return failure;
    }
  bool check = checkDepartmentIdValidity(departId);
  if(check == false)
    {
      cout  << "\nDepartment " << departId << " isn't a valid department ID" << endl; // error message
      return failure;
    }

  for(int i = 0; Departments.size(); i++)
    {
      if(departId == Departments[i].Id)
	{
	  Departments[i].ChairId = facultyId;
	  cout << "The new chair of department " << departId << " is " << facultyId << endl;
	  return success;
	}
    }
}
//----------------------------------------------------------------------------
bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
  bool valid = checkFacultyIdValidity(facultyId);
  if(valid == false)
    {
      cout << "\nFaculty " << facultyId << " isn't a valid faculty ID" << endl; // error message
      return failure;
    }
  bool check = checkCourseIdValidity(courseId);
  if(check == false)
    {
      cout << "\nCourse " << courseId << " isn't a valid course ID" << endl; // error message
      return failure;
    }
  for( int i = 0; i < Courses.size(); i++)
    {
      if(courseId == Courses[i].CRN)
	{
	  Courses[i].IsTaughtBy = facultyId;
	  cout << courseId << " is now taught by faculty member " << facultyId << endl;
	  return success;
	}
    }
}

//----------------------------------------------------------------------------
bool University :: ListDepartments()
{
  cout << "Department List: " << endl;
  for(int i = 0; i < Departments.size(); i++)
    {
      cout << "Department ID: " << Departments[i].Id << endl;
      cout << "Department Name: " << Departments[i].Name << endl;
    }
  return success;
}
//----------------------------------------------------------------------------
bool University :: ListStudents()
{
  cout << "Student List: " << endl;
  for(int i = 0; i < Students.size(); i++)
    {
      cout << "Student ID: " << Students[i].Id << endl;
      cout << "Student Name: " << Students[i].Name << endl;
    }
  return success;
}
//----------------------------------------------------------------------------
  bool University :: ListCourses()
  {
    cout << "Course List: " << endl;
    for(int i = 0; i < Courses.size(); i++)
      {
	cout << "Course ID: " << Courses[i].CRN << endl;
	cout << "Course Name: " << Courses[i].Name << endl;
      }
    return success;
  }
//----------------------------------------------------------------------------
    bool University :: ListFaculties()
    {
      cout << "Faculty List: " << endl;
      for(int i = 0; i < Faculties.size(); i++)
	{
	  cout << "Faculty ID: " << Faculties[i].Id << endl;
	  cout << "Faculty Name: " << Faculties[i].Name << endl;
	}
      return success;
    }
//----------------------------------------------------------------------------
bool University::RemoveADepartment(long depId)
{
  string dName;
  bool check = checkDepartmentIdValidity(depId);
  if(check == false)
    {
      cout  << "\nDepartment " << depId << " isn't a valid department ID" << endl; // error message
      return failure;
    }

  for(int i = 0; i < Faculties.size(); i++) //checks if department has faculty
    {
      if(Faculties[i].DepartId == depId)
	{
	  return failure;
	}
    }
  for(int x = 0; x < Courses.size(); x++) //checks if department has courses
    {
      if(Courses[x].DepartId == depId)
        {
          return failure;
        }
    }
  for(int y = 0; y < Departments.size(); y++) // retrieves department name that matches the Id
    {
      if(Departments[y].Id == depId)
	{
	  dName = Departments[y].Name;
	}
    }
  for(int z = 0; z < Students.size(); z++) // makes sure no stduents major matches the dName
    {
      if(dName == Students[z].Major)
	{
	return failure;
	}
    }
  for(int j = 0; j < Departments.size(); j++) // removes the department from the vector
    {
      if(Departments[j].Id == depId)
	{
	  Departments.erase(Departments.begin()+ j);
	}
    }
  return success;
}
//----------------------------------------------------------------------------
bool University::RemoveAFaculty(long fFactId)
{
  bool valid = checkFacultyIdValidity(fFactId);
  if(valid == false)
    {
      cout << "\nFaculty " << fFactId << " isn't a valid faculty ID" << endl; // error message
      return failure;
    }
  for(int x = 0; x < Courses.size(); x++) // makes sure faculty isnt teaching any courses
    {
      if(Courses[x].IsTaughtBy == fFactId)
        {
          return failure;
        }
    }
  for(int z = 0; z < Students.size(); z++) // makes sure faculty isnt advising any students
    {
      if(Students[z].AdvisorId == fFactId)
        {
	  return failure;
        }
    }
  for(int y = 0; y < Departments.size(); y++) // makes sure no department chair matches the fFactId
    {
      if(Departments[y].ChairId == fFactId)
        {
          return failure;
        }
    }
  for(int j = 0; j < Faculties.size(); j++) // erases the faculty from the vector
    {
      if(Faculties[j].Id == fFactId)
	{
	  Faculties.erase(Faculties.begin()+ j);
	}
    }
  return success;
}
//----------------------------------------------------------------------------
bool University::ProcessTransactionFile (string fileName)
{
  string command = "";
  string s1, s2, s3, s4, s5, s6;
  int i1, i2;
  long L1, L2, L3;
  float f1;

  ifstream fin;
  fin.open(fileName.data());

  while(fin >> command)
    {
    if(command == "CreateNewDepartment")
      {
	fin >>s1 >>s2 >> L1;
	CreateNewDepartment(s1, s2, L1);
      }
    else if(command == "CreateNewStudent")
      {
	fin >> s1>> s2>> s3>> s4>> s5>> i1>> s6 >>L1;
	CreateNewStudent(s1, s2, s3, s4, s5, i1, s6, L1);
      }
    else if(command == "CreateNewCourse")
      {
	fin >>s1>> L1>> L2>> i1;
	CreateNewCourse(s1, L1, L2, i1);
      }
    else if(command == "CreateNewFaculty")
      {
        fin >> s1>> s2>> s3>> s4>> s5>> f1>> i1 >>L1;
        CreateNewFaculty(s1, s2, s3, s4, s5, f1, i1, L1);
      }
    else if(command == "ListCoursesTaughtByFaculty")
      {
	cout << endl;
	fin >> L1;
	ListCoursesTaughtByFaculty(L1);
      }
    else if(command == "ListCoursesTakenByStudent")
      {
        cout << endl;
        fin >> L1;
        ListCoursesTakenByStudent(L1);
      }
    else if(command == "ListFacultiesInDepartment")
      {
        cout << endl;
        fin >> L1;
        ListFacultiesInDepartment(L1);
      }
    else if(command == "ListStudentsOfAFaculty")
      {
        cout << endl;
        fin >> L1;
        ListStudentsOfAFaculty(L1);
      }
    else if(command == "ListCoursesOfADepartment")
      {
        cout << endl;
        fin >> L1;
        ListCoursesOfADepartment(L1);
      }
    else if(command == "AddACourseForAStudent")
      {
        cout << endl;
        fin >> L1 >> L2;
        AddACourseForAStudent(L1, L2);
      }/*
    else if(command == "DropACourseForAStudent")
      {
        cout << endl;
        fin >> L1 >> L2;
        DropACourseForAStudent(L1, L2);
	}*/
    else if(command == "AssignDepartmentChair")
      {
        cout << endl;
        fin >> L1 >> L2;
        AssignDepartmentChair(L1, L2);
      }
    else if(command == "AssignInstructorToCourse")
      {
        cout << endl;
        fin >> L1 >> L2;
        AssignInstructorToCourse(L1, L2);
	} 
    else if(command == "ListDepartments")
      {
	 ListDepartments();
      }
    else if(command == "ListStudents")
      {
        cout << endl;
        ListStudents();
      }
    else if(command == "ListCourses")
      {
        cout << endl;
        ListCourses();
      }
    else if(command == "RemoveADepartment")
      {
        cout << endl;
        fin >> L1;
        RemoveADepartment(L1);
      }
    else if(command == "RemoveAFaculty")
      {
        cout << endl;
        fin >> L1;
        RemoveAFaculty(L1);
      }

    else
      {
        cout <<  endl;
        ListFaculties();
      }
    }
  fin.close();    
}
#endif
