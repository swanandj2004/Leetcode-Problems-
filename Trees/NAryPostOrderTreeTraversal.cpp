#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode {
    public:
    int val;
    vector<TreeNode*>children;

    TreeNode(int v) {
        val=v;
    }
};

vector<int>postorderTraversal(TreeNode *root) {
    if(root==NULL) {
        return {};
    }

    vector<int>v;

    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()) {
        TreeNode *current=st.top();
        st.pop();
        v.push_back(current->val);
        for(int i=0; i<current->children.size(); i=i+1) {
            if(current->children.at(i)) {
                st.push(current->children.at(i));
            }
        }
    }

    reverse(v.begin(),v.end());
    return v;
}

int main() {
    TreeNode *root=new TreeNode(1);
    TreeNode *firstchild=new TreeNode(3);
    TreeNode *secondchild=new TreeNode(2);
    TreeNode *thirdchild=new TreeNode(4);
    TreeNode *firstfirstchild=new TreeNode(5);
    TreeNode *firstsecondchild=new TreeNode(6);

    root->children.push_back(firstchild);
    root->children.push_back(secondchild);
    root->children.push_back(thirdchild);
    firstchild->children.push_back(firstfirstchild);
    firstchild->children.push_back(firstsecondchild);

    vector<int>v=postorderTraversal(root);
    for(int i=0; i<v.size(); i=i+1) {
        cout << v.at(i) << " ";
    }

    return 0;
}