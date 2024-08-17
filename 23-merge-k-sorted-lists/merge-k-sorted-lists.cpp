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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ans  = new ListNode  ( 0) ;
        ListNode * a = ans ;
        map <int , int> mp ;
        for (int i = 0 ; i < lists.size() ;i++){
            ListNode * l = lists[i] ;
            while (l != NULL) {
                mp[l->val]++  ;
                l= l->next ;
            }
        }
        for (auto pair : mp ){
            int key = pair.first ;
            int value = pair.second ;
            while (value != 0){
                ans->next = new ListNode (key) ;
                ans = ans->next ;
                value-- ;
            }
        }
        return a ->next ;
    }
};