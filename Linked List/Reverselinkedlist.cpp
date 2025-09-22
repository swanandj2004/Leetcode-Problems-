#include <iostream>
using namespace std;

class node {
    public:
    int val;
    node *next;
    node(int v) {
        val=v;
        next=nullptr;
    }
};

node *reverse(node *head, node *first) {
    node *current=head->next;
    node *previous=nullptr;
    head->next=nullptr;
    while(current!=nullptr) {
        node *next_node=current->next;
        current->next=nullptr;
        previous=head;
        current->next=previous;
        head=current;
        current=next_node;
    }  
    return head;
}

int main() {
    node *first=new node(1);
    first->next=new node(2);
    first->next->next=new node(3);
    first->next->next->next=new node(4);
    first->next->next->next->next=new node(5);
    node *head=first;

    node *new_head=reverse(head, first);
    while(new_head!=nullptr) {
        cout << new_head->val << " ";
        new_head=new_head->next;
    }
    return 0;
}