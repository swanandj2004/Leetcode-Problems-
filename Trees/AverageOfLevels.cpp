#include <queue>
#include <vector>
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

vector<double>averageOfLevels(TreeNode *root) {
    if(root==NULL) {
        return {};
    }
    vector<double>average;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        int levelsize=q.size();
        double sum=0;
        for(int i=0; i<levelsize; i=i+1) {
            TreeNode *current=q.front();
            q.pop();
            sum=sum+current->val;
            if(current->left) {
                q.push(current->left);
            } if(current->right) {
                q.push(current->right);
            }
        }
        double avg=sum/levelsize;
        average.push_back(avg);
    }
    return average;
}

int main() {
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    vector<double>average=averageOfLevels(root);
    for(int i=0; i<average.size(); i=i+1) {
        cout << average.at(i) << " ";
    }

    return 0;
}