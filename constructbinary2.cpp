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
private:
    int preHead = 0;
public:
    TreeNode* subbuilder(vector<int>& preorder, vector<int>& inorder, int inBegin, int inEnd) {
        if (inBegin > inEnd) {
            return NULL;
        }
        int myIdx = find(inorder.begin()+inBegin, inorder.begin()+inEnd+1, preorder.at(this->preHead)) - inorder.begin();
        int myval = preorder.at(this->preHead);
        this->preHead++;
        TreeNode* left = subbuilder(preorder, inorder, inBegin, myIdx-1);
        TreeNode* right = subbuilder(preorder, inorder, myIdx+1, inEnd);
        TreeNode* node = new TreeNode(myval, left, right);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return subbuilder(preorder, inorder, 0, preorder.size()-1);
    }
};