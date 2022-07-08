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
    ListNode* middleNode(ListNode* head) {
        // using two runner-pointers algorithm
        // while the faster pointer takes two steps,
        // the slower pointer take one step
        // when the faster pointer reaches the end,
        // the slower pointer should be at middle.
        
        ListNode *fast_runner = head, *slow_runner = head;
        bool toggle = false;
        
        while(fast_runner != nullptr)
        {
            
            //cout << "Fast: " << fast_runner->val << "  Slow: " << slow_runner->val << endl;
            
            fast_runner = fast_runner->next;
            
            if( toggle )
                slow_runner = slow_runner->next;
            
            toggle = !toggle;
            
        }
        
        return slow_runner;
    }
};