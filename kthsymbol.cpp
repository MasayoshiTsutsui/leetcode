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
    int stepFootPrint(vector<int> &footprints) {
        int bin = 0;
        for (int i = 0; i < footprints.size(); i++)
        {
            if (footprints.at(i) == 0)
            {
                if (bin == 0)
                {
                    bin = 0;
                }
                else
                {
                    bin = 1;
                }
            }
            else
            {
                if (bin == 0)
                {
                    bin = 1;
                }
                else
                {
                    bin = 0;
                }
            }
        }
        return bin;
        
    }
    void getFootPrint(int n, int k, vector<int> &footprints) {
        if (n == 0)
        {
            return;
        }
        if (k % 2 == 0)
        {
            footprints.at(n-1) = 1;
            getFootPrint(n-1, k / 2, footprints);
        }
        else
        {
            footprints.at(n-1) = 0;
            getFootPrint(n-1, (k+1) / 2, footprints);
        }
    }



    int kthGrammar(int n, int k) {
        vector<int> footprints(n-1);

        getFootPrint(n-1, k, footprints);

        int ans = stepFootPrint(footprints);
        return ans;
    }
};