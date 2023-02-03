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
    bool is_crossing(vector<int> &a, vector<int> &b) {
        bool notCrossing = a.at(0) > b.at(1) || a.at(1) < b.at(0);
        return !notCrossing;
    }

    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        bool startInsert = false;
        bool endInsert = false;
        vector<int> growingInter = {-1, -1};

        for (int i = 0; i < intervals.size(); i++)
        {
            if (endInsert) {
                ans.push_back(intervals.at(i));
            }
            else if (!startInsert && newInterval.at(1) <  intervals.at(i).at(0)) {
                ans.push_back(newInterval);
                ans.push_back(intervals.at(i));
                startInsert = true;
                endInsert = true;
            }
            else if (!startInsert && !is_crossing(intervals.at(i), newInterval)) {
                ans.push_back(intervals.at(i));
                continue;
            }
            else if (!startInsert && is_crossing(intervals.at(i), newInterval)) {
                growingInter.at(0) = min(intervals.at(i).at(0), newInterval.at(0));
                growingInter.at(1) = max(intervals.at(i).at(1), newInterval.at(1));
                startInsert = true;
            }
            else if (startInsert && is_crossing(growingInter, intervals.at(i))) {
                growingInter.at(1) = max(intervals.at(i).at(1), growingInter.at(1));
            }
            else if (startInsert && !is_crossing(growingInter, intervals.at(i))) {
                ans.push_back(growingInter);
                ans.push_back(intervals.at(i));
                growingInter.at(0) = -1;
                endInsert = true;
            }
            else {
                ans.push_back(intervals.at(i));
            }
        }
        if (!startInsert) {
            ans.push_back(newInterval);
        }
        if (growingInter.at(0) != -1) {
            ans.push_back(growingInter);
        }
        return ans;
    }
};