/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        int size = nums.size();
        TreeNode *head = new TreeNode(nums.at((size - 1) / 2));
        {
            vector<int> vec(nums.begin(), nums.begin() + (size - 1) / 2);
            head->left = sortedArrayToBST(vec);
        }
        {
            vector<int> vec(nums.begin() + (size + 1) / 2, nums.end());
            head->right = sortedArrayToBST(vec);
        }
        return head;
    }
};
