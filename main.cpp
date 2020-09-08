#include <iostream>
#include <string>

using namespace std;



// Node

class Node {
  public:
    Node* next;
    int data;
    int index;
    void setNext(Node* nextNode) { next = nextNode; };

    Node(Node* nextNode, int nodeData, int nodeIndex) {
      next = nextNode;
      data = nodeData;
      index = nodeIndex;
    }
};



// Data Structure

class DataStructure {
  private:
    Node* head;
    int length;

  public:
    DataStructure() {
      head = NULL;
      length = 0;
    }
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

Node* DataStructure::createNode(int data, Node* nodeNext) {
  Node* newNode = new Node(nodeNext, data, length);
  return newNode;
}

string DataStructure::toString() {
  Node* currentNode = head;
  string output = "";
  while(currentNode != NULL) {
    output = output + to_string(currentNode->index) + ": [" + to_string(currentNode->data) + "]\n";
    currentNode = currentNode->next;
  }
  return output;
}



// Stack

class Stack {
  private:
    DataStructure* ds;
  public:
    Stack() {
      ds = new DataStructure();
    }
    void push(int);
    int pop();
    int peek() { return ds->peek(); };
    string toString() { return ds->toString(); };
    bool isEmpty() { return ds->isEmpty(); };
};

void Stack::push(int data) {
  Node* head = ds->getHead();
  Node* newNode = ds->createNode(data, head);
  ds->setHead(newNode);
  ds->increaseLength();
};

int Stack::pop() {
  Node* deletedNode = ds->getHead();
  if (deletedNode == NULL) { return NULL; }
  int returnData = deletedNode->data;
  ds->setHead(deletedNode->next);
  ds->decreaseLength();
  delete deletedNode;
  return returnData;
  
}



// Queue

class Queue {
  private:
    DataStructure* ds;
  
  public:
    Queue() {
      ds = new DataStructure();
    }
    void add(int);
    int poll();
    int peek() { return ds->peek(); };
    string toString() { return ds->toString(); };
    bool isEmpty() { return ds->isEmpty(); };
};

void Queue::add(int data) {
  Node* newNode = ds->createNode(data, NULL);
  Node* currentNode = ds->getHead();
  if(currentNode == NULL) {
    ds->setHead(newNode);
  } else {
    while(currentNode->next != NULL) {
      currentNode = currentNode->next;
    }
    currentNode->setNext(newNode);
  }
  ds->increaseLength();
}

int Queue::poll() {
  Node* deletedNode = ds->getHead();
  int returnData;
  if(deletedNode == NULL) { 
    returnData = NULL; 
  } else {
    returnData = deletedNode->data;
    if(deletedNode->next == NULL) { 
      ds->setHead(NULL); 
    } else {
      ds->setHead(deletedNode->next);
    }
    delete deletedNode;
  }
  ds->decreaseLength();
  return returnData;
}



// UI

void print(string message) {
  cout << message << endl;
}

int read(string message) {
  int number;
  print(message);
  cin >> number;
  return number;
}

int main() {
  print("Stack");
  Stack* stack = new Stack();
  stack->push(4);
  stack->push(5);
  stack->push(8);
  print(stack->toString());
  stack->pop();
  print(stack->toString());
  stack->push(56);
  stack->push(11);
  print(stack->toString());
  print("Peek: " + to_string(stack->peek()));
  print("Queue");
  Queue* queue = new Queue();
  queue->add(4);
  queue->add(5);
  queue->add(8);
  print(queue->toString());
  queue->poll();
  print(queue->toString());
  queue->add(56);
  queue->add(11);
  print(queue->toString());
  print("Peek: " + to_string(queue->peek()));
}