#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<int> > adjac;
    void dfsFarLeaf(int parent, int node, int depth, int &maxdepth, int &farestLeaf) {
        if (depth >= maxdepth) {
            farestLeaf = node;
            maxdepth = depth;
        }
        for (int i = 0; i < adjac.at(node).size(); i++)
        {
            int neighbor = adjac.at(node).at(i);
            if (neighbor == parent){
                continue;
            }
            dfsFarLeaf(node, neighbor, depth+1, maxdepth, farestLeaf);
        }
    }
    void dfsDistFromFarestL(int parent, int node, int depth, int &maxdepth) {
        maxdepth = max(depth, maxdepth);
        for (int i = 0; i < adjac.at(node).size(); i++)
        {
            int neighbor = adjac.at(node).at(i);
            if (neighbor == parent){
                continue;
            }
            dfsDistFromFarestL(node, neighbor, depth+1, maxdepth);
        }
    }
    void dfsRoot(int parent, int node, int depth, vector<int> &traject, int maxdepth, set<int> &ans) {
        traject.push_back(node);
        if (depth == maxdepth) {
            int root1 = maxdepth / 2;
            int root2 = (maxdepth + 1) / 2;

            ans.insert(traject.at(root1));
            if (root1 != root2) {
                ans.insert(traject.at(root2));
            }
        }
        for (int i = 0; i < adjac.at(node).size(); i++)
        {
            int neighbor = adjac.at(node).at(i);
            if (neighbor == parent){
                continue;
            }
            dfsRoot(node, neighbor, depth+1, traject, maxdepth, ans);
        }
        traject.pop_back();
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n==1) {
            ans.push_back(0);
            return ans;
        }
        adjac.resize(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges.at(i).at(0);
            int v = edges.at(i).at(1);
            adjac.at(u).push_back(v);
            adjac.at(v).push_back(u);
        }
        int maxdepth = 0;
        int farestLeaf = -1;
        dfsFarLeaf(-1, 0, 0, maxdepth, farestLeaf);
        dfsDistFromFarestL(-1, farestLeaf, 0, maxdepth);
        vector<int> traject;
        set<int> ans_;
        dfsRoot(-1, farestLeaf, 0, traject, maxdepth, ans_);
        for (auto itr = ans_.begin(); itr != ans_.end(); itr++)
        {
            ans.push_back(*itr);
        }
        
        return ans;
    }
};