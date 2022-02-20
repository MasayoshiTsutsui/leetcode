#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> word_dist;
        queue<string> que;

        word_dist.emplace(beginWord, 1);
        for (int i = 0; i < wordList.size(); i++)
        {
            word_dist.emplace(wordList.at(i), 999999999);
        }

        que.push(beginWord);

        while(!que.empty())
        {
            string baseword = que.front();
            que.pop();
            int basedist = word_dist.at(baseword);

            for (int i = 0; i < baseword.size(); i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    string onechanged = baseword;
                    if (baseword.at(i) != 'a' + j) {
                        onechanged.at(i) = 'a' + j;
                        cout << onechanged << ", " << baseword << endl;

                        if (word_dist.find(onechanged) != word_dist.end()) {
                            if (basedist + 1 < word_dist.at(onechanged)) {
                                word_dist.at(onechanged) = basedist + 1;
                                que.push(onechanged);
                            }
                        }
                    }
                }
            }
        }
        if (word_dist.find(endWord) == word_dist.end() || word_dist.at(endWord) == 999999999) {
            return 0;
        }
        else {
            return word_dist.at(endWord);
        }
    }
};