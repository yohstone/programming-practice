#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//给定如下二叉树，以及目标和 sum = 22，
//
//5
/// \
//4   8
///   / \
//11  13  4
///  \      \
//7    2      1
//返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
//
//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//
//Note: A leaf is a node with no children.
//
//Example:
//
//Given the below binary tree and sum = 22,
//
//5
/// \
//4   8
///   / \
//11  13  4
///  \      \
//7    2      1
//return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法1：递归法，新 sum 等于 sum 减去当前节点的值，然后递归判断其左右子节点，直到叶子节点
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return false;
        }
        sum = sum - root->val;
        if(root->left == nullptr && root->right == nullptr){
            return sum == 0;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
    
    // 方法2：迭代法
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return false;
        }
        stack<pair<TreeNode *, int> > treeStack;
        treeStack.push({root, sum});
        while(!treeStack.empty()){
            TreeNode* curNode = treeStack.top();
            treeStack.pop();
            if(curNode.left == nullptr && curNode.right == nullptr){ // 当前节点是叶子节点
                if(sum - curNode.val == 0){
                    return true;
                }else{
                    return false;
                }
            }
            if(curNode.left != nullptr){
                treeStack.push({curNode.left, sum - curNode.val});
            }
        }
        
    }
};
int main(){

	return 0;
}
