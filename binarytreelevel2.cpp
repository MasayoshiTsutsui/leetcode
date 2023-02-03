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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        
        queue<TreeNode*> node_que;
        queue<int> depth_que;
        node_que.push(root);
        depth_que.push(1);

        while (!node_que.empty())
        {
            TreeNode* node = node_que.front();
            int depth = depth_que.front();
            node_que.pop();
            depth_que.pop();
            if (ans.size() < depth)
            {
                assert(ans.size() == depth -1 );
                ans.push_back(vector<int>());
            }
            ans.at(depth-1).push_back(node->val);
            if (node->left != nullptr)
            {
                node_que.push(node->left);
                depth_que.push(depth + 1);
            }
            if (node->right != nullptr)
            {
                node_que.push(node->right);
                depth_que.push(depth + 1);
            }
        }
        return ans;
    }
};