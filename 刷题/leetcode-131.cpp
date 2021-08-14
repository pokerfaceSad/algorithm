# include <iostream>
# include <vector>
# include <unordered_map>
# include <queue>
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
    unordered_map<Node*, Node*>  hashMap;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return {};
        // return DFS(node);
        return BFS(node);
    }

    Node* BFS(Node* node) {
        Node* cloneNode = nullptr;
        if (hashMap.count(node)) cloneNode = hashMap[node];
        else {
            cloneNode = new Node(node->val);
            hashMap[node] = cloneNode;
        }
        
        queue<Node*> q;
        q.push(node);
        Node* curNode = nullptr;
        while (!q.empty()) {
            curNode = q.front(); q.pop();
            for (Node* neighbor : curNode->neighbors) {
                Node* cloneNeighbor = nullptr;
                if (hashMap.count(neighbor)) {
                    cloneNeighbor = hashMap[neighbor];
                    hashMap[curNode]->neighbors.push_back(cloneNeighbor);
                } else {
                    cloneNeighbor = new Node(neighbor->val);
                    hashMap[neighbor] = cloneNeighbor;
                    hashMap[curNode]->neighbors.push_back(cloneNeighbor);
                    q.push(neighbor);
                }
            }
        }
        return cloneNode;
    }

    Node* DFS(Node* node) {
        Node* clone_node = nullptr;
        if (hashMap.count(node)) clone_node = hashMap[node];
        else {
            clone_node = new Node(node->val);
            hashMap[node] = clone_node;
        }
        for (Node* neighbor : node->neighbors) {
            Node* clone_neighbor = nullptr;
            if (hashMap.count(neighbor)) {
                clone_neighbor = hashMap[neighbor];
                clone_node->neighbors.push_back(clone_neighbor);
            } else {
                clone_neighbor = new Node(neighbor->val);
                hashMap[neighbor] = clone_neighbor;
                clone_node->neighbors.push_back(clone_neighbor);
                // 仅当该邻节点没有被访问过时才递归访问
                DFS(neighbor);
            }
        }
        return clone_node;
    }
};