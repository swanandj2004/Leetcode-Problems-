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

bool searchBST(TreeNode *root, int val) {
    if(root==NULL) {
        return false;
    }   
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *current=q.front();
        q.pop();
        if(current->val==val) {
            return true;
        }
        if(current->left!=NULL) {
            q.push(current->left);
        } if(current->right!=NULL) {
            q.push(current->right);
        }
    }
    return false;
}

int main() {
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right=new TreeNode(7);

    cout << searchBST(root, 2);
    return 0;
}