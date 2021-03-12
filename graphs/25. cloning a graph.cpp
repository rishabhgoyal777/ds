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
    void dfs(Node* node, map<Node*,Node*> &mp, set<Node*> &vis){
        if(!node) return;

        vis.insert(node);
        Node* nodeCopy=new Node(node->val);
        mp.insert({node,nodeCopy});

        for(auto v: node->neighbors){
           if(vis.find(v)==vis.end())
            dfs(v,mp,vis);
        }
    }

    Node* cloneGraph(Node* node) {
       map<Node*,Node*> mp;    //
       set<Node*> vis;  // vis ka set liya. kyomki ab 1 2 3 nhi hai adresses hai alg. aur Set mein unique elements hi hote hai.
       dfs(node,mp,vis); // dfs se map bna liya jisme node as key and uski copy as value hai. Copy ke neighbors empty hai abhi.

//ab copy nodes mei neighbours add krne hai. node ke jo neighbour hai unki map mei jo value hai usko copynode mei push krna
       for(auto i: mp){
           for(auto j: i.first->neighbors){
               i.second->neighbors.push_back(mp[j]);
           }
       }
       return mp[node];
    }
};
