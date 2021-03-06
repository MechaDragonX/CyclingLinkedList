#include <algorithm>
#include <iostream>
#include <vector>
#include "list_node.hpp"
using namespace std;

void printAllValues(ListNode* list) {
    ListNode* current = list;
    while(current != nullptr) {
        cout << current->value << " => ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
/*
    1. Check the current node
    2. If the current address is in the address Vector, then return true
    3. Otherwise, move on to the next one and repeat
    4. Return false at the end if loop was never exited
*/
bool isCyclical(ListNode* list) {
    vector<ListNode*> addresses = {};
    ListNode* current = list;
    while(current != nullptr) {
        if(find(addresses.begin(), addresses.end(), *&current) != addresses.end()) {
            return true;
        }
        addresses.push_back(*&current);
        current = current->next;
    }
    return false;
}

int main() {
    ListNode* one = new ListNode{1, nullptr};
    ListNode* two = new ListNode{2, nullptr};
    ListNode* three = new ListNode{3, nullptr};
    ListNode* four = new ListNode{4, nullptr};
    ListNode* five = new ListNode{5, nullptr};
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = three;

    cout << isCyclical(one) << endl;
}
