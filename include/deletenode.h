#ifndef _INC_DELETENODE
#define _INC_DELETENODE

uint8_t DeleteNodeForData(const int data)
{
	aux = firstNode;
	uint8_t DetectElement = 0;
	while (1)
	{
		if (aux->data == data)
		{
			node*const aux2 = aux;
			DetectElement = 1;
			if (aux == firstNode) 
			{
				if (firstNode->sig == firstNode) 
					firstNode = NULL;
				else 
				{
					firstNode = firstNode->sig;
					firstNode->ant = lastNode;
					lastNode->sig = firstNode;
				}
			}
			else
			{
				node*const postNode = aux->sig;
				node*const pastNode = aux->ant;
				postNode->ant = pastNode;
				pastNode->sig = postNode;
				if (aux == lastNode)
					lastNode = pastNode;
			}
			aux = aux->sig;
			free(aux2);
			if (firstNode == NULL) break;
			continue;
		}
		aux = aux->sig;
		if (aux == firstNode) break;
	}
	aux = lastNode;
	assertr(DetectElement, "ERROR: No se pudo eliminar el elemento porque no existe.")
	puts("El elemento fue eliminado con exito.");
	return 1;
}

void DeleteOneNode(void)
{
	if (firstNode->sig == firstNode)
	{
		free(firstNode);
		firstNode = NULL;
	}
	else
	{
		aux = firstNode;
		lastNode = firstNode->ant;
		firstNode = firstNode->sig;
		firstNode->ant = lastNode;
		lastNode->sig = firstNode;
		free(aux);
		aux = lastNode;
	}
	puts("-> El primer elemento fue eliminado con exito."); 
}

void DeleteLastNode(void)
{
	if (firstNode->sig == firstNode)
	{
		free(firstNode);
		firstNode = NULL;
	}
	else
	{
		aux = lastNode;
		node*const pastNode = lastNode->ant;
		pastNode->sig = firstNode;
		firstNode->ant = pastNode;
		lastNode = pastNode;
		free(aux);
		aux = lastNode;
	}
	puts("-> El ultimo elemento fue eliminado con exito.");
}

void DeleteAllNode(void)
{
	aux = firstNode;
	lastNode = firstNode->ant; 
	while (aux != lastNode)
	{
		firstNode = aux;
		aux = aux->sig;
		free(firstNode);
	}
	free(aux);
	firstNode = NULL;
	puts("-> Todos los elementos fueron eliminados.");
}

#endif /* _INC_DELETENODE */

