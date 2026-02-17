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

ListNode *reverseBetween(ListNode *head, int left, int right) {
    if(head==NULL) {
        return NULL;
    } 
    else if(left==right) {
        return head;
    }
    
    if(left==1) {
        
        ListNode *firstNode=head;
        ListNode *leftNode=head;
        ListNode *rightNode=NULL;
        ListNode *nextOfRightNode=NULL;
        int track=0;
        
        while(head) {
            track++;
            if(track==right) {
                rightNode=head;
                nextOfRightNode=rightNode->next;
            }
            head=head->next;
        }
        
        head=firstNode;
        rightNode->next=NULL;
        ListNode *current=head->next;
        head->next=NULL;
        while(current) {
            ListNode *nextNode=current->next;
            current->next=NULL;
            current->next=head;
            head=current;
            current=nextNode;
        }
        firstNode->next=nextOfRightNode;
        firstNode=rightNode;
        head=rightNode;
        
        return head;
    } 
    
    ListNode *firstNode=head;
    ListNode *leftNode=NULL;
    ListNode *rightNode=NULL;
    int track=0;    
    
    while(head) {
        track++;
        if(track==left) {
            leftNode=head;
        } else if(track==right) {
            rightNode=head;
        }
        head=head->next;
    }
    
    ListNode *previousOfLeftNode=NULL;
    ListNode *nextOfRightNode=NULL;
    head=firstNode;
    
    while(head) {
        if(head->next==leftNode) {
            previousOfLeftNode=head;
        } else if(head==rightNode) {
            nextOfRightNode=head->next;
        }
        head=head->next;
    }
    
    head=leftNode;
    ListNode *current=head->next;   
    head->next=NULL;
    
    while(head!=rightNode) {
        ListNode *nextNode=current->next;
        current->next=NULL;
        current->next=head;
        head=current;   
        current=nextNode;
    }
    
    leftNode->next=nextOfRightNode;
    previousOfLeftNode->next=NULL;
    previousOfLeftNode->next=rightNode;
    head=firstNode;
    
    return head;
}

int main() {
    // Write C++ code here
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    
    head=reverseBetween(head, 2, 4);
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }

    return 0;
}