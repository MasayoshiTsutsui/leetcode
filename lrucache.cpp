#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <list>

using namespace std;


class LRUCache {
private:
    unordered_map<int, list<pair<int,int> >::iterator> key_itr;
    list<pair<int,int> > accessLog;

    int capa;

public:
    LRUCache(int capacity) {
        this->capa = capacity;
    }
    
    int get(int key) {
        if (key_itr.find(key) == key_itr.end()) {
            return -1;
        }
        accessLog.splice(accessLog.begin(), accessLog, key_itr.at(key));
        return key_itr.at(key)->second;
    }
    
    void put(int key, int value) {
    if (key_itr.find(key) == key_itr.end()) {
        accessLog.emplace_front(key, value);
        key_itr.emplace(key, accessLog.begin());
        if (key_itr.size() > this->capa) {
            int erasingkey = accessLog.rbegin()->first;
            key_itr.erase(erasingkey);
            accessLog.pop_back();
        }
        return;
    }
    accessLog.splice(accessLog.begin(), accessLog, key_itr.at(key));
    key_itr.at(key)->second = value;
    }
};