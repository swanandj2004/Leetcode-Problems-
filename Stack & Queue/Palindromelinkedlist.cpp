#include <stack>
#include <iostream>
using namespace std;

stack<int>st;

class node {
    public:
    int val;
    node *next;
    node(int v) {
        val=v;
        next=nullptr;
    }
};

bool isPalindrome(node *head, node *first) {
    bool result=true;
    while(head!=nullptr) {
        st.push(head->val);
        head=head->next;
    }
    head=first;
    while(head!=nullptr) {
        if(st.top()!=head->val) {
            result=false;
        }
        head=head->next;
        st.pop();
    }
    return result; 
}

int main() {
    node *first=new node(1);
    first->next=new node(2);
    first->next->next=new node(2);
    first->next->next->next=new node(1);
    node *head=first;

    cout << isPalindrome(head, first);
    return 0;
}