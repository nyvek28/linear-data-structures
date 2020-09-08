#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
#include <string>
#include "Node.h"

using namespace std;

class DataStructure {
  private:
    Node* head;
    int length;

  public:
    DataStructure();
    Node* createNode(int, Node*);
    string toString();
    Node* getHead() { return head; };
    void setHead(Node* newHead) { head = newHead; };
    int getLength() { return length; };
    void increaseLength() { length = length + 1; };
    void decreaseLength() { length = length - 1; };
    int peek() { return head->data; };
    bool isEmpty() { return length == 0; };
};

#endif