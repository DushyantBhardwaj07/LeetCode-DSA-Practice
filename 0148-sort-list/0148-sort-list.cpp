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
    ListNode *findMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *head1, ListNode *head2){
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        ListNode *ans = new ListNode(-1);
        ListNode *pp = ans;

        while(p1 != NULL && p2 != NULL){
            if(p1->val <= p2->val){
                ListNode *n = new ListNode(p1->val);                  
                ans->next = n;
                ans = ans->next;
                p1 = p1->next;
            }
            else{
                ListNode *n = new ListNode(p2->val);                  
                ans->next = n;
                ans = ans->next;
                p2 = p2->next;
            }
        }

        while(p1 != NULL){
            ListNode *n = new ListNode(p1->val);                  
            ans->next = n;
            ans = ans->next;
            p1 = p1->next;            
        }

        while(p2 != NULL){
            ListNode *n = new ListNode(p2->val);                  
            ans->next = n;
            ans = ans->next;
            p2 = p2->next;            
        }

        return pp->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p1 = head;        
        ListNode *mid = findMid(head);
        ListNode *mm = head;
        while(mm!=NULL && mm->next != mid){
            mm = mm->next;
        }        
        if(mm!=NULL)mm->next = NULL;
        ListNode *first = sortList(p1);
        ListNode *second = sortList(mid);

        return merge(first, second);
    }
};