#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

struct Node {
   private:
      string data;
      string word;
      Node* next;
      Node* prev;
      
   public:
      Node() : word(""), next(nullptr), prev(nullptr) {}
      Node(const string& w) : word(w), next(nullptr), prev(nullptr) {}
      
      string getWord() const { return word; }
      string getData() const { return data; }
      Node* getNext() const { return next; }
      Node* getPrev() const { return prev; }
      
      
      void setWord(const string& w) { word = w; }
      void setNext(Node* n) { next = n; }
      void setPrev(Node* p) { prev = p; }
      
};

bool operator==(const Node& lhs, const Node& rhs);
bool operator==(const Node& lhs, const std::string& rhs);
bool operator==(const std::string& lhs, const Node& rhs);


#endif // NODE_H
