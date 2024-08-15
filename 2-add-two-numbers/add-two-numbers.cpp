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
        ListNode * n1 = l1 ;
        ListNode * n2 = l2 ;
        int carry = 0 ;
        ListNode * ans  = new ListNode (0);
        ListNode * temp  = ans ;
        while (n1 != NULL || n2 != NULL){
            int sum = carry  ;
            if (n1 != NULL) {
                sum  += n1->val  ;
                n1 = n1 -> next ;
            } 
            if (n2 != NULL) {
                sum  += n2 ->val ;
                n2 = n2 -> next ;
            }
            
            carry =  sum/10 ;
            ListNode * n = new ListNode (sum%10) ;
            temp ->next =  n ;
            temp = temp ->next ;
        }
        if (carry != 0 ) temp ->next = new ListNode (carry) ;
        return ans->next ;
    }
};