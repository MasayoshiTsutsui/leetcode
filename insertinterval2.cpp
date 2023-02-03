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
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        bool mergingflag = false;
        bool mergedflag = false;
        vector<int> mergingInterv = {0, 0};
        for (int i = 0; i < intervals.size(); i++)
        {
            if (mergedflag) {
                ans.push_back(intervals.at(i));
            }
            else if (!mergingflag) {
                if (intervals.at(i).at(1) < newInterval.at(0)) {
                    ans.push_back(intervals.at(i));
                }
                else {
                    if (intervals.at(i).at(0) > newInterval.at(1)) { // not interleaving
                        ans.push_back(newInterval);
                        ans.push_back(intervals.at(i));
                        mergedflag = true;
                    }
                    else { // interleaving
                        mergingInterv.at(0) = min(intervals.at(i).at(0), newInterval.at(0));
                        mergingInterv.at(1) = max(intervals.at(i).at(1), newInterval.at(1));
                        mergingflag = true;
                    }
                }
            }
            else {
                if (mergingInterv.at(1) < intervals.at(i).at(0)) {
                    ans.push_back(mergingInterv);
                    ans.push_back(intervals.at(i));
                    mergedflag = true;
                }
                else {
                    mergingInterv.at(0) = min(intervals.at(i).at(0), mergingInterv.at(0));
                    mergingInterv.at(1) = max(intervals.at(i).at(1), mergingInterv.at(1));
                }
            }
        }
        if (!mergingflag && !mergedflag) {
            ans.push_back(newInterval);
        }
        if (mergingflag && !mergedflag) {
            ans.push_back(mergingInterv);
        }
        return ans;
    }
};