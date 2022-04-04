#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include<numeric>

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

/*
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        TreeNode *node = new TreeNode(preorder.front());

        auto p = std::find(inorder.begin(), inorder.end(), node->val);
        vector<int> inLeft = vector<int>(inorder.begin(),p);
        vector<int> inRight = vector<int>(++p,inorder.end());

        vector<int> preLeft = vector<int>(++preorder.begin(),++preorder.begin() + inLeft.size());
        vector<int> preRight = vector<int>(++preorder.begin() + preLeft.size(),preorder.end());

        node->left = buildTree(preLeft,inLeft);
        node->right = buildTree(preRight,inRight);

        return node;

    }
};


int main(){
    TreeNode root(1);
    TreeNode node2(2);

    vector<int> in{3,9,20,15,7};
    vector<int> po{9,3,15,20,7};


    Solution solution;
    solution.buildTree(in,po);

}