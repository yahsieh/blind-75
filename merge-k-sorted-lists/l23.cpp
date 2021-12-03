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
    ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode;
        ListNode *cur = ret;
        while (l1!=nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val) {
                    cur->next = l1;
                    l1 = l1->next;
                } else {
                    cur->next = l2;
                    l2 = l2->next;
                }
            } else {
                if (l1) {
                    cur->next = l1;
                    l1 = l1->next;
                } else if (l2) {
                    cur->next = l2;
                    l2 = l2->next;
                }
            }
            cur = cur->next;
        }
        return ret->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        queue<ListNode*> q;
        for (auto i: lists)
            q.push(i);
        while(q.size()>1) {
            ListNode *l1 = q.front();
            q.pop();
            ListNode *l2 = q.front();
            q.pop();
            q.push(merge2Lists(l1,l2));
        }
        if (q.empty())
            return nullptr;
        else
            return q.front();
    }
};