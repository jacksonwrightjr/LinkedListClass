#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "LinkedList.h"
//#include "test_helpers.h"

// TODO(student): the rest of the LinkedList

// default constructor...size 0 and all nodes nullptr
LinkedList::LinkedList() : _size(0), headPt(nullptr), tailPt(nullptr), prevPt(nullptr), nextPt(nullptr), marker(nullptr) {}

// destructor
LinkedList::~LinkedList() {
    if (_size != 0) {
        //std::cout << "Destructor is working" << std::endl;
        marker = headPt;
        
        while (marker != nullptr) {
            nextPt = marker->next;
            marker = nullptr;
            marker = nextPt;
        }

        _size = 0;
        headPt = nullptr;
    }
}

// copy constructor
LinkedList::LinkedList(const LinkedList& x) : _size(x._size), headPt(x.headPt), tailPt(x.tailPt), prevPt(x.prevPt), nextPt(x.nextPt), marker(x.marker) {
    marker = x.headPt;
    nextPt = x.headPt;
    
    while(marker != nullptr) {
        marker->next = nextPt->next;
        nextPt = nextPt->next;
        marker = marker->next;
    }
}

// copy assignment operator
LinkedList& LinkedList::operator=(const LinkedList& x) {
    // assign necessary members
    _size = x._size;
    headPt = x.headPt;
    tailPt = x.tailPt;

    nextPt = x.headPt;

    // put marker at the head to begin traversing
    marker = x.headPt;

    while (marker != nullptr) {
        marker->next = nextPt->next;
        nextPt = nextPt->next;
        marker = marker->next;
    }

    return *this;
}

// returns head pointer or null if list is empty
const Node* LinkedList::head() const {
    if (_size != 0) {
        return headPt;
    } else {
        return nullptr;
    }
}

// pushes int value onto end of list, or assigns int value to head if list is empty
void LinkedList::push_back(int value) {
    // make a new node to point to / assign data to
    Node* x = new Node;
    //std::cout << "function running" << std::endl;

    // if list is empty, just assign value to headPt data and x will be the next node in list
    if (_size == 0) {
        // assign head to non-null node, assign member values
        headPt = x;
        headPt->data = value; // data in head = value
        headPt->next = nullptr; // (head) -> nullptr
        tailPt = headPt; // (currently tail and head node) -> nullptr
        _size++;
        //std::cout << "stuck here" << std::endl;
    } else { // if there's already data in the list, assign x to be the next pointer and add data to that node
    
        tailPt->next = x; // (head) -> intermediate nodes (if any) -> (current tail) -> *new node x inserted after tail*
        x->data = value; // data in node x = value
        tailPt = x;
        tailPt->next = nullptr;

        _size++;
    }
}


void LinkedList::remove_duplicates() {

    if (_size > 0) {
         // we start at the head of the list. * note * marker stores the node of the node->data value we are looking for.
        marker = headPt;
        int searchVal;
        size_t i = 0;

        // we will use nextPt to traverse list, where prevPt is the node behind it.
        prevPt = marker;
        nextPt = prevPt->next;

        // run through list until we get to the end
        while (i < _size) {
            // set value to search for
            searchVal = marker->data;
            //std::cout << "**** NEW SEARCHVAL ****" << std::endl << searchVal << std::endl;

            while (nextPt != nullptr) {

                // if we find a matching second/third/etc. value, reassign nodes to skip that one
                if (nextPt->data == searchVal) {
                    // if value is at end of list, prevPt will be the new tail. point deleted = nullptr
                    if (nextPt == tailPt) {
                        //std::cout << "nextpt is at the tail. we will delete the tail and reassign it to prevpt." << std::endl;
                        prevPt->next = nullptr;
                        tailPt = prevPt;
                        _size--;
                        break;
                    }

                    //std::cout << "prevpt = " << prevPt->data << " nextpt = " << nextPt->data << std::endl;
                    //std::cout << "removing " << nextPt->data << std::endl;

                    prevPt->next = nextPt->next; // skipping over the found duplicate node
                    _size--;

                    // keep going through the list but skip over the duplicate node when moving forward
                    nextPt = nextPt->next;
                } else { // we didn't find the value here...keep traversing 1 by 1
                    //std::cout << "value not found...here we have " << nextPt->data << std::endl;
                    prevPt = nextPt;
                    nextPt = nextPt->next;
                }
            }

            marker = marker->next;
            if (marker != nullptr) {
                prevPt = marker;
                if (prevPt->next != nullptr) {
                    nextPt = prevPt->next;
                }
            }
            i++;
        }
        //std::cout << "tail pt = " << tailPt->data << std::endl;
    }

}

std::size_t LinkedList::length_max_decreasing() const {

    size_t i = 0;
    size_t maxStreak = 0;
    size_t streakHolder = 0;
    int currNum = 0;

    // if the list is empty, return 0
    if (_size == 0) {
        return 0;
    }

    // start from head of the list
    Node* x = headPt;
    currNum = x->data;

    while (i < _size) {
        
        //std::cout << "next value is " << x->next->data << std::endl;
        //std::cout << "currNum = " << currNum << std::endl;

        if (x->next != nullptr && x->next->data < currNum) { // max streak goes up if the next node value is less than current node value
            maxStreak++;
            //std::cout << "max streak now equals " << maxStreak << std::endl;
        } else {
            if (maxStreak > streakHolder) { streakHolder = maxStreak; }
            //std::cout << "streak holder = " << streakHolder << std::endl;
            maxStreak = 0;
        }

        // continue through list
        if (x->next != nullptr) {
            x = x->next;
            currNum = x->data;
            //std::cout << "new currNum at end of loop: " << currNum << std::endl;
        } else {
            break;
        }
        i++;
    }

    return streakHolder + 1;

}