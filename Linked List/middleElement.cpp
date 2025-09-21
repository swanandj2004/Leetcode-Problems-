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

int middleNode(node *head, node *first) {
    int length=0, track=0, middle;
    while(head!=nullptr) {
        length++;
        head=head->next;
    }
    head=first;
    while(head!=nullptr) {
        track++;
        if(track==(length/2)+1) {
            middle=head->val;
            break;
        }
        head=head->next;
    }
    return middle;
}

int main() {
    node *first=new node(1);
    first->next=new node(2);
    first->next->next=new node(3);
    first->next->next->next=new node(4);
    first->next->next->next->next=new node(5);
    first->next->next->next->next->next=new node(6);
    node *head=first;

    cout << middleNode(head, first);
    return 0;
}