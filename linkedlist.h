#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>

using namespace std;

struct LinkedList {
   
   private:
      Node* head;
      Node* tail;
      int count;
   
   public:
      LinkedList() : head(nullptr), tail(nullptr), count(0) {}
      LinkedList(const std::string& word);
      ~LinkedList();
      
      LinkedList& operator+=(LinkedList& other);
   
      void push_back(const string& word);
      void push_back(Node* newWordNode);
      int size() const;
      void print() const;
      void printReverse() const;
      void clear();  // New function declaration
      Node* begin() const { return head; }
      Node* end() const { return nullptr; }
      
      Node* getHead() const { return head; }
      Node* getTail() const { return tail; }
      Node* deleteWord(Node* node);
      Node* insert_before(string newWord, Node * knownNode);
      Node* findWord(const string& word);
      void setSize(int newSize);
      void mergeDicts(LinkedList* listB);
      
      void mergeSort();
      void mergeDicts(LinkedList* leftList, LinkedList* rightList);
      void mergeSort(LinkedList* topListPtr);
      void splitList(LinkedList* leftList, LinkedList* rightList);

};

string cleanInput(const string& input);
Node* findWord(LinkedList* lDict, const string& userWord);


#endif // LINKEDLIST_H
