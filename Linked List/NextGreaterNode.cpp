#include <vector>
#include <iostream>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int v) {
        val=v;
        next=NULL;
    }
};

vector<int>findNode(ListNode *head, vector<int>&v) {
    ListNode *currentNode=head;
    while(head) {
        if(head->val > currentNode->val) {
            v.push_back(head->val);
            return v;
        }
        head=head->next;
    }
    v.push_back(0);
    return v;
}

vector<int>nextGreaterNode(ListNode *head) {
    if(head==NULL) {
        return {};
    }
    vector<int>v;
    while(head) {
        v=findNode(head, v);
        head=head->next;
    }
    return v;
}

int main() {
    ListNode *head=new ListNode(2);
    head->next=new ListNode(7);
    head->next->next=new ListNode(4);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(5);

    vector<int>v=nextGreaterNode(head);
    for(int i=0; i<v.size(); i=i+1) {
        cout << v.at(i) << " ";
    }
    return 0;
}