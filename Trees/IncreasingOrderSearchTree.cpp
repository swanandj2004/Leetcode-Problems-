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

TreeNode *increasingBST(TreeNode *root) {
    if(root==NULL) {
        return NULL;
    } else if(root->left==NULL && root->right==NULL) {
        return root;
    }
    
    stack<TreeNode*>st;
    vector<TreeNode*>v;
    TreeNode *current=root;
    while(!st.empty() || current) {
        while(current) {
            st.push(current);
            current=current->left;
        }
        current=st.top();
        st.pop();
        v.push_back(current);
        current=current->right;
    }

    for(int i=0; i<v.size(); i=i+1) {
        v.at(i)->left=NULL;
    }
    for(int i=0; i<v.size()-1; i=i+1) {
        v.at(i)->right=v.at(i+1);
    }
    
    root=v.at(0);

    return root;
}

int main() {
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->left->left=new TreeNode(2);
    root->left->left->left=new TreeNode(1);
    root->left->right=new TreeNode(4);
    root->right=new TreeNode(6);
    root->right->right=new TreeNode(8);
    root->right->right->left=new TreeNode(7);
    root->right->right->right=new TreeNode(9);

    root=increasingBST(root);
    TreeNode *head=root;
    while(head) {
        cout << head->val << " ";
        head=head->right;
    }

    return 0;
}