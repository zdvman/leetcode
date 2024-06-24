#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


//  Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *new_node(int i)
{
	struct ListNode *new;

	new = NULL;
	new = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (new == NULL)
		return (NULL);
	new->val = i;
	new->next = NULL;
	return (new);
}

struct ListNode *add_btm(struct ListNode *node, int i)
{
	struct ListNode    *new;
	struct ListNode    *tmp;

	tmp = node;
	new = new_node(i);
	if (new == NULL)
		return (NULL);
	if (node)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		return (new);
	return (node);
}

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *result = NULL;
	struct ListNode **node = &result;
	int carry = 0;

	while (l1 != NULL || l2 != NULL || carry != 0) {
		int sum = carry;
		if (l1 != NULL) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			sum += l2->val;
			l2 = l2->next;
		}
		carry = sum / 10;

		// Create a new node with the single digit
		struct ListNode *newNode = new_node(sum % 10);
		if (newNode == NULL) {
			// Handle memory allocation failure
			// Free any allocated memory before returning
			while (result != NULL) {
				struct ListNode *temp = result;
				result = result->next;
				free(temp);
			}
			return NULL;
		}

		// Append the new node to the result list
		*node = newNode;
		node = &newNode->next;
	}

	return result;
}

int main()
{
	struct ListNode *l1 = NULL;
	struct ListNode *l2 = NULL;
	struct ListNode *result = NULL;

	l1 = add_btm(l1, 2);
	l1 = add_btm(l1, 4);
	l1 = add_btm(l1, 3);
	l2 = add_btm(l2, 5);
	l2 = add_btm(l2, 6);
	l2 = add_btm(l2, 4);
	result = addTwoNumbers(l1, l2);
	while (result)
	{
		printf("%d\n", result->val);
		result = result->next;
	}
	return 0;
}
