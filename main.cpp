#include <iostream>
#include <string>
#include "Node.h"
#include "DataStructure.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

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
  Stack* stack = new Stack();
  Queue* queue = new Queue();

  print("Stack");
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