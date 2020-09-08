#include <string>
#include "DataStructure.h"
#include "Node.h"

using namespace std;

DataStructure::DataStructure() {
  head = NULL;
  length = 0;
};

Node* DataStructure::createNode(int data, Node* nodeNext) {
  Node* newNode = new Node(nodeNext, data, length);
  return newNode;
};

string DataStructure::toString() {
  Node* currentNode = head;
  string output = "";
  while(currentNode != NULL) {
    output = output + to_string(currentNode->index) + ": [" + to_string(currentNode->data) + "]\n";
    currentNode = currentNode->next;
  }
  return output;
};