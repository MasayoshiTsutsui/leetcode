#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int idx_pre = 0;
    unordered_map<int, int> val_idx;
public:
    TreeNode* subtree(vector<int>& preorder, vector<int>& inorder, int in_begin, int in_end) {
        if (in_begin >= in_end) {
            return NULL;
        }
        int myval = preorder.at(this->idx_pre);
        int divider = val_idx.at(myval);
        TreeNode* left = subtree(preorder, inorder, in_begin, divider);
        TreeNode* right = subtree(preorder, inorder, divider, in_end);
        TreeNode* me = new TreeNode(inorder.at(0), left, right);
        return me;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            this->val_idx.insert({inorder.at(i), i});
        }

        return subtree(preorder, inorder, 0, inorder.size());
    }
};