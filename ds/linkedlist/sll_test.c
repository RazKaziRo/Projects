/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Single Linked List.
 * Date: 02.12.2019
 * Language: C
 * Reviewer: 
 */

#include <stdio.h>
#include <stdlib.h> /*free()*/
#include "sll.h"

#define UNUSED(x) (void)(x)


int main(int argc, char const *argv[])
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;

	int a = 10;	
	int b = 20;
	int c = 30;
	
	n1 = SLLCreateNode(NULL, &a);
	n2 = SLLCreateNode(NULL, &b);
	n3 = SLLCreateNode(NULL, &c);

	SLLInsertAfter(n2,n1);
	SLLInsertAfter(n3,n2);

	printf("n1 data:%d\n",*(int *)n1->data);
	printf("n2 data:%d\n",*(int *)n2->data);
	printf("n3 data:%d\n",*(int *)n3->data);

	printf("before: %lu \n", SLLSize(n1));
	SLLDestroy(n1);
	/*printf("before: %lu \n", SLLSize(n1));*/

	/*printf("%d", *(int *)n2->data);*/

	UNUSED(argc);
	UNUSED(argv);
	return 0;
}
