#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> emailset;

        for (int i = 0; i < emails.size(); i++)
        {
            string adr = emails.at(i);
            string forwarded = "";
            bool isInDomain = false;
            bool plusflag = false;

            for (int j = 0; j < adr.size(); j++)
            {
                char c = adr.at(j);
                if (c == '@'){
                    isInDomain = true;
                    forwarded += c;
                }
                else if (!isInDomain) {
                    if (plusflag) {
                        continue;
                    }
                    else if (c == '.') {
                        continue;
                    }
                    else if (c == '+') {
                        plusflag = true;
                    }
                    else {
                        forwarded += c;
                    }
                }
                else {
                    forwarded += c;
                }
            }
            emailset.insert(forwarded);
        }
        return emailset.size();
    }
};