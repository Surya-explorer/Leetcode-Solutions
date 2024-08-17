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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head ;
        ListNode* a1 =  new ListNode ( 0) ;
        ListNode* ans = a1 ;

        vector <int > a ;
        while (temp != NULL){
            a.push_back(temp->val) ;
            temp = temp ->next ;
        }
        int size =  a.size() ;
        for (int i = 0 ; i+1 < a.size()  ;  ){
            int t = a[i] ;

            a[i] = a[i+1] ;
            a[i+1]  = t ;

            i+=2  ;
        } 

        for (int i = 0 ; i < a.size() ; i++) {
            a1  ->next = new ListNode (a[i]) ;
            a1 = a1->next ;
        }
        return ans->next ;
    }
};