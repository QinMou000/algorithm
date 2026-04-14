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
        if (!root)
            return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front) {
                q.push(front->left);
                q.push(front->right);
                ans += to_string(front->val) + ",";
            } else
                ans += "NULL,";
        }
        ans.pop_back();
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        string item;
        vector<string> node_val;
        // 把每一个值提取到数组里面
        while (getline(ss, item, ','))
            node_val.push_back(item);
        TreeNode* root = new TreeNode(stoi(node_val[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1; // 遍历node_val专用
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            // 左右节点按顺序来
            if (node_val[i] != "NULL") {
                front->left = new TreeNode(stoi(node_val[i]));
                q.push(front->left);
            }
            i++;
            if (node_val[i] != "NULL") {
                front->right = new TreeNode(stoi(node_val[i]));
                q.push(front->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));