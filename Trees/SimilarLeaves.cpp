#include <stack>
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

bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    if(root1==NULL && root2==NULL) {
        return true;
    }
    if(root1==NULL || root2==NULL) {
        return root1==root2;
    }
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    vector<int>v1;
    vector<int>v2;
    st1.push(root1);
    while(!st1.empty()) {
        TreeNode *current=st1.top();
        st1.pop();
        if(current->left==NULL && current->right==NULL) {
            v1.push_back(current->val);
        }
        if(current->right!=NULL) {
            st1.push(current->right);
        }
        if(current->left!=NULL) {
            st1.push(current->left);
        }
    }
    st2.push(root2);
    while(!st2.empty()) {
        TreeNode *current=st2.top();
        st2.pop();
        if(current->left==NULL && current->right==NULL) {
            v2.push_back(current->val);
        }
        if(current->right!=NULL) {
            st2.push(current->right);
        }
        if(current->left!=NULL) {
            st2.push(current->left);
        }
    }
    if(v1.size()!=v2.size()) {
        return false;
    }
    else if(v1.size()==v2.size()) {
        for(int i=0; i<v1.size(); i=i+1) {
            if(v1.at(i)!=v2.at(i)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    TreeNode *root1=new TreeNode(3);
    root1->left=new TreeNode(5);
    root1->right=new TreeNode(1);
    root1->left->left=new TreeNode(6);
    root1->left->right=new TreeNode(2);
    root1->right->left=new TreeNode(9);
    root1->right->right=new TreeNode(8);
    root1->left->right->left=new TreeNode(7);
    root1->left->right->right=new TreeNode(4);
    
    TreeNode *root2=new TreeNode(3);
    root2->left=new TreeNode(5);
    root2->right=new TreeNode(1);
    root2->left->left=new TreeNode(6);
    root2->left->right=new TreeNode(7);
    root2->right->left=new TreeNode(4);
    root2->right->right=new TreeNode(2);
    root2->right->right->left=new TreeNode(9);
    root2->right->right->right=new TreeNode(8);
    
    cout << leafSimilar(root1,root2);
    return 0;
}