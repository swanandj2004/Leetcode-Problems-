#include <iostream>
#include <stack>
#include <vector>
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

void PostorderTraversal(TreeNode *root) {
    vector<int>v;
    if(root==NULL) {
        return;
    }
    if(root->left==NULL && root->right==NULL) {
        v.push_back(root->val);
        cout << v.at(0);
        return;
    }
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()) {
        TreeNode *current=st.top();
        st.pop();
        v.push_back(current->val);
        if(current->left!=NULL) {
            st.push(current->left);
        }
        if(current->right!=NULL) {
            st.push(current->right);
        }
    }
    for(int i=v.size()-1; i>-1; i=i-1) {
        cout << v.at(i) << " ";
    }
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->left=new TreeNode(6);
    root->left->right->right=new TreeNode(7);
    root->right=new TreeNode(3);
    root->right->right=new TreeNode(8);
    root->right->right->left=new TreeNode(9);

    PostorderTraversal(root);

    return 0;
}