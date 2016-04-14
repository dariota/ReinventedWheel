#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"

struct Node *lListNewNode(void *data) {
	struct Node *node = malloc(sizeof(struct Node));

	node->data = data;
	node->next = NULL;

	return node;
}

void lListFreeNode(struct Node *node) {
	free(node);	
}

void lListInit(struct LinkedList *list) {
	if (!list) return;

	list->head = list->tail = NULL;
}

void lListPrint(struct LinkedList* list) {
	if (!list) {
		printf("NULL list.\n");
	} else {
		struct Node *next = list->head;
		while (next) {
			printf("%ld->",(long) next->data);
			next = next->next;
		}
		printf("NULL\n");
	}
}

void lListInsert(struct LinkedList *list, void *data) {
	if (!list) return;

	if (!list->head) {
		list->head = list->tail = newNode(data);
	} else {
		list->tail->next = newNode(data);
		list->tail = list->tail->next;
	}
}

void *lListGetHead(struct LinkedList *list) {
	if (!list || !list->head) return NULL;

	struct Node *head = list->head;
	void *data = head->data;

	list->head = head->next;
	freeNode(head);

	return data;
}

int lListIsEmpty(struct LinkedList *list) {
	if (!list) return 1;

	return list->head == NULL;
}
