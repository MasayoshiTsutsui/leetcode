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
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        auto comp = [](vector<int> &a, vector<int> &b){
            return a.at(0) < b.at(0);
        };

        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int> > ans;
        vector<int> growingInter = intervals.at(0);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals.at(i).at(0) <= growingInter.at(1)) {
                growingInter.at(1) = max(intervals.at(i).at(1), growingInter.at(1));
            }
            else {
                ans.push_back(growingInter);
                growingInter = intervals.at(i);
            }
        }
        ans.push_back(growingInter);
        return ans;
    }
};