#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
/*struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        // Step 1: Build the nodes and relationships
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2] == 1;

            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }

            if (isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }

            children.insert(childVal);
        }

        // Step 2: Identify the root node
        TreeNode* root = nullptr;
        for (const auto& pair : nodes) {
            if (children.find(pair.first) == children.end()) {
                root = pair.second;
                break;
            }
        }

        // Step 3: Return the root of the tree
        return root;
    }
};
