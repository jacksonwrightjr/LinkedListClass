#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;
    // TODON'T(student): change the visibility, types, or names of the members
    // TOMAYBE(student): the optional-rest of the Node
};

class LinkedList {
    // the type to use for sizes and indices is size_t.
    // TODO(student): the rest of the LinkedList
    private:

    std::size_t _size = 0; // size of list
    Node* headPt = nullptr; // head of list
    Node* tailPt = nullptr; // tail of list
    Node* prevPt = nullptr; // previous point to marker
    Node* nextPt = nullptr; // next point from marker
    Node* marker = nullptr; // tool to traverse linked list

    public:
    // default constructor
    LinkedList();
    // destructor
    ~LinkedList();
    // copy constructor
    LinkedList(const LinkedList& x);
    //copy assignment operator
    LinkedList& operator=(const LinkedList& x);

    size_t size() const { return _size; }; // gets size of list
    const Node* head() const; // returns head of list
    void push_back(int value); // adds value to end of list and reassigns tailptr
    void remove_duplicates(); // removes all duplicate numbers from linked list
    std::size_t length_max_decreasing() const; // gives length of maximum sequence of decreasing numbers


};

#endif  // LINKEDLIST_H