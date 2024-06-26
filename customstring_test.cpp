#include <cassert>
#include "customstring.h"

void testDefaultConstructor() {
    customstring str;
    assert(str.size() == 0);
    assert(str.c_str() == nullptr);
}

void testCharConstructor() {
    customstring str("Hello");
    assert(str.size() == 5);
    assert(std::strcmp(str.c_str(), "Hello") == 0);
}

void testCopyConstructor() {
    customstring str1("Hello");
    customstring str2 = str1;
    assert(str2.size() == str1.size());
    assert(std::strcmp(str2.c_str(), str1.c_str()) == 0);
}


void testAssignmentOperator() {
    customstring str1 = "Hello";
    customstring str2;
    str2 = str1;
    assert(str2 == "Hello");
}

void testLength() {
    customstring str = "Hello";
    assert(str.size() == 5);
}

void testSubstring() {
    customstring str = "Hello";
    assert(str.substr(1, 3) == "ell");
}

int main() {
    testDefaultConstructor();
    testCharConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testLength();
    testSubstring();
    std::cout << "All tests passed!\n";
    return 0;
}