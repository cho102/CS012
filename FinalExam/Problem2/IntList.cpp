#include "IntList.h"

void IntList::distanceFrom(int key) {
	if (head == nullptr)
	{
		return;
	}
    head->data = searchAndModify(head, key);
}


int IntList::searchAndModify(IntNode *curr, int key) {
	if (curr->data == key)
	{
		if (curr == head)
		{
			return key;
		}
		return 0;
	}
	if (curr == nullptr)
	{
		return 0;
	}
// 	if (curr->next)
	int num = searchAndModify(curr->next, key) + 1;
	curr->data = num ;
	return num;
}

