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
private:
    ListNode* revhelper(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        if (head == nullptr || head->next == nullptr)
            return;
        ListNode* fast = head;
        ListNode* head2 = NULL;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        head2 = slow->next;
        slow->next = NULL;
        head2 = revhelper(head2);
        while (head != NULL && head2 != NULL) {
            ListNode* next1 = head->next;
            ListNode* next2 = head2->next;
            head->next = head2;
            head2->next = next1;
            head = next1;
            head2 = next2;
        }
    }
};