// Leetcode
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            long long int mmin = q.front().second; // to make the id starting from zero
            int first, last;
            for(int i = 0; i<size; i++){
                long long int cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = cur_id;
                if (i == size -1) last = cur_id;
                if(node -> left)
                    q.push({node->left, cur_id * 2 + 1});
                if(node -> right)
                    q.push({node->right, cur_id * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};

// CodeStudio
int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL) return 0;

    queue<pair<TreeNode<int>*, int>> q;
    q.push({root,0});

    int ans=0;
    while(!q.empty())
    {
        int siz = q.size();
        ans=max(ans,siz);
        for(int i=0;i<siz;i++)
        {
            TreeNode<int> *temp = q.front().first;
            int index = q.front().second;
            q.pop();

            if(temp->left)
            q.push({temp->left,2*index+1});

            if(temp->right)
            q.push({temp->right,2*index+2});
        }
    }
    return ans;
}