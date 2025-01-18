class Solution {
public:
    TreeNode* first = NULL;
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(root==NULL) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        markParent(root->left, parent);
        markParent(root->right, parent);
    }
    void find(TreeNode* root, int start) {
        if(root==NULL) return;
        if(root->val==start) {
            first = root;
            return;
        };
        find(root->left, start);
        find(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        // step 1 : find node with given value 'start'
        find(root, start);

        // step 2 : mark the parent value
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        // step 3 : making isInfected map
        unordered_set<TreeNode*> s;
        s.insert(first);
        queue< pair<TreeNode*, int> > q;
        // pair<TreeNode*, int> p;
        // p.first = first;
        // p.second = 0;
        q.push({first, 0});
        int maxLevel = 0;

        // bfs
        while(q.size()>0) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            int level = p.second;
            maxLevel = max(maxLevel, level);
            TreeNode* temp = p.first;
            // check for the child's of the root are infected or not
            if(temp->left) {
                if(s.find(temp->left)==s.end()) {
                    q.push({temp->left, level+1});
                    s.insert(temp->left);
                }
            }
            if(temp->right) {
                if(s.find(temp->right)==s.end()) {
                    q.push({temp->right, level+1});
                    s.insert(temp->right);
                }
            }
            // check for child's parent
            if(parent.find(temp)!=parent.end()) {   // agar parent mila node ka to use bhi infected set m dalo
                if(s.find(parent[temp])==s.end()) {
                    q.push({parent[temp], level+1});
                    s.insert(parent[temp]);
                }
            }
        }
        return maxLevel;
    }
};