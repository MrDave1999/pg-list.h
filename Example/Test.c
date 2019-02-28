#include "list.h"

#define OPTIONS " <1-12>"

int main(void)
{  
	int32_t data;
	int32_t option;
	while (1)
	{
		puts("-> Menu de Opciones:");
		puts("1. Insertar un elemento a la lista");
		puts("2. Eliminar todos los elementos");
		puts("3. Mostrar los elementos de forma ascendente");
		puts("4. Mostrar los elementos de forma descendente");
		puts("5. Buscar un elemento");
		puts("6. Eliminar un especifico elemento");
		puts("7. Eliminar el primer elemento");
		puts("8. Eliminar el ultimo elemento");
		puts("9. Ordenar elementos de menor a mayor");
		puts("10. Ordenar elementos de mayor a menor");
		puts("11. Cantidad de elementos agregados");
		puts("12. Salir del programa");
		dataread("%d", &option, "Ingrese una opcion" ""OPTIONS"");
		if ((option >= 2 && option <= 10) && (firstNode == NULL))
		{
			puts("ERROR: La lista esta vacia.");
			pauseprogram();
			continue;
		}
		switch (option)
		{
			case 1:
				CreateNode();
				break;

			case 2: 
				DeleteAllNode();
				break;

			case 3: 
				PrintElementNodes(START); 
				break;
			case 4:
				PrintElementNodes(END);
				break;
			case 5:
				while (1)
				{
					dataread("%d", &data, "Ingrese un elemento a buscar:");
					assertc(SearchElementNode(data), "")
					break;
				}
				break;

			case 6:
				while (1)
				{
					dataread("%d", &data, "Que elemento quieres eliminar de la lista?");
					assertc(DeleteNodeForData(data), "")
					break;
				}
				break;

			case 7:
			{
				DeleteOneNode();
				break;
			}
			case 8:
				DeleteLastNode();
				break;

			case 9:
				OrderList(AS);
				break;

			case 10:
				OrderList(DES);
				break;

			case 11:
				; int countNodes = 0;
				if (firstNode != NULL)
				{
					aux = firstNode;
					while (1)
					{
						++countNodes;
						aux = aux->sig;
						if (aux == firstNode) break;
					}
				}
				aux = lastNode;
				printf("-> Total de elementos: %d\n", countNodes);
				break;

			case 12:
				if (firstNode != NULL)
					DeleteAllNode();
				pauseprogram();
				return 0;
			default: puts("\nIngrese una opcion valida" ""OPTIONS"");
		}
		pauseprogram();
	}
	return 0;
}   
