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
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        int x = -1; int y = 0;
        int h = matrix.size(); int w = matrix.at(0).size();
        int horizmove = w;
        int virtmove = h-1;

        while(1) {
            if (horizmove <= 0) {
                break;
            }
            for (int i = 0; i < horizmove; i++)
            {
                x++;
                ans.push_back(matrix.at(y).at(x));
            }
            horizmove--;
            if (virtmove <= 0) {
                break;
            }
            for (int i = 0; i < virtmove; i++)
            {
                y++;
                ans.push_back(matrix.at(y).at(x));
            }
            virtmove--;
            if (horizmove <= 0) {
                break;
            }
            for (int i = 0; i < horizmove; i++)
            {
                x--;
                ans.push_back(matrix.at(y).at(x));
            }
            horizmove--;
            if (virtmove <= 0) {
                break;
            }
            for (int i = 0; i < virtmove; i++)
            {
                y--;
                ans.push_back(matrix.at(y).at(x));
            }
            virtmove--;
        }
        return ans;
    }
};