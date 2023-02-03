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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> dp;
        
        for (int i = 0; i < wordList.size(); i++)
        {
            dp.emplace(wordList.at(i), 999999);
        }
        if (dp.find(endWord) == dp.end()) {
            return 0;
        }
        
        queue<pair<string, int> > que;
        que.emplace(beginWord, 1);

        while(!que.empty()) {
            int depth = que.front().second;
            string word = que.front().first;
            que.pop();

            for (int i = 0; i < word.size(); i++)
            {
                char replaced = word.at(i);
                for (int j = 0; j < 26; j++)
                {
                    word.at(i) = 'a' + j;
                    if (dp.find(word) != dp.end()) {
                        if (dp.at(word) > depth+1) {
                            dp.at(word) = depth+1;
                            que.emplace(word, depth+1);
                        }
                    }
                }
                word.at(i) = replaced;
            }
        }
        if (dp.at(endWord) == 999999) {
            return 0;
        }
        else {
            return dp.at(endWord);
        }
    }
};