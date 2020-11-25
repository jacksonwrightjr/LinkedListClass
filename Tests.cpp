#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "LinkedList.h"

using std::cout, std::endl;

int main() {
    // TODO(student): the rest of the Tests

    LinkedList test0; // initialize first testing list

    test0.push_back(1);
    test0.push_back(7);
    test0.push_back(2);
    test0.push_back(7);
    test0.push_back(7);
    test0.push_back(3);
    test0.push_back(7);
    test0.push_back(7);
    test0.push_back(4);
    test0.push_back(7);
    test0.push_back(7);
    test0.push_back(7);
    test0.push_back(7);
    test0.remove_duplicates();
    test0.push_back(10);
    test0.push_back(10);
    test0.push_back(20);
    test0.push_back(5);
    test0.push_back(4);
    test0.push_back(3);
    test0.push_back(2);
    test0.push_back(1);
    test0.push_back(-1);
    test0.push_back(0);
    test0.push_back(4);
    test0.push_back(3);
    test0.remove_duplicates();

    LinkedList list;
    list.push_back(11);
    list.push_back(9);
    list.push_back(3);
    list.push_back(8);
    list.push_back(7);
    list.push_back(5);
    list.push_back(2);
    list.push_back(1);
    list.push_back(4);
    list.push_back(3);
    list.push_back(9);
    list.push_back(8);
    list.remove_duplicates();

    LinkedList myList(list);

    LinkedList duplicateList;
    for (size_t i = 0; i < 1000; i++) {
        duplicateList.push_back(1);
        duplicateList.push_back(-2);
        duplicateList.push_back(-100);
    }
    duplicateList.remove_duplicates();

    LinkedList constantlyDecreasing;
    for (size_t j = 10000000; j > 0; j--) {
        constantlyDecreasing.push_back(j);
    }


    LinkedList emptyList;
    emptyList.remove_duplicates();
    
    list = test0;
    
    const Node* x = test0.head();
    Node* y = x->next;
    cout << x->data << " ";
    while(y->next != nullptr) {
        cout << y->data << " ";
        if (y->next != nullptr) {
            y = y->next;
        }
    }

    cout << y->data;
    cout << endl;
    cout << "Length of max decreasing in test0: " << test0.length_max_decreasing() << endl;
    cout << "Linked list \"test0\" size: " << test0.size() << endl;
    cout << "test0 head: " << test0.head()->data << endl;
    test0.~LinkedList();
    cout << "Length of max decreasing in list: " << list.length_max_decreasing() << endl;
    cout << "Linked list \"list\" size: " << list.size() << endl;
    cout << "Length of max decreasing in myList: " << myList.length_max_decreasing() << endl;
    cout << "Linked list \"myList\" size: " << myList.size() << endl;
    cout << "Length of max decreasing in constant decreasing list: " << constantlyDecreasing.length_max_decreasing() << endl;
    cout << "Constant decreasing list size: " << constantlyDecreasing.size() << endl;
    cout << "Length of max decreasing in duplicate list: " << duplicateList.length_max_decreasing() << endl;
    cout << "Duplicate list size: " << duplicateList.size() << endl;
    cout << "Length of max decreasing in empty list: " << emptyList.length_max_decreasing() << endl;
    cout << "Empty list size: " << emptyList.size() << endl;
    cout << "Empty list head: " << emptyList.head() << endl;

    return 0;
}
