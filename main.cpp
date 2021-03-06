#include <iostream>
#include "list_node.hpp"
using namespace std;

int main() {
    /*
        1. Check the current node
        2. If the current address is in the address Vector, then return true
        3. Otherwise, move on to the next one and repeat
        4. Return false at the end if loop was never exited
    */
    ListNode* link = new ListNode{
        1, new ListNode{2, 
            new ListNode{3, 
                new ListNode{4, 
                    new ListNode{5, 
                        nullptr
                    }
                }
            }
        }
    };

    ListNode* current = link;
    while(current != nullptr) {
        cout << current->value << " => ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
