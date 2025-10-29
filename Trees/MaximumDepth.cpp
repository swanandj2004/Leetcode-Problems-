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

int maxDepth(TreeNode *root) {
    if(root==NULL) {
        return 0;
    } 
    if(root->left==NULL && root->right==NULL) {
        return 1;
    }
    int leftdepth=maxDepth(root->left);
    int rightdepth=maxDepth(root->right);

    return max(leftdepth, rightdepth)+1;
}

int main() {
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    cout << maxDepth(root);
    return 0;
}