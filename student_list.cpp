#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Student struct
struct Student {
  char fname[80];
  char lname[80];
  int id;
  float gpa;

  // constructors
  Student () {}
  
  Student (char f[80], char l[80], int i, float g) {
    strcpy(fname, f);
    strcpy(lname, l);
    id = i;
    gpa = g;
  }
};

// functions
int checkInput (char input[80]);
/*
  0 = not a command
  1 = ADD
  2 = PRINT
  3 = DELETE
  4 = QUIT
*/

void printCmds ();

// main function
int main () {
  vector<Student*> slist;

  cout << "Beginning the Student List program." << endl;
  printCmds();

  bool isRunning = true;

  while (isRunning) {

    // input
    char input[80];
    cin.get(input, 80);
    cin.get();
    int cmd;
    while (checkInput(input) == 0) {
      cout << "Not a command. HELP for command list." << endl;
      if (input[0] == '\n') {
	cin.clear();
	cin.ignore();
      }
      cout << "Enter command:" << endl;
      cin.get(input, 80);
      cin.get();
    }

    // commands
    cmd = checkInput(input);

    if (cmd == 4) {
      isRunning = false;
    }

    else if (cmd == 3) { // DELETE
    }

    else if (cmd == 2) { // PRINT
      // referenced https://cplusplus.com/reference/vector/vector/begin/
      for (vector<Student*>::iterator it = slist.begin(); it != slist.end(); it++) {
	cout << (*it)->fname << " " << (*it)->lname << " -- ID: " << (*it)->id << " -- GPA: " << (*it)->gpa << endl;
      }
    }

    else if (cmd == 1) { // ADD
      char first[80], last[80];
      int id;
      float gpa;

      cout << "Student's first name?" << endl;
      cin.get(first, 80);
      cin.get();

      cout << "Student's last name?" << endl;
      cin.get(last, 80);
      cin.get();

      cout << "Student's ID number?" << endl;
      cin >> id;
      cin.get();

      cout << "Student's GPA?" << endl;
      cin >> gpa;
      cin.get();

      Student* s = & new Student(first, last, id, gpa);
      slist.push_back(s);
    }
    
    else {
      cout << "Unknown error occurred." << endl;
      isRunning = false;
    }
    
    
  } 
  
  return 0;
}

// functions
void printCmds () {
  cout << "Commands:\nADD (add student)\nPRINT (print student list)\nDELETE (delete student)\nQUIT (quit program)" << endl;
}

// parse move input
/*
  0 = bad input
  1 = ADD
  2 = PRINT
  3 = DELETE
  4 = QUIT
 */

int checkInput (char input[80]) {

  if (strcmp(input, "ADD") == 0) { return 1; }
  else if (strcmp(input, "PRINT") == 0) { return 2; }
  else if (strcmp(input, "DELETE") == 0) { return 3; }
  else if (strcmp(input, "QUIT") == 0) { return 4; }

  return 0;
}
