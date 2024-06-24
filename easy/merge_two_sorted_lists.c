#include <stdio.h>
#include <stdlib.h>

//  Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *newNode(int val) {
	struct ListNode *new;

	new = NULL;
	new = malloc(sizeof(struct ListNode));
	new->val = val;
	new->next = NULL;
	return new;
}

int list_size(struct ListNode *list)
{
	struct ListNode *tmp = list;
	int i = 0;

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

struct ListNode *add_last(struct ListNode* dest, struct ListNode* src)
{
	struct ListNode *tmp = dest;

	if (dest == NULL)
	{
		return src;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = src;
	return (dest);
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	
	int len1, len2, len3;
	struct ListNode *res = NULL;
	struct ListNode *tmp = NULL;

	len1 = list_size(list1);
	len2 = list_size(list2);
	len3 = len1 + len2;
	while (list1 || list2)
	{
		if (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				tmp = newNode(list1->val);
				list1 = list1->next;
				res = add_last(res, tmp);
			}
			else if (list1->val > list2->val)
			{
				tmp = newNode(list2->val);
				list2 = list2->next;
				res = add_last(res, tmp);
			}
			else
			{
				tmp = newNode(list1->val);
				list1 = list1->next;
				res = add_last(res, tmp);
				tmp = newNode(list2->val);
				list2 = list2->next;
				res = add_last(res, tmp);
			}
		}
		else if (list1 && !list2)
		{
			while (list1)
			{
				tmp = newNode(list1->val);
				res = add_last(res, tmp);
				list1 = list1->next;
			}
		}
		else if (!list1 && list2)
		{
			while (list2)
			{
				tmp = newNode(list2->val);
				res = add_last(res, tmp);
				list2 = list2->next;
			}
		}
	}
	return res;
}

int main()
{
	struct ListNode *list1 = newNode(1);
	list1->next = newNode(2);
	list1->next->next = newNode(4);
	struct ListNode *list2 = newNode(1);
	list2->next = newNode(3);
	list2->next->next = newNode(4);
	struct ListNode *result = mergeTwoLists(list1, list2);
	while (result)
	{
		printf("Result: %d\n", result->val);
		result = result->next;
	}
	return 0;
}	
