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

int sumOfLeftLeaves(TreeNode *root) {
    if(root==NULL) {
        return 0;
    } else if(root->left==NULL && root->right==NULL) {
        return 0;
    }
    int leftSum=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *current=q.front();
        q.pop();
        if(current->left!=NULL) {
            TreeNode *leftNode=current->left;
            if(leftNode->left==NULL && leftNode->right==NULL) {
                leftSum=leftSum+leftNode->val;
            }
        }
        if(current->left!=NULL) {
            q.push(current->left);
        } if(current->right!=NULL) {
            q.push(current->right);
        }
    }
    return leftSum;
}

int main() {
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    cout << sumOfLeftLeaves(root);
    return 0;
}