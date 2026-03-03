#include <vector>
#include <queue>
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

vector<vector<int>>zigZagLevelOrderTraversal(TreeNode *root) {
    if(root==NULL) {
        return {};
    }

    vector<vector<int>>node;
    
    int alt=0;
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
        if(alt%2!=0) {
            reverse(v.begin(),v.end());
        }
        node.push_back(v);
        alt=alt+1;
    }

    return node;
}

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20);
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);

    root->left = node9;
    root->right = node20;
    node20->left = node15;
    node20->right = node7;

    vector<vector<int>>node=zigZagLevelOrderTraversal(root);
    for(int i=0; i<node.size(); i=i+1) {
        for(int j=0; j<node.at(i).size(); j=j+1) {
            cout << node.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}