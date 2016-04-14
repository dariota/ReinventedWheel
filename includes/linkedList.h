#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
	void *data;
	struct Node *next; 
};

struct LinkedList {
	struct Node *head;
	struct Node *tail;
};

void lListInit(struct LinkedList *list);
void lListPrint(struct LinkedList *list);
void lListInsert(struct LinkedList *list, void *data);
void *lListGetHead(struct LinkedList *list);
int lListIsEmpty(struct LinkedList *list);

#endif
