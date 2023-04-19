#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int value;
    int count;
    Node* next;

    Node(int value, int count = 1);

    ~Node();
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();

    ~LinkedList();

    void addNode(int value, int count = 1);

    void removeNode(int value);

    void printList();

    static LinkedList createList(std::vector<int> nums);

    int sumNodes();
};

#endif