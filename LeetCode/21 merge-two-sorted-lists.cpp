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
        ListNode *p = list1, *q = list2;
        ListNode *head;
        if(p && q)
            head = (list1->val < list2->val) ? list1:list2;
        else if(p)
        {
            return p;
        }
        else if(q)
            return q;
        else
            return nullptr;
        ListNode *tail = new ListNode();
        while(p && q)
        {
            if(p && q && p->val < q->val)
            {
                tail->next = p;
                tail = p;
                p = p->next;
            }
            else if(p && q && p->val >= q->val)
            {
                tail->next = q;
                tail = q;
                q = q->next;
            }
        }
        if(p == nullptr)
        {
            tail->next = q;
        }
        else
        {
            tail->next = p;
        }
        return head;
    }
};