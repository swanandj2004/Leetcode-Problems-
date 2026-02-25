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

int calGreaterValue(TreeNode *current, TreeNode *root) {
    int newValue=0;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode *NodeAtFront=q.front();
            q.pop();
            if(NodeAtFront->val>=current->val) {
                newValue=newValue+NodeAtFront->val;
            }
            if(NodeAtFront->left) {
                q.push(NodeAtFront->left);
            } if(NodeAtFront->right) {
                q.push(NodeAtFront->right);
            }
        }
        
        return newValue;
}

TreeNode *convertToGreaterTree(TreeNode *root) {
    if(root==NULL) {
            return NULL;
        } if(root->left==NULL && root->right==NULL) {
            return root;
        }
        
        vector<int>v;
        
        queue<TreeNode*>q;
        q.push(root);  
        
        while(!q.empty()) {
            TreeNode *current=q.front();
            q.pop();
            int newValue=calGreaterValue(current, root);
            v.push_back(newValue);
            if(current->left) {
                q.push(current->left);
            } if(current->right) {
                q.push(current->right);
            }           
        }
        
        while(!q.empty()) {
            q.pop();
        }
        
        int i=0;
        
        q.push(root);
        while(!q.empty()) {
            TreeNode *current=q.front();
            q.pop();
            current->val=v.at(i);
            if(current->left) {
                q.push(current->left);
            } if(current->right) {
                q.push(current->right);
            }
            i=i+1;
        }
        
        return root;
}

int main() {
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(1);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(2);
    root->left->right->right=new TreeNode(3);
    root->right=new TreeNode(6);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(7);
    root->right->right->right=new TreeNode(8);

    root=convertToGreaterTree(root);

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *current=q.front();
        q.pop();
        cout << current->val << " ";
        if(current->left) {
            q.push(current->left);
        } if(current->right) {
            q.push(current->right);
        }
    }

    return 0;
}