#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_set<Node*> visited;
    unordered_map<Node*, Node*> oldNewAddr;

    void dfs(Node* newnode, Node* oldnode) {
        if (visited.find(oldnode) == visited.end()) {
            visited.insert(oldnode);
        }
        else {
            return;
        }
        vector<Node*> newNeighbors;
        for (Node* neighbor : oldnode->neighbors)
        {
            Node* newNeighbor;
            if (oldNewAddr.find(neighbor) == oldNewAddr.end()) {
                newNeighbor = new Node(neighbor->val);
                oldNewAddr.emplace(neighbor, newNeighbor);
                newnode->neighbors.push_back(newNeighbor);
            }
            else {
                newNeighbor = oldNewAddr.at(neighbor);
                newnode->neighbors.push_back(newNeighbor);
            }
            dfs(newNeighbor, neighbor);
        }
        return;
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        Node* newroot = new Node(node->val);
        dfs(newroot, node);
        for (auto itr = oldNewAddr.begin(); itr != oldNewAddr.end(); itr++)
        {
            if (itr->first == itr->second) {
                cout << "!!" <<endl;
            }
        }
        
        
        return newroot;
        
    }
};