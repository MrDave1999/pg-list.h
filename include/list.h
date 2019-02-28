#ifndef _INC_LIST
#define _INC_LIST

#include <stdint.h>
#include <stdlib.h>
#include "pscanf.h"
#include "assertx.h"

struct __node
{
	int data;
	struct __node* sig;
	struct __node* ant;
};

typedef struct __node node;

node* firstNode = NULL;
node* lastNode = NULL;
node* aux = NULL;

#include "deletenode.h"

#define START	(1)
#define END		(0)

#define AS		(1) //Ascendente
#define DES		(0) //Descendente

uint8_t CreateNode(void) 
{
	lastNode = (node*)malloc(sizeof(node));
	assertr(lastNode != NULL, "ERROR: No se pudo reservar memoria.")
	dataread("%d", &lastNode->data, "Ingrese un dato entero:");
	if (firstNode == NULL)
	{
		firstNode = lastNode;
		firstNode->sig = lastNode;
		firstNode->ant = lastNode;
	}
	else
	{
		lastNode->ant = aux;
		lastNode->sig = firstNode;
		firstNode->ant = lastNode;
		aux->sig = lastNode;
	}
	aux = lastNode;
	return 1;
}

void PrintElementNodes(const uint8_t type)
{
	aux = ((type) ? (firstNode) : (lastNode));
	printf("-> Elementos:\n\n");
	while (1)
	{
		printf("%d\n", aux->data);
		aux = ((type) ? (aux->sig) : (aux->ant));
		if ((type && aux == firstNode) || (!type && aux == lastNode)) break;
	}
	aux = lastNode;
}

uint8_t SearchElementNode(const int data)
{
	aux = firstNode;
	uint8_t count_nodes = 0;
	uint8_t DetectElement = 0;
	while (1)
	{
		++count_nodes;
		if (aux->data == data)
		{
			++DetectElement;
			((DetectElement == 1) ? (printf("-> El elemento %d se encuentra en el nodo: %d", aux->data, count_nodes)) : (printf(",%d", count_nodes)));
		}
		aux = aux->sig;
		if (aux == firstNode) break;
	}
	aux = lastNode;
	puts("");
	assertr(DetectElement, "ERROR: Ese elemento no existe en la lista")
	return 1;
}

uint8_t OrderList(const uint8_t type)
{
	assertr(firstNode->sig != firstNode, "ERROR: Solo hay 1 elemento en la lista.")
	aux = firstNode;
	node* pastNode = NULL;
	node* postNode = NULL;
	int dataHigher = 0;
	while (1)
	{
		postNode = firstNode;
		for (;;)
		{
			postNode = postNode->sig;
			pastNode = postNode->ant;
			if ((type && pastNode->data > postNode->data) || (!type && pastNode->data < postNode->data))
			{
				dataHigher = pastNode->data;
				pastNode->data = postNode->data;
				postNode->data = dataHigher;
			}
			if (postNode->sig == firstNode) break;
		}
		aux = aux->sig;
		if (aux == firstNode) break;
	}
	aux = lastNode;
	puts("-> La lista fue ordenada con exito!");
	return 1;
}

#endif /* _INC_LIST */
