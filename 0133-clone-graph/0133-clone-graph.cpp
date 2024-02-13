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
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        Node* root= new Node(node->val);
        mp[node] = root;
        for(auto it : node->neighbors){
            if(mp.find(it) == mp.end()){
                Node * cur = cloneGraph(it);
                root->neighbors.push_back(cur);
            }
            else root->neighbors.push_back(mp[it]);
        }
        return root;
    }
};