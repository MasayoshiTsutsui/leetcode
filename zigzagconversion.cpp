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
    string convert(string s, int numRows) {
        vector<string> sgrid(numRows);
        int sHead = 0;
        int colModRow = 0;

        if (numRows == 1) {
            return s;
        }

        while (sHead < s.size()) {
            for (int i = 0; i < numRows; i++)
            {
                if (sHead >= s.size()) {
                    break;
                }
                if (colModRow == 0) {
                    sgrid.at(i).push_back(s.at(sHead));
                    sHead++;
                }
                else {
                    if (i % numRows != numRows - 1 - colModRow) {
                        sgrid.at(i).push_back(' ');
                    }
                    else {
                        sgrid.at(i).push_back(s.at(sHead));
                        sHead++;
                    }
                }
            }
            colModRow = (colModRow + 1) % (numRows-1);
        }
        string ans = "";
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < sgrid.at(i).size(); j++)
            {
                if (sgrid.at(i).at(j) != ' ') {
                    ans.push_back(sgrid.at(i).at(j));
                }
            }
        }
        return ans;
    }
};