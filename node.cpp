#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"
using namespace std;

bool operator==(const Node& lhs, const Node& rhs) {
    return lhs.getWord() == rhs.getWord();
}


#endif
