#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
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
    queue<pair<int,TreeNode*>> que;
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        que.push({0, root});
        int level = -1;

        while (!que.empty())
        {
            pair<int, TreeNode*> p = que.front();
            que.pop();
            int nlevel = p.first;
            TreeNode* node = p.second;
            if (level < nlevel) {
                ans.push_back({});
                level = nlevel;
            }
            if (node->left != nullptr) {
                que.push({level + 1, node->left});
            }
            if (node->right != nullptr) {
                que.push({level + 1, node->right});
            }
            ans.at(level).push_back(node->val);
        }
        return ans;
    }
};