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

vector<int>rightSideView(TreeNode *root) {
    if(root==NULL) {
        return {};
    }
    if(root->left==NULL && root->right==NULL) {
        return {root->val};
    }

    vector<int>visible;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        int levelsize=q.size();
        for(int i=0; i<levelsize; i=i+1) {
            TreeNode *current=q.front();
            q.pop();
            if(i==levelsize-1) {
                visible.push_back(current->val);
            }
            if(current->left) {
                q.push(current->left);
            }
            if(current->right) {
                q.push(current->right);
            }
        }
    }
    
    return visible;
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->left->left->left=new TreeNode(5);
    root->right=new TreeNode(3);

    vector<int>visible=rightSideView(root);
    for(int i=0; i<visible.size(); i=i+1) {
        cout << visible.at(i) << " ";
    }

    return 0;
}