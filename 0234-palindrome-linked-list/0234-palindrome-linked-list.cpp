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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *head2=slow->next;

        slow->next=NULL;
        ListNode* curr = head2;
        ListNode* prev = NULL;

        while(curr!=NULL){
            ListNode *next=curr->next;

            curr->next=prev;
            prev=curr;
            curr=next;

        }
        
        head2 = prev;

        while(head2!=NULL && head!=NULL){
            if(head2->val != head->val){
                return false;
            }
            head2=head2->next;
            head=head->next;
        }
        return true;
    }
};