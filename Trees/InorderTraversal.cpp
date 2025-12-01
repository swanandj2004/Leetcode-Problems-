#include <stack>
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

void InorderTraversal(TreeNode *root) {
    if(root==NULL) {
        return;
    }
    if(root->left==NULL && root->right==NULL) {
        cout << root->val;
        return;
    }
    stack<TreeNode*>st;
    TreeNode *current=root;
    while(current!=NULL || !st.empty()) {
        while(current!=NULL) {
            st.push(current);
            current=current->left;
        }
        current=st.top();
        st.pop();
        cout << current->val << " ";
        current=current->right;
    }
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(8);
    root->left->right->left=new TreeNode(6);
    root->left->right->right=new TreeNode(7);

    InorderTraversal(root);
    return 0;
}