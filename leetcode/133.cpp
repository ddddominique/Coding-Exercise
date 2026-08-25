/*
// Definition for a Node.
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
*/

class Solution {
    unordered_map<Node*, Node*> copied;
    Node* dfs(Node* node) {
        if (copied.count(node)) {
            return copied[node];
        }
        Node* myNode = new Node(node->val);
        copied[node] = myNode;
        for(Node* neighbor : node->neighbors) {
            Node* copy = dfs(neighbor);
            myNode->neighbors.push_back(copy);
        }
        return myNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        return dfs(node);
    }
};