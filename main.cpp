#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;

int main(){
  queue<string> q,q2; // creates 2 queue objects
  stack<string> s; // creates stack object
  string answer; // determines if we pop item out of queue
  int tomtask = 0;//counts the number of tasks for the next day
  ifstream infile; // file name
  int sizeOfQueue;// variable size of queue
  infile.open("toDo.txt");//opens file

  cout << "Welcome to your to-do list. You have entered the following task: " << endl;

  if (infile.fail()){ //if the file is not open, the program will not run
    cout << "Text file does not work. Try again." << endl;
  }
  else{
    string str; // stores string into var "s"
    while(getline(infile, str)){ //reads each line from the file
      cout << str << endl;
      q.push(str); // pushes everything in the to do file into the queue
    }
  }
  sizeOfQueue = q.size();// sets queue size
  cout << "So you have " << sizeOfQueue << " things to do." << endl;
  for (int i = 0; i < sizeOfQueue; i++){//goes through queue
    cout << "Have you completed: " << q.front() << "?" << endl;
    cin >> answer;
    if ((answer == "Yes" )||(answer == "yes")){
      q.pop(); // takes item out of queue
    }
    else if((answer == "No" )||(answer == "no")){
      s.push(q.front());//pushes the top of the queue in the stacl
      q.pop();
    }
  }
  if(s.size() != 0){ //determines is the stack has at least 1 element
      cout << "These are the things you have left to do:" << endl;
      for(int j = 0; j < (s.size()+1); j++){
        q.push(s.top());// pushes the top of the stack into the queue
        cout << s.top() << endl;
        s.pop(); //takes top element out of stack
      }
      sizeOfQueue = q.size(); // re-intialize queue size
      cout << "Did you want to finish them?"<<endl;
      cin >> answer;
      if ((answer == "Yes" )||(answer == "yes")){
        cout << "So you have " << q.size() << " things to do." << endl;
        for (int i = 0; i < sizeOfQueue; i++){
          cout << "Have you completed: " << q.front() << "?" << endl;
          cin >> answer;
          if ((answer == "Yes" )||(answer == "yes")){
            q.pop(); 
          }
          else if((answer == "No" )||(answer == "no")){
            q.pop();
            tomtask++; //increment tomorrow's task
          }
        }
        cout << "You have to finish " << tomtask << " tasks tomorrow." << endl;
      }
    else{
      tomtask = q.size(); //sets tomorrow's task count to the queue size
      cout << "You have to finish " << tomtask << " tasks tomorrow." << endl;
    }
  }
  else{
    cout << "You did everything!" << endl;
  }
}
