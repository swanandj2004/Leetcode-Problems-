#include <stack>
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

vector<vector<int>>levelOrderBottom(TreeNode *root) {
    if(root==NULL) {
        return {};
    }
    vector<vector<int>>result;
    stack<vector<int>>st;
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
        st.push(v);
    }
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main() {
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    vector<vector<int>>result=levelOrderBottom(root);
    for(int i=0; i<result.size(); i=i+1) {
        for(int j=0; j<result.at(i).size(); j=j+1) {
            cout << result.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}