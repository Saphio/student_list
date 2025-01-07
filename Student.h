#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>

using namespace std;

class Student {
 public:
  Student();
  Student(char*, int, float);
  ~Student();
  char* getName();
  int getGrade();
  float getGPA();
  void display();
 private:
  char* name;
  int grade;
  float gpa;
};

#endif
