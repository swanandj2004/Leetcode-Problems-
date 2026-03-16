#include <queue>
#include <vector>
#include <algorithm>
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

int kthSmallest(TreeNode *root, int k) {
    vector<int>v;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *current=q.front();
        q.pop();
        v.push_back(current->val);
        if(current->left) {
            q.push(current->left);
        } if(current->right) {
            q.push(current->right);
        }
    }

    sort(v.begin(),v.end());

    return v.at(k-1);
}

int main() {
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(1);
    root->left->right=new TreeNode(2);
    root->right=new TreeNode(4);

    cout << kthSmallest(root, 1);

    return 0;
}