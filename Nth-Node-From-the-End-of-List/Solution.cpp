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
        ListNode dummy(0, head);
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        
        // Move first pointer n+1 steps ahead so that there's a gap of n nodes between first and second
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }
        
        // Move both pointers until first reaches the end of the list
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the nth node from the end
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;
        
        return dummy.next;
    }
};
