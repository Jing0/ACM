/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode *node = head;
        while (node != NULL) {
            vec.push_back(node);
            node = node->next;
        }
        srand(seed + vec.size());
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int size = vec.size();
        seed = (int)rand() % size;
        return vec.at(seed)->val;
    }
private:
    vector<ListNode*> vec;
    int seed = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
