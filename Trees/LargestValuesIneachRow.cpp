#include <vector>
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

vector<int>largestValues(TreeNode *root) {
    if(root==NULL) {
        return {};
    } else if(root->left==NULL && root->right==NULL) {
        return {root->val};
    }

    vector<int>values;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        int levelsize=q.size();
        vector<int>v;
        for(int i=0; i<levelsize; i=i+1) {
            TreeNode *current=q.front();
            q.pop();
            v.push_back(current->val);
            if(current->left) {
                q.push(current->left);
            } if(current->right) {
                q.push(current->right);
            }
        }
        int max=v.at(0);
        for(int j=0; j<v.size(); j=j+1) {
            if(max<v.at(j)) {
                max=v.at(j);
            }
        }
        values.push_back(max);
    }

    return values;
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->left->left=new TreeNode(5);
    root->left->right=new TreeNode(3);
    root->right=new TreeNode(2);
    root->right->right=new TreeNode(9);

    vector<int>values=largestValues(root);
    for(int i=0; i<values.size(); i=i+1) {
        cout << values.at(i) << " ";
    }

    return 0;
}