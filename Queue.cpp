#include <string>
#include "Queue.h"
#include "DataStructure.h"
#include "Node.h"

using namespace std;

Queue::Queue() {
  ds = new DataStructure();
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
  this->updateIndexes();
  return returnData;
}

void Queue::updateIndexes() {
  int currentIndex = 0;
  Node* currentNode = ds->getHead();
  int length = ds->getLength();
  while (currentIndex < length) {
    currentNode->setIndex(currentIndex);
    currentNode = currentNode->next;
    currentIndex = currentIndex + 1;
  }
}