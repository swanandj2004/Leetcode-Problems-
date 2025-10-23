#include <iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) {
        val=v;
        left=nullptr;
        right=nullptr;
    }
};

bool isSameTree(TreeNode *root1, TreeNode *root2) {
    if(root1==nullptr && root2==nullptr) 
        return true;
    if((root1==nullptr && root2!=nullptr) || (root1!=nullptr && root2==nullptr)) 
        return false;
    return(root1->val==root2->val) && isSameTree(root1->left,root2->left) && isSameTree(root1->right, root2->right);
}

int main() {
    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    TreeNode *root2=new TreeNode(1);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);

    cout << isSameTree(root1, root2);
    return 0;
}