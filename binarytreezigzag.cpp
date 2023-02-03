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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        stack<pair<TreeNode*, int> > stacks[2];
        stacks[0].emplace(root, 0);
        int stackidx = 0;
        int maxdepth = -1;
        while (!stacks[0].empty() || !stacks[1].empty())
        {
            TreeNode* node = stacks[stackidx].top().first;
            int depth = stacks[stackidx].top().second;
            stacks[stackidx].pop();
            if (node != NULL)
            {
                if (depth > maxdepth)
                {
                    ans.push_back({});
                    maxdepth = depth;
                }

                ans.at(depth).push_back(node->val);

                if (depth % 2 == 0)
                {
                    stacks[(stackidx+1) % 2].emplace(node->left, depth+1);
                    stacks[(stackidx+1) % 2].emplace(node->right, depth+1);
                }
                else {
                    stacks[(stackidx+1) % 2].emplace(node->right, depth+1);
                    stacks[(stackidx+1) % 2].emplace(node->left, depth+1);
                }
            }
            if (stacks[stackidx].empty())
            {
                stackidx = (stackidx+1) % 2;
            }
        }
        return ans;
    }
};