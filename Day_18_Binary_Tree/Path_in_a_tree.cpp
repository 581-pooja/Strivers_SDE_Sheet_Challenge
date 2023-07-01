
bool getPath(TreeNode<int>* root, vector<int> &ans, int x){
	if(!root) return false;
	ans.push_back(root->data);
	
	if(root->data == x) return true;
	
	if( (getPath(root->left , ans, x)) || (getPath(root->right, ans, x)) ) return true;

	// backtracking 
	ans.pop_back();
	return false;
}


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
	if(root == NULL) return ans;
	getPath(root, ans, x);
	return ans;
}

