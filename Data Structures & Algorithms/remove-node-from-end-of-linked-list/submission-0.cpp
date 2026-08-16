class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int cnt = 0;
        ListNode* temp = head;

        // Count nodes
        while (temp) {
            cnt++;
            temp = temp->next;
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        temp = dummy;

        // Move to node BEFORE the node to delete
        for (int i = 0; i < cnt - n; i++) {
            temp = temp->next;
        }

        // Delete
        temp->next = temp->next->next;

        return dummy->next;
    }
};