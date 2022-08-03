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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* Using two-pointer technique */
        ListNode follower_node(0, head);
        ListNode *leader = head, *follower = &follower_node;
        
        // give the leader an advantage
        for(int i = 0; i < n; i++)
        {
            leader = leader->next;
        }
        
        // move both pointer step by step until the leader reaches the end
        while(leader != nullptr)
        {
            leader = leader->next;
            follower = follower->next;
        }
        
        // remove follower->next (nth node from the end)
        if(follower->next == head)
        {
            return head->next;
        }
        else
        {
            follower->next = follower->next->next;
            return head;
        }
    }
};