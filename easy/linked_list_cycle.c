#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	if (!head || !head->next)
		return false;
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			return true;
	}
	return false;
}

int main(void) {
	struct ListNode *head = NULL;
	struct ListNode *node1 = malloc(sizeof(struct ListNode));
	struct ListNode *node2 = malloc(sizeof(struct ListNode));
	struct ListNode *node3 = malloc(sizeof(struct ListNode));
	struct ListNode *node4 = malloc(sizeof(struct ListNode));
	struct ListNode *node5 = malloc(sizeof(struct ListNode));
	node1->val = 1;
	node1->next = node2;
	node2->val = 2;
	node2->next = node3;
	node3->val = 3;
	node3->next = node4;
	node4->val = 4;
	node4->next = node5;
	node5->val = 5;
	node5->next = node1;
	head = node1;
	printf("%d\n", hasCycle(head));
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	return 0;
}
