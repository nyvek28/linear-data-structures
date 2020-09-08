#include "Node.h"

Node::Node(Node* nextNode, int nodeData, int nodeIndex) {
  next = nextNode;
  data = nodeData;
  index = nodeIndex;
}