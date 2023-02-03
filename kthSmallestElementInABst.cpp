#include <vector>
#include <set>
#include <map>
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
    void dfs(TreeNode* node, int& k, int& ans) {
        if (node->left != nullptr) {
            dfs(node->left, k, ans);
        }
        if (k == 1) {
            ans = node->val;
            k--;
            return;
        }
        else if (k < 1) {
            return;
        }
        k--;
        if (node->right != nullptr) {
            dfs(node->right, k, ans);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        dfs(root, k, ans);
        
        return ans;
    }
};