#ifndef University_H
#define University_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class University
{

 protected:
  vector<Department> Departments;
  vector<Student> Students;
  vector<Course> Courses;
  vector<Faculty> Faculties;
  static bool failure;
  static bool success;

 public:
  University();
  ~University();

  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
  bool RemoveADepartment(long depId);
  bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  //bool RemoveAStudent(long sStId);
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  //bool RemoveACourse(long cCRN);
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  bool RemoveAFaculty(long fFactId);
  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListFacultiesInDepartment (long departId);
  bool ListStudentsOfAFaculty(long facultyId);
  bool ListCoursesOfADepartment(long departId);
  bool AddACourseForAStudent(long courseId, long stId);
  //bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);
  bool AssignInstructorToCourse (long facultyId, long courseId);
  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFaculties();

  bool checkDeptExists(long depChairId);
  bool checkStudentExists(string sMajor);
  bool checkCourseExists(long cTaughtBy);
  bool checkFacultyExists(long fDepId);
  bool checkFacultyIdValidity(long fFactId); 
  bool ProcessTransactionFile(string fileName);
  bool checkStudentIdValidity(long studentId);
  bool checkDepartmentIdValidity(long departId);
  bool checkCourseIdValidity(long courseId);

};
#endif
