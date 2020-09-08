#ifndef STACK_H
#define STACK_H
#include <string>
#include "DataStructure.h"

using namespace std;

class Stack {
  private:
    DataStructure* ds;
  public:
    Stack();
    void push(int);
    int pop();
    int peek() { return ds->peek(); };
    string toString() { return ds->toString(); };
    bool isEmpty() { return ds->isEmpty(); };
};

#endif