/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for(auto &d: descriptions){
            int parent = d[0];
            int child = d[1];
            int isleft = d[2];

            if(nodes.find(parent) == nodes.end()){
                nodes[parent] = new TreeNode(parent);
            }
            if(nodes.find(child) == nodes.end()){
                nodes[child] = new TreeNode(child);
            }
            if(isleft){
                nodes[parent]-> left = nodes[child];
            } else{
                nodes[parent]->right = nodes[child];
            }
            children.insert(child);
        }

        for(auto &d: descriptions){
            int parent = d[0];
            if(children.find(parent) == children.end()){
                return nodes[parent];
            }
        }
        return nullptr;
    }
};
