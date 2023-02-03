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
    void dfsmerge(TreeNode* root1, TreeNode* root2) {
        if (root1->left == NULL && root2->left != NULL) {
            root1->left = root2->left;
        }
        else if (root1->left != NULL && root2->left != NULL) {
            root1->left->val += root2->left->val;
            dfsmerge(root1->left, root2->left);
        }

        if (root1->right == NULL && root2->right != NULL) {
            root1->right = root2->right;
        }
        else if (root1->right != NULL && root2->right != NULL) {
            root1->right->val += root2->right->val;
            dfsmerge(root1->right, root2->right);
        }
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) {
            return root2;
        }
        if (root2 == NULL) {
            return root1;
        }
        root1->val += root2->val;
        dfsmerge(root1, root2);
        return root1;
    }
};