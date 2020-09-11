#include <iostream>
#include <string>
#include "Node.h"
#include "DataStructure.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

Stack* stack = new Stack();
Queue* queue = new Queue();

void print(string message) {
  cout << message << endl;
}

void blankLine() {
  cout << endl;
}

void singleLine(string message) {
  blankLine();
  print(message);
  blankLine();
}

int read(string message) {
  int number;
  print(message);
  cin >> number;
  return number;
}

int readOption() {
  return read("Select an option:");
}

int readNumber() {
  return read("Enter a number:");
}

int displayMainMenu() {
  int selection = 0;
  bool isInputValid = false;

  do {
    blankLine();
    print("Main Menu");
    print("1. Add");
    print("2. Modify");
    print("3. Show");
    print("4. Show All");
    print("5. Exit");
    blankLine();
    selection = readOption();
    if(selection > 0 && selection <= 5) {
      isInputValid = true;
    } else {
      singleLine("Invalid Input!");
    }
  } while (!isInputValid);

  return selection;
}

int displayDataStructuresMenu() {
  int selection = 0;
  bool isInputValid = false;

  do {
    blankLine();
    print("Data Structure Menu");
    print("1. Stack");
    print("2. Queue");
    print("3. Exit");
    blankLine();
    selection = readOption();
    if(selection > 0 && selection <= 3) {
      isInputValid = true;
    } else {
      singleLine("Invalid Input!");
    }
  } while (!isInputValid);

  return selection;
}

void add() {
  int selection = displayDataStructuresMenu();
  int input = 0;
  switch (selection) {
  case 1:
    input = readNumber();
    singleLine("Adding " + to_string(input) + " to Stack");
    stack->push(input);
    singleLine(stack->toString());
    break;
  case 2:
    input = readNumber();
    singleLine("Adding " + to_string(input) + " to Queue");
    queue->add(input);
    singleLine(queue->toString());
    break;
  default:
    break;
  }
}

int displayModifyMenu() {
  int selection = 0;
  bool isInputValid = false;

  do {
    blankLine();
    print("Modify Menu");
    print("1. Stack to Queue");
    print("2. Queue to Stack");
    print("3. Exit");
    blankLine();
    selection = readOption();
    if(selection > 0 && selection <= 3) {
      isInputValid = true;
    } else {
      singleLine("Invalid Input!");
    }
  } while (!isInputValid);

  return selection;
}

void modify() {
  int selection = displayModifyMenu();
  int input = 0;
  switch (selection) {
  case 1:
    if(stack->isEmpty()) {
      singleLine("Stack is empty, can't modify");
    } else {
      singleLine("Moving " + to_string(stack->peek()) + " from Stack to Queue");
      queue->add(stack->pop());
    } 
    break;
  case 2:
    if(queue->isEmpty()) {
      singleLine("Queue is empty, can't modify");
    } else {
      singleLine("Moving " + to_string(queue->peek()) + " from Queue to Stack");
      stack->push(queue->poll());
    }
    break;
  default:
    break;
  }
}

void show() {
  int selection = displayDataStructuresMenu();
  int input = 0;
  switch (selection) {
  case 1:
    blankLine();
    print("Stack:");
    print(stack->toString());
    break;
  case 2:
    blankLine();
    print("Queue:");
    print(queue->toString());
    break;
  default:
    break;
  }
}

void showAll() {
  blankLine();
  print("Stack:");
  print(stack->toString());
  blankLine();
  print("Queue:");
  print(queue->toString());
}

int main() {
  bool isAppRunning = true;
  int selection = 0;

  do {
    selection = displayMainMenu();
    switch(selection) {
      case 1:
        add();
        break;
      case 2:
        modify();
        break;
      case 3:
        show();
        break;
      case 4:
        showAll();
        break;
      default:
        singleLine("Bye!");
        isAppRunning = false;
        break;
    }
  } while(isAppRunning);

  return 0;
}