#ifndef NODE_H
#define NODE_H

class Node {
  public:
    Node* next;
    int data;
    int index;
    void setNext(Node* nextNode) { next = nextNode; };
    void setIndex(int newIndex) { index = newIndex; };

    Node(Node*, int, int);
};

#endif