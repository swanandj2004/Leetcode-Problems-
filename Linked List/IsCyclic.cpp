#include <vector>
#include <iostream>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int v) {
        val=v;
        next=nullptr;
    }
};

bool isCyclic(ListNode *head, ListNode *first) {
    bool result=false;
    vector<ListNode*>v;
    while(head!=nullptr) {
        for(int i=0; i<v.size(); i=i+1) {
            if(head->next==v.at(i)) {
                result=true;
                break;
            }
        }
        if(result==true) {
            break;
        }
        v.push_back(head);
        head=head->next;
    }
    return result;
}

int main() {
    ListNode *first=new ListNode(1);
    first->next=new ListNode(2);
    first->next->next=new ListNode(3);
    first->next->next->next=new ListNode(4);
    first->next->next->next->next=first->next;
    ListNode *head=first;

    cout << isCyclic(head, first);
    return 0;
}