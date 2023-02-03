#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    void dfscheck(vector<vector<int> >& ans, vector<int>& candidates, vector<int>& comb, int target, int head) {
        if (target == 0){
            ans.push_back(comb);
            return;
        }
        else if (target < 0){
            return;
        }

        for (int i = head; i < candidates.size(); i++)
        {
            int nextcand = candidates.at(i);
            comb.push_back(nextcand);
            dfscheck(ans, candidates, comb, target-nextcand, i);
            comb.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        dfscheck(ans, candidates, comb, target, 0);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int> > > sum_comb(target+1);

        for (int i = 0; i < candidates.size(); i++)
        {
            int cand = candidates.at(i);
            vector<int> comb({candidates.at(i)});
            sum_comb.at(cand).push_back(comb);
        }

        for (int sum = 1; sum <= target; sum++)
        {
            for (int i = 0; i < candidates.size(); i++)
            {
                int cand = candidates.at(i);
                if (cand <= sum) {
                    vector<vector<int> > combs = sum_comb.at(sum - cand);
                    for (int j = 0; j < combs.size(); j++)
                    {
                        vector<int> comb = combs.at(j);
                        comb.push_back(cand);
                        sum_comb.at(sum).push_back(comb);
                    }
                }
            }
        }
        vector<vector<int> > ansvecs = sum_comb.at(target);
        unordered_set<vector<int> > vecset;
        for (int i = 0; i < ansvecs.size(); i++)
        {
            vector<int> v = ansvecs.at(i);
            sort(v.begin(), v.end());
            vecset.insert(v);
        }
        vector<vector<int> > ans;
        for (auto itr = vecset.begin(); itr != vecset.end(); itr++)
        {
            ans.push_back(*itr);
        }
        

        return sum_comb.at(target);
    }
};