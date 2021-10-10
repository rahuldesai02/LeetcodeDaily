//19. Remove Nth Node From End of List
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
    
        if(head==nullptr)
            return head;
        // Calculate Total no of nodes
        int total = 1;
        ListNode* curr=head;
        while(curr->next!=nullptr)
        {
            curr = curr->next;
            total++;
        }
        curr=head;
        //One node previous to be deleted
        n=total-n+1;
        if(n==1)
        {
            head=curr->next;
            delete(curr);
        }
        else{
            for(int i=1;i<n-1;i++)
            curr=curr->next;
            ListNode* del = curr->next;
            if(del==nullptr)
            {
                curr->next=nullptr;
            }
            else
            {
                curr->next = del->next;
            }
            delete(del);
        }
        return head;
    }
};