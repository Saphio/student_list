#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

// constructor/destructor

Student::Student() {
  strcpy(name, new char[80]);
  grade = 0;
  gpa = 0.0;
}

// normal constructor; pass in name, grade, gpa
Student::Student(char* n, int g, float a) {
  name = new char[80];
  strcpy(name, n);
  grade = g;
  gpa = a;
}

// destructor
Student::~Student() {
  delete name;
}

// getters
// get name
char* Student::getName () {
  return name;
}

// get grade
int Student::getGrade() {
  return grade;
}

// get gpa
float Student::getGPA() {
  return gpa;
}

// display student information
void Student::display() {
  cout << name << " -- grade: " << grade << " -- gpa: " << gpa << endl;
  return;
}
