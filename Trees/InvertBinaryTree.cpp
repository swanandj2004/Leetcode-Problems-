#include <queue>
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

TreeNode *invertTree(TreeNode *root) {
    if(root==NULL) {
        return NULL;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *current=q.front();
        q.pop();
        TreeNode *temp=current->left;
        current->left=current->right;
        current->right=temp;
        if(current->left!=NULL) {
            q.push(current->left);
        }
        if(current->right!=NULL) {
            q.push(current->right);
        }
    }
    return root;
}

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    TreeNode *invertedTreeRoot=invertTree(root);
    queue<TreeNode*>q;
    q.push(invertedTreeRoot);
    while(!q.empty()) {
        TreeNode *current=q.front();
        q.pop();
        cout << current->val << " ";
        if(current->left!=NULL) {
            q.push(current->left);
        }
        if(current->right!=NULL) {
            q.push(current->right);
        }
    }
    return 0;
}