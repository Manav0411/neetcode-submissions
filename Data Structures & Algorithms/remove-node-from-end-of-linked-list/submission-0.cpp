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
        ListNode* temp = head;
        int cnt = 1;
        while (temp->next != NULL) {
            cnt++;
            temp = temp->next;
        }
        int node = cnt - n;

        if (node == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        temp = head;
        for (int i = 1; i < node; i++) {
            temp = temp->next;
        }

        ListNode* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;

        return head;
    }
};