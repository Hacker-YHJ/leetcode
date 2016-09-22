class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    findPaths(root, sum);
    return paths;
  }
private:
  vector<int> path;
  vector<vector<int> > paths;
  void findPaths(TreeNode* node, int sum) {
    if (!node) return;
    path.push_back(node -> val);
    if (!(node -> left) && !(node -> right) && sum == node -> val)
      paths.push_back(path);
    findPaths(node -> right, sum - node -> val);
    findPaths(node -> left, sum - node -> val);
    path.pop_back();
  }
};
