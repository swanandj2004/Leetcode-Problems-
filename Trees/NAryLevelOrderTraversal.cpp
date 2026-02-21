#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    vector<TreeNode*>children;
    TreeNode(int v) {
        val=v;
    }
    TreeNode(int v, vector<TreeNode*>_children) {
        val=v;
        children=_children;
    }
};

vector<vector<int>>levelOrder(TreeNode *root) {
    if(root==NULL) {
        return {};
    }
    
    vector<vector<int>>node;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()) {
        int levelsize=q.size();
        vector<int>v;
        
        for(int i=0; i<levelsize; i=i+1) {
            TreeNode *current=q.front();
            q.pop();
            for(int j=0; j<current->children.size(); j=j+1) {
                q.push(current->children.at(j));
            }
            v.push_back(current->val);
        }
        node.push_back(v);
    }

    return node;
}

int main() {
    TreeNode *root=new TreeNode(1);
    TreeNode *rootfirstchild=new TreeNode(3);
    TreeNode *rootsecondchild=new TreeNode(2);
    TreeNode *rootthirdchild=new TreeNode(4);
    TreeNode *rootfirstchildfirstchild=new TreeNode(5);
    TreeNode *rootfirstchildsecondchild=new TreeNode(6);

    root->children.push_back(rootfirstchild);
    root->children.push_back(rootsecondchild);
    root->children.push_back(rootthirdchild);
    rootfirstchild->children.push_back(rootfirstchildfirstchild);
    rootfirstchild->children.push_back(rootfirstchildsecondchild);

    vector<vector<int>>node=levelOrder(root);

    for(int i=0; i<node.size(); i=i+1) {
        for(int j=0; j<node.at(i).size(); j=j+1) {
            cout << node.at(i).at(j) << " ";
        }
        cout << "  ";
    }


    return 0;
}