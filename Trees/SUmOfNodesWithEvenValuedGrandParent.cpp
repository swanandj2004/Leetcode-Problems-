#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int v) {
        val=v;
        left=right=NULL;
    }
};

int sumEvenGrandParent(TreeNode *root) {
    if(root==NULL) {
        return 0;
    }
    if(root->left==NULL && root->right==NULL) {
        return 0;
    }

    int sum=0;
    vector<TreeNode*>even_nodes;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *current=q.front();
        q.pop();
        if(current->val%2==0) {
            even_nodes.push_back(current);
        }
        if(current->left) {
            q.push(current->left);
        }
        if(current->right) {
            q.push(current->right);
        }
    }

    for(int i=0; i<even_nodes.size(); i=i+1) {
        TreeNode *current=even_nodes.at(i);
        if(current->left) {
            if(current->left->left) {
                sum=sum+current->left->left->val;
            }
            if(current->left->right) {
                sum=sum+current->left->right->val;
            }
        }
        if(current->right) {
            if(current->right->left) {
                sum=sum+current->right->left->val;
            }
            if(current->right->right) {
                sum=sum+current->right->right->val;
            }
        }
    }

    return sum;
}

int main() {
    TreeNode *root=new TreeNode(6);
    root->left=new TreeNode(7);
    root->left->left=new TreeNode(2);
    root->left->left->left=new TreeNode(9);
    root->left->right=new TreeNode(7);
    root->left->right->left=new TreeNode(1);
    root->left->right->right=new TreeNode(4);
    root->right=new TreeNode(8);
    root->right->left=new TreeNode(1);
    root->right->right=new TreeNode(3);
    root->right->right->right=new TreeNode(5);

    cout << sumEvenGrandParent(root);
    return 0;
}