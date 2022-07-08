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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // to minimze space, we will edit the values of both linked lists in place
        // and return the longer list which will have full answer
        
        // create a flag to identify the longer list
        // True : l1
        // False : l2
        bool flag = true;
        
        // two pointers to save the initial node of each list
        ListNode *l1_ptr = l1, *l2_ptr = l2;
        
        // pointer to last node to add and extra carry node
        ListNode *last;
        
        // short variable to temporarely hold the sum 
        short sum;
        
        // create a short to act as a carry
        short carry = 0;
        
        // loop until both linked lists are totally consumed.
        while(l1 != nullptr || l2 != nullptr)
        {
            // load node values
            if( l1 == nullptr)  
            {
                // l2 is the longer list
                flag = false;
                
                sum = l2->val + carry;
                
                if(sum > 9)
                {
                    sum -= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                
                l2->val = sum;   
                
                last = l2;
                l2 = l2->next;
            }
            else if( l2 == nullptr )  
            {
                // l1 is the longer list
                flag = true;
                
                sum = l1->val + carry;
                
                if(sum > 9)
                {
                    sum -= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                
                l1->val = sum;   
            
                last = l1;
                l1 = l1->next;
            }
            else
            {
                // l1 and l2 corresponding nodes
                // update values in both lists
                sum = l1->val + l2->val + carry;
                
                if(sum > 9)
                {
                    sum -= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                
                l1->val = sum;
                l2->val = sum;    
                
                
                last = l1;
                l1 = l1->next;
                l2 = l2->next;
            }
        
            //cout << sum << " : " << carry << endl;
        }
        
        // if there is a remaining carry, create one extra node
        if(carry)
        {
            ListNode *extra = new ListNode;
            extra->val = 1;
            extra->next = nullptr;
            last->next = extra;
        }
        
        
        if(flag)
        {
            //cout << "l1" << endl;
            return l1_ptr;
        }
        else
        {
            //cout << "l2" << endl;
            return l2_ptr;
        }
    }
};