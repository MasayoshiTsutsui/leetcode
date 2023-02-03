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
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = false;
        unordered_set<string> wordSet;
        for (int i = 0; i < wordDict.size(); i++)
        {
            wordSet.insert(wordDict.at(i));
        }
        
        vector<string> remainLiteral(1, "");
        for (int i = 0; i < s.size(); i++)
        {
            char c = s.at(i);
            int applicantnum = remainLiteral.size();
            bool foundflag = false;

            for (int j = 0; j < applicantnum; j++)
            {
                string rL = remainLiteral.at(j) + c;
                remainLiteral.at(j) = rL; 
                if (!foundflag && wordSet.find(rL) != wordSet.end())
                {
                    remainLiteral.push_back("");
                    if (i == s.size() - 1)
                    {
                        ans = true;
                    }
                    foundflag = true;
                }
            }
        }
        return ans;
    }
};