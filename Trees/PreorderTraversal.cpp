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

void PreorderTraversal(TreeNode *root) {    
    if(root==NULL) {
        return;
    }
    if(root->left==NULL && root->right==NULL) {
        cout << root->val;
        return;
    }
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()) {
        TreeNode *current=st.top();
        st.pop();
        cout << current->val << " ";
        if(current->right!=NULL) {
            st.push(current->right);
        }
        if(current->left!=NULL) {
            st.push(current->left);
        }
    }
    return;
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->left=new TreeNode(6);
    root->left->right->right=new TreeNode(7);
    root->right->right=new TreeNode(8);
    root->right->right->left=new TreeNode(9);

    PreorderTraversal(root);
    return 0;
}