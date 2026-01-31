#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) {
        val=v;
        left=right=NULL;
    }
};

TreeNode *flatten(TreeNode *root) {
    if(root==NULL) {
        return NULL;
    }
    vector<TreeNode*>v;
    stack<TreeNode*>st;
    TreeNode *current=root;
    while(current || !st.empty()) {
        while(current) {
            st.push(current);
            v.push_back(current);
            current=current->left;
        }
        current=st.top();
        st.pop();
        current=current->right;
    }
    for(int i=0; i<v.size(); i=i+1) {
        v.at(i)->left=NULL;
    }
    for(int i=0; i<v.size()-1; i=i+1) {
        v.at(i)->right=v.at(i+1);
    }
    return root;
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right=new TreeNode(5);
    root->right->right=new TreeNode(6);

    root=flatten(root);
    TreeNode *head=root;
    while(head) {
        cout << head->val << " ";
        head=head->right;
    }

    return 0;
}