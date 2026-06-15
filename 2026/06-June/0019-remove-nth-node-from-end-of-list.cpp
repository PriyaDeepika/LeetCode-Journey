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
        ListNode *temp = head;
        int length = 0;
        while(temp){
            length++;
            temp=temp->next;
        }

        int pos = length-n+1;
        if(pos == 1){
            return head->next;
        }

        ListNode *p = head;
        for(int i=1; i <pos-1; i++){
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};
