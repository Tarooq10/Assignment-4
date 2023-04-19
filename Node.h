#ifndef NODE_H
#define NODE_H

struct Node {
    int value;
    int count;
    Node* next;

    Node(int value, int count = 1);

    ~Node();
};

#endif