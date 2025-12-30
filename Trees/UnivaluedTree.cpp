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

bool isUnivaluedTree(TreeNode *root) {
    if(root==NULL) {
        return true;
    }
    if(root->left==NULL && root->right==NULL) {
        return true;
    }
    queue<TreeNode*>q;
    q.push(root);
    int value=root->val;
    while(!q.empty()) {
        TreeNode *current=q.front();
        q.pop();
        if(current->val!=value) {
            return false;
        }
        if(current->left!=NULL) {
            q.push(current->left);
        } if(current->right!=NULL) {
            q.push(current->right);
        }
    }
    return true;
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(1);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(1);
    root->right->right=new TreeNode(1);

    cout << isUnivaluedTree(root);
    return 0;
}