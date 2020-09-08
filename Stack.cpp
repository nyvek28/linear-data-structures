#include <string>
#include "Stack.h"
#include "DataStructure.h"
#include "Node.h"

Stack::Stack() {
  ds = new DataStructure();
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