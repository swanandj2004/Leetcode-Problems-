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

bool calSum(TreeNode *currentNode, TreeNode *root, int k) {
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *NodeAtFront=q.front();
        if(NodeAtFront==currentNode) {
            q.pop();
            continue;
        }
        q.pop();
        if(currentNode->val+NodeAtFront->val==k) {
            return true;
        } if(NodeAtFront->left!=NULL) {
            q.push(NodeAtFront->left);
        } if(NodeAtFront->right!=NULL) {
            q.push(NodeAtFront->right);
        }
    }
    return false;
}

bool findTarget(TreeNode *root, int k) {
    if(root==NULL) {
        return 0;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *currentNode=q.front();
        q.pop();
        bool isEqual=calSum(currentNode, root, k);
        if(isEqual==true) {
            return true;
        }
        if(currentNode->left!=NULL) {
            q.push(currentNode->left);
        } if(currentNode->right!=NULL) {
            q.push(currentNode->right);
        }
    }
    return false;
}

int main() {
    // Write C++ code here
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right=new TreeNode(6);
    root->right->right=new TreeNode(7);
    
    cout << findTarget(root, 9);

    return 0;
}