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

int bottomLeftValue(TreeNode *root) {
    if(root->left==NULL && root->right==NULL) {
        return root->val;
    }

    int leftmost_val=root->val;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        int levelsize=q.size();
        for(int i=0; i<levelsize; i=i+1) {
            TreeNode *current=q.front();
            q.pop();
            if(i==0) {
                leftmost_val=current->val;
            }
            if(current->left) {
                q.push(current->left);
            }
            if(current->right) {
                q.push(current->right);
            }
        }
    }
    
    return leftmost_val;
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->right=new TreeNode(3);
    root->right->left=new TreeNode(5);
    root->right->left->left=new TreeNode(7);
    root->right->right=new TreeNode(6);

    cout << bottomLeftValue(root) << endl; 
    return 0;
}
