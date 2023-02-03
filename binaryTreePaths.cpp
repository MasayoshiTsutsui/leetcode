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
public:
    void dfs (vector<string>&ans, string path, TreeNode* node) {
        path = path + to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(path);
            return;
        }

        if (node->left != nullptr) {
            dfs(ans, path + "->", node->left);
        }
        if (node->right != nullptr) {
            dfs(ans, path + "->", node->right);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr) {
            return ans;
        }
        dfs(ans, "", root);
        return ans;
    }
};