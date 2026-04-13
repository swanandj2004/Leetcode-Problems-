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

ListNode *insertGreatestCommonDivisors(ListNode *head) {
    if(head==NULL) {
        return NULL;
    }
    if(head->next==NULL) {
        return head;
    }

    vector<int>divisors;

    ListNode *firstNode=head;
    ListNode *nextNode=NULL;

    while(head) {
        if(head->next==NULL) {
            break;
        }
        nextNode=head->next;
        int a=head->val;
        int b=nextNode->val;
        vector<int>v;
        if(a > b) {
            for(int i=1; i<a+1; i=i+1) {
                if(a%i==0 && b%i==0) {
                    v.push_back(i);
                }
            }
        } 
        else if((a < b) || (a==b)) {
            for(int j=1; j<b+1; j=j+1) {
                if(a%j==0 && b%j==0) {
                    v.push_back(j);
                }
            }
        }
        int max=v.at(0);
        for(int i=0; i<v.size(); i=i+1) {
            if(max < v.at(i)) {
                max=v.at(i);
            }
        }
        divisors.push_back(max);
        head=head->next;
    }

    int i=0;
    head=firstNode;
    while(head) {
        if(head->next==NULL) {
            break;
        }
        ListNode *current=new ListNode(divisors.at(i));
        ListNode *nextNode=head->next;
        head->next=NULL;
        head->next=current;
        current->next=nextNode;
        head=nextNode;
        i=i+1;
    }

    head=firstNode;
    return head;
}

int main() {
    ListNode *head=new ListNode(18);
    head->next=new ListNode(6);
    head->next->next=new ListNode(10);
    head->next->next->next=new ListNode(3);

    head=insertGreatestCommonDivisors(head);
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }

    return 0;
}