// https://leetcode.com/problems/linked-list-cycle/
// Time Complexity: O(N)
// Space Complexity; O(1)

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
    bool hasCycle(ListNode *head) {
        ListNode *tortoise=head,*hare=head;
        
        while(tortoise!=NULL && hare!=NULL && hare->next!=NULL) {
            
            tortoise = tortoise->next;            
            hare = hare->next->next;       
            
            if(tortoise==hare) 
                return true;
        }
        
        return false; 
    }
};