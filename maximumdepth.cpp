#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void dfs(TreeNode* node, int mydepth, int* maxdepth) {
        if (node == NULL) {
            return;
        }
        *maxdepth = max(*maxdepth, mydepth);
        dfs(node->left, mydepth+1, maxdepth);
        dfs(node->right, mydepth+1, maxdepth);
    }
    int maxDepth(TreeNode* root) {
        int maxdepth = 0;
        dfs(root, 1, &maxdepth);
        return maxdepth;
    }
};