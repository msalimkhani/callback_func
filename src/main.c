#include <stdio.h>
#include "../libs/console.h"

typedef struct _key
{
	void *value;
	struct _key *next;
}Key;
void actionLinkedList(Key *k, void (*func)())
{
	while (k != NULL)
	{
		(*func)(k);
		k = k->next;
	}
	
}
void action(Key *key)
{
	printfc("I'm Called back, %d\n", Green, key->value);
}
int main()
{
	Key *head;
	Key *k1, *k2, *k3;
	k1 = (Key *) malloc(sizeof(Key));
	k2 = (Key *) malloc(sizeof(Key));
	k3 = (Key *) malloc(sizeof(Key));
	k1->value = 1;
	k2->value = 2;
	k3->value = 3;
	k1->next = k2;
	k2->next = k3;
	k3->next = NULL;
	head = k1;
	actionLinkedList(head, &action);
	free(head);
	free(k2);
	free(k3);
	return 0;

}
