#include <stdio.h>
#include <stdlib.h>

struct list
{
  int val;
  struct list *next;
};
typedef struct list List;

List *initialize(void);
List *insert(List *list, int value);
void printList(List *l);

int main()
{
  int option = 1;
  int val = 0;
  List *lista = initialize();

  do
  {
    printf("1 - Inserir.\n");
    printf("2 - Listar\n");
    printf("0 - Sair!\n");
    scanf("%d", &option);

    if (option == 1)
    {
      printf("\nDigite um valor:\n");
      scanf("%d", &val);
      lista = insert(lista, val);
    }

    else if (option == 2)
    {
      printList(lista);
    }
    else if (option == 0)
    {
      printf("Saindo...\n");
    }
    else
    {
      printf("Opcao invalida!\n");
    }
  } while (option != 0);

  return 0;
}

List *initialize(void)
{
  return NULL;
}

List *insert(List *list, int value)
{
  List *aux;
  List *insert = (List *)malloc(sizeof(List));

  if (list == NULL)
  {
    insert->val = value;
    insert->next = NULL;
    return insert;
  }

  if (list->val >= value)
  {
    insert->val = value;
    insert->next = list;
    return insert;
  }

  for (aux = list; aux != NULL; aux = aux->next)
  {
    if (aux->val < value && aux->next == NULL)
    {
      insert->val = value;
      insert->next = NULL;
      aux->next = insert;
      return list;
    }
    else if (aux->val < value && aux->next->val > value)
    {
      insert->val = value;
      insert->next = aux->next;
      aux->next = insert;
      return list;
    }
  }

  printf("\nSucess!!\n");
  return insert;
}

void printList(List *list)
{
  List *p;
  for (p = list; p != NULL; p = p->next)
    printf("value = %d\n", p->val);
}