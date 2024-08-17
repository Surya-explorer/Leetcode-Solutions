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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode * l1 = list1 ;
        ListNode * l2 = list2 ;
        
        ListNode * l = new ListNode (0) ;
        ListNode * ans = l  ;

        int size1 = 0 ;
        int size2 = 0 ;
        
        // if (l1 )
        // for (int i = 0 ; i < ())
        while (l1 != NULL && l2!= NULL){

            if (l1->val >= l2->val){
                l->next = new ListNode (l2->val) ;
                l = l->next ;
                l2 = l2 ->next ;
            }
            else {
                l->next = new ListNode (l1->val) ;
                l = l->next ;
                l1 = l1 ->next ;
            }
        }
        while (l1 != NULL) {
            l->next = new ListNode (l1->val) ;
            l1 = l1->next ;
            l = l->next ;
        }
        while (l2 != NULL) {
            l->next = new ListNode (l2->val) ;
            l2 = l2->next ;
            l = l->next ;
        }

        return ans->next ;
    }
};