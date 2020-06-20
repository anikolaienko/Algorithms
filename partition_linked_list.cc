/**
 * 2.4 Partition linked lists from "Cracking coding interview"
 */

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next = nullptr;

    Node (int val_): val{val_} {}
};

#define SIMPLE

#ifdef SIMPLE

Node* partition(Node* node, int value) {
    Node *head = node, *tail = node;

    while (node) {
        Node *next = node->next;
        if (node->val < value) {
            node->next = head;
            head = node;
        } else {
            tail->next = node;
            tail = node;
        }

        node = next;
    }
    tail->next = nullptr;

    return head;
}

#else

Node* partition(Node* node, int value) {
    Node *leftHead = nullptr, *rightHead = nullptr;
    Node *left = nullptr, *right = nullptr;

    while (node) {
        if (node->val < value) {
            // add to left side
            if (left) left->next = node;
            else leftHead = node;

            left = node;
        } else {
            // add to right side
            if (right) right->next = node;
            else rightHead = node;

            right = node;
        }

        node = node->next;
    }

    if (right) right->next = nullptr;
    if (left) left->next = rightHead;
    else leftHead = rightHead;

    return leftHead;
}

#endif

void display(Node* node, const string message) {
    cout << message << endl;
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(3);
    Node* node = head;
    node->next = new Node(5); node = node->next;
    node->next = new Node(8); node = node->next;
    node->next = new Node(5); node = node->next;
    node->next = new Node(10); node = node->next;
    node->next = new Node(2); node = node->next;
    node->next = new Node(1); node = node->next;

    display(head, "Initial list:");

    head = partition(head, 5);

    display(head, "After:");
}