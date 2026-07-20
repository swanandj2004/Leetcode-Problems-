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

bool hasPathSum(TreeNode *root, int targetsum) {
    if(root==NULL) {
        return false;
    }
    targetsum=targetsum-root->val;
    if(root->left==NULL && root->right==NULL && targetsum==0) {
        return true;
    }
    return hasPathSum(root->left,targetsum) || hasPathSum(root->right, targetsum);
}

int main() {
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);    
    root->right=new TreeNode(8);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(4);
    root->right->right->right=new TreeNode(1);
    
    cout << hasPathSum(root, 22);
    return 0;
}
