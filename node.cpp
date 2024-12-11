#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"
using namespace std;

bool operator==(const Node& lhs, const Node& rhs) {
    return lhs.getWord() == rhs.getWord();
}

bool operator!=(const Node& lhs, const Node& rhs) {
    return lhs.getWord() != rhs.getWord();
}

bool operator<(const Node& lhs, const Node& rhs) {
    return lhs.getWord() < rhs.getWord();
}

bool operator>(const Node& lhs, const Node& rhs) {
    return lhs.getWord() > rhs.getWord();
}

bool operator<=(const Node& lhs, const Node& rhs) {
    return lhs.getWord() <= rhs.getWord();
}

bool operator>=(const Node& lhs, const Node& rhs) {
    return lhs.getWord() >= rhs.getWord();
}

// Overloads for comparing Node with std::string
bool operator==(const Node& lhs, const std::string& rhs) {
    return lhs.getWord() == rhs;
}

bool operator!=(const Node& lhs, const std::string& rhs) {
    return lhs.getWord() != rhs;
}

bool operator<(const Node& lhs, const std::string& rhs) {
    return lhs.getWord() < rhs;
}

bool operator>(const Node& lhs, const std::string& rhs) {
    return lhs.getWord() > rhs;
}

bool operator<=(const Node& lhs, const std::string& rhs) {
    return lhs.getWord() <= rhs;
}

bool operator>=(const Node& lhs, const std::string& rhs) {
    return lhs.getWord() >= rhs;
}

bool operator==(const std::string& lhs, const Node& rhs) {
    return lhs == rhs.getWord();
}

bool operator!=(const std::string& lhs, const Node& rhs) {
    return lhs != rhs.getWord();
}

bool operator<(const std::string& lhs, const Node& rhs) {
    return lhs < rhs.getWord();
}

bool operator>(const std::string& lhs, const Node& rhs) {
    return lhs > rhs.getWord();
}

bool operator<=(const std::string& lhs, const Node& rhs) {
    return lhs <= rhs.getWord();
}

bool operator>=(const std::string& lhs, const Node& rhs) {
    return lhs >= rhs.getWord();
}

#endif
