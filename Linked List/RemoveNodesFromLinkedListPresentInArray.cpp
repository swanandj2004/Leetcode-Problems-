#include <iostream>
#include <vector>
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

ListNode *removeNodes(ListNode *head, vector<int>nums) {
    ListNode *newHead=NULL;
    ListNode *previous=NULL;

    while(head) {
        bool isPresent=false;
        for(int i=0; i<nums.size(); i=i+1) {
            if(nums.at(i)==head->val) {
                isPresent=true;
                break;
            }
        }
        if(isPresent==false) {
            ListNode *newNode=new ListNode(head->val);
            newNode->next=NULL;
            if(newHead==NULL) {
                newHead=newNode;
            }
            if(previous) {
                previous->next=newNode;
            }
            previous=newNode;
        }
        head=head->next;
    }

    return newHead;
}

int main() {
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    head=removeNodes(head, {1,2,3});
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }

    return 0;
}