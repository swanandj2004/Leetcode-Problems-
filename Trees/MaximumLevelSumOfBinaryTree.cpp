#include <queue>
#include <climits>
#include <unordered_map>
#include <iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int v) {
        val=v;
        left=NULL;
        right=NULL;
    }
};

int maxLevelSum(TreeNode *root) {
    int level=1;
    unordered_map<int,int>map;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        int levelsize=q.size();
        int sum=0;
        for(int i=0; i<levelsize; i=i+1) {
            TreeNode *current=q.front();
            q.pop();
            sum=sum+current->val;
            if(current->left) {
                q.push(current->left);
            }
            if(current->right) {
                q.push(current->right);
            }
        }
        map[level]=sum;
        level=level+1;
    }
    int max_sum=INT_MIN;
    int level_of_max_sum=INT_MAX;
    for(auto &p : map) {
        max_sum=max(max_sum,p.second);
    }
    for(auto &p : map) {
        if(p.second==max_sum) {
            level_of_max_sum=min(level_of_max_sum,p.first);
        }
    }
    return level_of_max_sum;
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(7);
    root->left->left=new TreeNode(7);
    root->left->right=new TreeNode(-8);
    root->right=new TreeNode(0);

    cout << maxLevelSum(root) << endl;
    return 0;
}