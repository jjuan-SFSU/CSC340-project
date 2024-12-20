#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "LinkedList.h"
#include "Node.h"

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

LinkedList::~LinkedList() {
    Node* current = head; // Start at the head of the list
    while (current != nullptr) {
        Node* next = current -> getNext(); // Save the pointer to the next node
        delete current;             // Delete the current node
        current = next;             // Move to the next node
    }
    head = nullptr; // Optional: Clear the head pointer (good practice)
    tail = nullptr;
}

LinkedList::LinkedList(const std::string& word) : head(nullptr), tail(nullptr), count(0) {
    push_back(word);  // Initialize the list with the provided word
}

void LinkedList::push_back(Node* newWordNode) {
    if (!newWordNode) return;  // Null safety check

    // Detach the node from any previous list
    newWordNode->setNext(nullptr);
    newWordNode->setPrev(nullptr);

    if (!head) {  // If the list is empty
        head = tail = newWordNode;
    } else {  // Attach to the end of the list
        tail->setNext(newWordNode);
        newWordNode->setPrev(tail);
        tail = newWordNode;
    }
    count++;  // Update list size
}


void LinkedList::push_back(const string& word) {
    Node* new_node = new Node(word);  // Create a new node

    if (tail == nullptr) {  // List is empty
        head = tail = new_node;  // New node is both the head and the tail
    } else {
        tail->setNext(new_node);  // Link the last node to the new node
        new_node->setPrev(tail);  // Set the new node's previous pointer to the old tail
        tail = new_node;        // Move the tail pointer to the new node
    }

    count++;  // Increment the list size
}

int LinkedList::size() const {
    return count;
}

void LinkedList::print() const {
    if (!head) {
            return;
        }

        Node* current = head;
        while (current) {
            cout << current->getWord() << endl;
            current = current->getNext();
        }
}

void LinkedList::printReverse() const {
    if (!head) {
        return; // Empty list, nothing to print
    }

    // Traverse to the tail of the list
    Node* current = head;
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }

    // Traverse backwards from the tail to the head
    while (current != nullptr) {
        cout << current -> getWord() << endl;
        current = current -> getPrev();
    }
}

void LinkedList::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
    head = tail = nullptr;
    count = 0;
}

string cleanInput(const string& input) {
    string cleaned;
    for (char ch : input) {
        if (isalpha(ch)) {  // Only accept alphabetic characters
            cleaned += tolower(ch);  // Convert to lowercase
        }
    }
    return cleaned;
}

Node* findWord(LinkedList* lDict, const string& userWord) {
    string cleanedWord = cleanInput(userWord);  // Clean the input before searching
    const Node* current = lDict->begin();  // Start from the beginning of the list
    
    while (current) {
        if (current->getWord() == cleanedWord) {
            return const_cast<Node*>(current);  // Return the node if the word is found
        }
        current = current->getNext();  // Move to the next node
    }
    return nullptr;  // Return nullptr if the word is not found
}

Node* LinkedList::deleteWord(Node* node) {
    if (!node) return nullptr; // If node is null, return nullptr

    Node* nextNode = node->getNext();
    Node* prevNode = node->getPrev();

    // Adjust the links
    if (prevNode) {
        prevNode->setNext(nextNode);
    } else {
        // If there is no previous node, we are at the head
        head = nextNode;
    }

    if (nextNode) {
        nextNode->setPrev(prevNode);
    } else {
        // If there is no next node, we are at the tail
        tail = prevNode;
    }

    // Delete the node and return the next node
    delete node;
    count--;
    return nextNode;
}

Node* LinkedList::findWord(const string& word) {
    Node* current = head; // Start at the head of the list
    
    while (current) {
        if (current->getWord() == word) {
            return current; // Word found
        }
        current = current->getNext();
    }
    
    return nullptr; // Word not found
}

Node* LinkedList::insert_before(const std::string newWord, Node* knownNode) {
    Node* newNode = new Node(newWord);

    if (!knownNode) {
        // Inserting into an empty list, or if knownNode is nullptr
        if (!head) {
            head = tail = newNode;  // The list was empty
        }
    } else if (knownNode == head) {
        // Inserting before the head node
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    } else {
        // Inserting before a middle node
        newNode->setPrev(knownNode->getPrev());
        newNode->setNext(knownNode);
        knownNode->getPrev()->setNext(newNode);
        knownNode->setPrev(newNode);
    }

    ++count;
    return newNode;
}

LinkedList& LinkedList::operator+=(LinkedList& other) {
   
    Node* current = other.head; // Traverse from the head of `other`.
    
    while (current) {
        this->push_back(current->getWord()); // Insert a copy of `current->data` into `this`.
        current = current->getNext();
    }
    
    other.head = nullptr;
    other.tail = nullptr;
    other.setSize(0);
    
    return *this; // Return the updated list.
}

void LinkedList::setSize(int newSize) {
    this->count = newSize; // Where `actualSize` is the true member variable
}

void LinkedList::mergeDicts(LinkedList* listB) {
    if (!listB || !listB->head) return; // If listB is empty, nothing to merge

    Node* currentA = this->head; // Pointer for the current list (listA)
    Node* currentB = listB->head; // Pointer for the incoming list (listB)
    Node* prevA = nullptr; // Track the previous node in listA

    while (currentB) {
        Node* nextB = currentB->getNext(); // Save next node in listB

        if (!currentA) {
            // If listA is exhausted, append remaining nodes from listB to the end of listA
            if (prevA) {
                prevA->setNext(currentB);  // Connect the previous node to currentB
            }
            currentB->setPrev(prevA);  // Set the prev pointer of currentB
            this->tail = currentB;     // Update the tail of listA to the last node
            while (currentB) {         // Traverse and update size for remaining nodes in listB
                this->count++;
                currentB = currentB->getNext();
            }
            break; // No need to continue as listB is now fully merged
        } else if (currentB->getWord() < currentA->getWord()) {
            // Insert currentB before currentA
            if (prevA) {
                prevA->setNext(currentB);  // Set previous node's next to currentB
            } else {
                this->head = currentB;     // Update head if inserting at the beginning
            }

            currentB->setPrev(prevA);       // Set previous pointer of currentB
            currentB->setNext(currentA);    // Set next pointer of currentB
            currentA->setPrev(currentB);    // Set previous pointer of currentA
            prevA = currentB;               // Update prevA to currentB

            this->count++;  // Increment size for every node added from listB
        } else if (currentB->getWord() == currentA->getWord()) {
            // Duplicate: delete currentB
            delete currentB;
        } else {
            // Move to the next node in listA
            prevA = currentA;
            currentA = currentA->getNext();
            continue;
        }

        // Advance currentB to the next node
        currentB = nextB;
    }

    // If there are any remaining nodes in listB, we append them to listA and update size
    while (currentB) {
        if (prevA) {
            prevA->setNext(currentB); // Connect the last node to currentB
        }
        currentB->setPrev(prevA);    // Set the previous pointer of currentB
        this->tail = currentB;       // Update the tail to the last node in listB
        this->count++;                // Increment size for each node in listB
        prevA = currentB;            // Update prevA to the last node
        currentB = currentB->getNext();  // Move to the next node
    }

    // Clear listB's head and tail pointers
    listB->head = nullptr;
    listB->tail = nullptr;
}

void LinkedList::mergeSort() {
    // Call the recursive mergeSort helper function with the current list
    mergeSort(this);
}

void LinkedList::mergeSort(LinkedList* topListPtr) {
    // Base case: if the list has 0 or 1 elements, it is already sorted
    if (topListPtr->size() <= 1) return;

    // Step 1: Split the list into two halves
    LinkedList leftList, rightList;
    topListPtr->splitList(&leftList, &rightList);  // This is a method to split the list into two halves

    // Step 2: Recursively sort both halves
    leftList.mergeSort(&leftList);
    rightList.mergeSort(&rightList);

    // Step 3: Merge the two sorted halves back into the original list
    topListPtr->mergeDicts(&leftList, &rightList);
}

void LinkedList::mergeDicts(LinkedList* leftList, LinkedList* rightList) {
    Node* leftNode = leftList->head;
    Node* rightNode = rightList->head;

    // Reset current list
    this->head = nullptr;
    this->tail = nullptr;
    this->setSize(0);

    // Merge the two sorted lists by comparing nodes
    while (leftNode && rightNode) {
        if (leftNode->getWord() < rightNode->getWord()) {
            this->push_back(leftNode->getWord());
            leftNode = leftNode->getNext();
        } else {
            this->push_back(rightNode->getWord());
            rightNode = rightNode->getNext();
        }
    }

    // If there are any remaining nodes in the left list, append them
    while (leftNode) {
        this->push_back(leftNode->getWord());
        leftNode = leftNode->getNext();
    }

    // If there are any remaining nodes in the right list, append them
    while (rightNode) {
        this->push_back(rightNode->getWord());
        rightNode = rightNode->getNext();
    }
}

void LinkedList::splitList(LinkedList* leftList, LinkedList* rightList) {
    // Step 1: Find the middle node
    Node* slow = this->head;
    Node* fast = this->head;
    Node* prev = nullptr;

    // Use slow and fast pointers to find the middle
    while (fast && fast->getNext()) {
        prev = slow;
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }

    // Split the list at the middle point
    if (prev) {
        prev->setNext(nullptr);  // Disconnect the left half from the right half
    }

    // Step 2: Assign the left and right lists
    leftList->head = this->head;
    leftList->tail = prev;  // Left list ends at the middle
    leftList->setSize(this->size() / 2);

    rightList->head = slow;
    rightList->tail = this->tail;
    rightList->setSize(this->size() - leftList->size());
}


#endif // LINKEDLIST_CPP
