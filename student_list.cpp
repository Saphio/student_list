#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

// Student struct
struct Student {
  char fname[80];
  char lname[80];
  int id;
  float gpa;
};

// function prototypes
int checkInput (char input[80]);
void printCmds ();
void add (vector<Student*> &slist); 
void remove (vector<Student*> &slist);
void display (vector<Student*> slist); 
void quit (bool &status);

// main function
int main () {
  vector<Student*> slist;

  cout << "Beginning the Student List program." << endl;

  bool isRunning = true;

  while (isRunning) {
    printCmds ();

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

    if (cmd == 4) { // QUIT
      quit (isRunning);
    }

    else if (cmd == 3) { // DELETE
      remove (slist);
    }

    else if (cmd == 2) { // PRINT
      display (slist);
    }

    else if (cmd == 1) { // ADD
      add (slist);
    }
    
    else {
      cout << "Unknown error occurred." << endl;
      isRunning = false;
    }
  } 
  return 0;
}

// functions
// print commands
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

// primary methods
// 1: ADD
void add (vector<Student*> &slist) {
  char first[80], last[80];
  int id;
  float gpa;
  
  // prompt for information
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
  
  // add to vector
  Student* s = new Student();
  slist.push_back(s);
      
  strcpy(s->fname, first);
  strcpy(s->lname, last);
  s->id = id;
  s->gpa = gpa;
  return;
}

// 2: PRINT
void display (vector<Student*> slist) { 
  // referenced https://cplusplus.com/reference/vector/vector/begin/
  for (vector<Student*>::iterator it = slist.begin(); it != slist.end(); it++) {
    cout << (*it)->fname << " " << (*it)->lname << " -- ID: " << (*it)->id;
    cout << " -- GPA: " << fixed << setprecision(2) << (*it)->gpa << endl;
  }
  return;
}

// 3: DELETE
void remove (vector<Student*> &slist) {
  cout << "ID number of student to be deleted?" << endl;
  int num;
  cin >> num;
  cin.get();

  int index = 0;
  bool deleted = false;

  // iterate through vector to find the right student
  vector<Student*>::iterator it = slist.begin();

  // before I moved this to another method, this could have just been a for loop with a return statement
  // sad. :(
  while ((!deleted) && (it != slist.end())) {
    if ((*it)->id == num) {
      // delete the data and erase from the vector
      delete slist.at(index);
      cout << "Data deleted" << endl;
      slist.erase(slist.begin() + index);
      cout << "Removed from struct" << endl;
      deleted = true;
    }
    index++;
    it++;
  }

  // for user purposes
  if (!deleted) {
    cout << "We couldn't find that student." << endl;
  }
  else {
    cout << "Poof! They're gone." << endl;
  }
  return;
}

// 4: QUIT
void quit (bool &status) {
  cout << "Sorry to see you go." << endl;
  status = false;
  return;
}
