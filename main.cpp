#include <iostream>
#include <vector>
#include<LinkedList.h>
using namespace std;

void insertAfter(vector<int>& nums, int firstValue, int secondValue) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == firstValue) {
            nums.insert(nums.begin() + i + 1, secondValue);
            i++; // Skip over the inserted element
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of integers to input: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int firstValue, secondValue;
    cout << "Enter the first value: ";
    cin >> firstValue;
    cout << "Enter the second value: ";
    cin >> secondValue;

    insertAfter(nums, firstValue, secondValue);

    cout << "Updated vector: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    LinkedList list = LinkedList::createList(nums);

    cout << "Linked list: ";
    list.printList();

    cout << "Sum of all nodes: " << list.sumNodes() << endl;

    return 0;
}