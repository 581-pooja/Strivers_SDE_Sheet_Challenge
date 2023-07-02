#include <bits/stdc++.h> 

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int>ans;
    map <int, map<int, multiset<int>>> nodes;

    queue <pair<TreeNode<int>* , pair<int,int>>> todo;
    todo.push({root, {0, 0}});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();

        TreeNode<int> *node = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(node->data);

        if(node->left){
            todo.push({node->left, {x-1, y+1}});
        }

        if(node->right){
            todo.push({node->right, {x+1, y+1}});
        }
    }

    for(auto i: nodes){
        cout<<i.first<<" ";
        for(auto j: i.second){
            cout<<j.first<<" ";
            for(auto k: j.second){
                cout<<k<<endl;
                ans.push_back(k);
            }
        }
    }
    return ans;

}

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int, int>>> todo;
        todo.push({root, {0,0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int v = p.second.first;
            int h = p.second.second;
            nodes[v][h].insert(node->val);
            if(node->left){
                todo.push({node->left, {v-1, h+1}});
            }
            if(node->right){
                todo.push({node->right, {v+1, h+1}});
            }
        }
        
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector <int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;

    }
};