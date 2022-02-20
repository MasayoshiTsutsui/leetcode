#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
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
public:
    void dfs(TreeNode* node, int mydepth, int* mindepth) {
        if (node->left == NULL && node->right == NULL) {
            *mindepth = min(*mindepth, mydepth);
            return;
        }
        if (node->left != NULL) {
            dfs(node->left, mydepth+1, mindepth);
        }
        if (node->right != NULL) {
            dfs(node->right, mydepth+1, mindepth);
        }
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int mindepth = 9999999;
        dfs(root, 1, &mindepth);
        return mindepth;
    }
};