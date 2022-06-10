#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

bool has_cycle(Node* head) {
    Node *tmp = head;
    unordered_set<Node*> visited;
    while (tmp != nullptr) {
        if (visited.find(tmp) != visited.end()) {
            return true;
        }
        visited.insert(tmp);
        tmp = tmp->next;
    }

    return false;
}

int main() {
    return 0;
}