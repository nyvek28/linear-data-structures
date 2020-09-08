#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include "DataStructure.h"

using namespace std;

class Queue {
  private:
    DataStructure* ds;
  
  public:
    Queue();
    void add(int);
    int poll();
    void updateIndexes();
    int peek() { return ds->peek(); };
    string toString() { return ds->toString(); };
    bool isEmpty() { return ds->isEmpty(); };
};

#endif