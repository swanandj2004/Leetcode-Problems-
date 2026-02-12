#include <stack>
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

ListNode* ReorderList(ListNode *head) {
    if(head==NULL) {
        return NULL;
    } if(head->next==NULL) {
        return head;
    }
    stack<ListNode*>st;
    ListNode *firstNode=head;
    ListNode *middleNode=NULL;
    int len=0, track=0;
    while(head) {
        len++;
        head=head->next;
    }
    head=firstNode;
    while(head) {
        track++;
        if(track==(len/2)+1) {
            middleNode=head;
            break;
        }
        head=head->next;
    }
    head=middleNode;
    while(head) {
        st.push(head);
        head=head->next;
    }
    head=firstNode;
    while(!st.empty()) {
        ListNode *nextNode=head->next;
        head->next=NULL;
        head->next=st.top();
        head=st.top();
        head->next=NULL;
        head->next=nextNode;
        head=nextNode;
        st.pop();
    }
    head->next->next=NULL;
    head=firstNode;
    return head;
}

int main() {
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    head=ReorderList(head);
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }

    return 0;
}