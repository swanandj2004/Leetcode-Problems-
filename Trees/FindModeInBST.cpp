#include <vector>
#include <queue>
#include <unordered_map>
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

void calFrequency(TreeNode *root, TreeNode *current, unordered_map<int,int>&map) {
    int count=0;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *current2=q.front();
        q.pop();
        if(current->val==current2->val) {
            count=count+1;
        }
        if(current2->left) {
            q.push(current2->left);
        }
        if(current2->right) {
            q.push(current2->right);
        }
    }
    map[current->val]=count;
}

vector<int> findMode(TreeNode *root) {
    if(root==NULL) {
        return { };
    }

    unordered_map<int,int>map;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *current=q.front();
        q.pop();
        calFrequency(root, current, map);
        if(current->left) {
            q.push(current->left);
        }
        if(current->right) {
            q.push(current->right);
        }
    }

    int max_value=0;
    vector<int>mode={};
    for(auto &p : map) {
        max_value=max(max_value,p.second);
    }
    for(auto &p : map) {
        if(max_value==p.second) {
            mode.push_back(p.first);
        }
    }    

    return mode;
}

int main() {
    TreeNode *root=new TreeNode(2);
    root->left=new TreeNode(5);
    root->left->right=new TreeNode(2);
    root->left->right->left=new TreeNode(3);
    root->left->right->right=new TreeNode(6);
    root->right=new TreeNode(4);
    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(1);

    vector<int>mode=findMode(root);
    cout << mode.at(0) << endl;

    return 0;
}