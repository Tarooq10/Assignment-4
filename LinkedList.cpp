#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

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

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    if (head != NULL) {
        delete head;
    }
}

void LinkedList::addNode(int value, int count) {
    if (head == NULL) {
        head = new Node(value, count);
    } else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new Node(value, count);
    }
}

void LinkedList::removeNode(int value) {
    if (head == NULL) {
        return;
    }
    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        while (curr->next != NULL && curr->next->value != value) {
            curr = curr->next;
        }
        if (curr->next != NULL) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }
    }
}

void LinkedList::printList() {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->value << "(" << curr->count << ") ";
        curr = curr->next;
    }
    cout << endl;
}

LinkedList LinkedList::createList(vector<int> nums) {
    LinkedList list;
    for (int i = 0; i < nums.size(); i++) {
        int value = nums[i];
        int count = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] == value) {
                count++;
            }
        }
        list.addNode(value, count);
    }
    return list;
}

int LinkedList::sumNodes() {
    int sum = 0;
    Node* curr = head;
    while (curr != NULL) {
        sum += curr->value * curr->count;
        curr = curr->next;
    }
    return sum;
}