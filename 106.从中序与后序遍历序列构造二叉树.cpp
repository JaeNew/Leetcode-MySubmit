/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (59.32%)
 * Total Accepted:    6.5K
 * Total Submissions: 11K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <set>
#include <iterator>
#include <map>
#include <math.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& inorder, int iLeft, int iRight, vector<int>& postorder, int pLeft, int pRight){
        if(iLeft>iRight || pLeft>pRight) return NULL;
        int i = 0;
        for(i = iLeft; i <= iRight; i++)
        {
            if(inorder[i] == postorder[pRight]) break;
        }
        TreeNode* cur = new TreeNode(postorder[pRight]);
        cur->left = buildTree(inorder, iLeft, i-1, postorder, pLeft, pLeft+i-iLeft-1);
        cur->right = buildTree(inorder, i+1, iRight, postorder, pLeft+i-iLeft, pRight-1);
        return cur;
    }
};
/*
11　　4　　[5]　　13　　8　　9　　　　　　=>　　　　　　　　　 5
11　　4　　13　　  9　　8　 [5]　　　　　　　　　　　　　　　　/　\
*/
