#include "Node.h"

Node::Node(int value, int count) {
    this->value = value;
    this->count = count;
    next = NULL;
}

Node::~Node() {
    if (next != NULL) {
        delete next;
    }
}