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

class BSTIterator {
private:
    stack<TreeNode*> stk;
public:
    void dfs(TreeNode* node){
        if (node == nullptr) {
            return;
        }
        stk.push(node);
        dfs(node->left);
    }

    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if (node->right != nullptr) {
            dfs(node->right);
        }
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */