/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(curNode == NULL){
                s.append("#,");
            } 
            else{
                s.append(to_string(curNode->val) + ',');
            }
            if(curNode != NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // if the string or data is empty string
        if(data.size() == 0) return NULL;
        
        // stringstream converts a string into stream
        stringstream s(data);
        string str;
        // getline everytime returns str from the stringstream using separator 
        getline(s,str,',');
        // stoi () stands for string to integer
        TreeNode* root = new TreeNode(stoi(str));
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            // for left Node
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode (stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            // for right Node
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode (stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));