#include <iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) {
        val=v;
        left=right=nullptr;
    }
};

bool isSymmetric(TreeNode *r1, TreeNode *r2) {
    if(r1==nullptr && r2==nullptr) 
        return true;
    if((r1==nullptr && r2!=nullptr) || (r1!=nullptr && r2==nullptr)) 
        return false;
    return (r1->val==r2->val) && isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);

    cout << isSymmetric(root->left, root->right);
    return 0;
}