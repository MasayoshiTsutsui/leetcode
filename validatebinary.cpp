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
public:
    bool dfs(TreeNode* node, int maxval, int minval) {
        if (node == NULL) {
            return true;
        }
        
        if (node->val > maxval || node->val < minval) {
            return false;
        }

        bool leftbool = true;
        bool rightbool = true;

        if (node->left != NULL) {
            if (node->val == INT_MIN) {
                return false;
            }
            int newmaxval = min(maxval, node->val - 1);
            leftbool = dfs(node->left, newmaxval, minval);
        }
        if (node->right != NULL) {
            if (node->val == INT_MAX) {
                return false;
            }
            int newminval = max(minval, node->val + 1);
            rightbool = dfs(node->right, maxval, newminval);
        }
        return leftbool && rightbool;
    }
    bool isValidBST(TreeNode* root) {
        bool ans = dfs(root, INT_MAX, INT_MIN);
        return ans;
    }
};