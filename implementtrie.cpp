#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Trie {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* nextChar[26];
    };

    TrieNode* root;

    void initNode(TrieNode* node) {
        node->isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            node->nextChar[i] = nullptr;
        }
    }

public:
    Trie() {
        root = new TrieNode;
        initNode(root);
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char c = word.at(i);
            if (node->nextChar[c-'a'] == nullptr) {
                TrieNode* nextnode = new TrieNode;
                initNode(nextnode);
                node->nextChar[c-'a'] = nextnode;
                node = nextnode;
            }
            else {
                node = node->nextChar[c-'a'];
            }
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char c = word.at(i);
            if (node->nextChar[c-'a'] == nullptr) {
                return false;
            }
            else {
                node = node->nextChar[c-'a'];
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            char c = prefix.at(i);
            if (node->nextChar[c-'a'] == nullptr) {
                return false;
            }
            else {
                node = node->nextChar[c-'a'];
            }
        }
        return true;
    }
};
