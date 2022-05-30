// https://leetcode.com/problems/merge-k-sorted-lists/
// Time Complexity: O(N*log(N))
// Space Complexity; O(N)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        
        for(auto headValue : lists) {
            if(headValue) {
                pq.push(headValue);
            }
        }
        
        ListNode head(0);
        ListNode *tail = &head;

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next)
            {
                pq.push(temp->next);
            }
        }

        tail->next = NULL;

        return head.next;
    }
};