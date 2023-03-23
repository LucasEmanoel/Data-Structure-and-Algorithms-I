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
void percorreListPrint(List *result);
List *concatena(List *l1, List *l2);
List *inverte(List *list);

int main()
{
  int option = 1;
  List *l1 = initialize();
  List *l2 = initialize();
  List *result = initialize();

  do
  {
    printf("*******************************\n");
    printf("* 1 - Inserir                 *\n");
    printf("* 2 - Listar                  *\n");
    printf("* 3 - Concatenar              *\n");
    printf("* 0 - Sair!                   *\n");
    printf("*******************************\n");
    scanf("%d", &option);

    if (option == 1)
    {
      int value, list_option = 0;
      printf("Qual Lista Deseja Inserir.?\n");
      printf("* 1 - primeira lista          *\n");
      printf("* 2 - segunda lista           *\n");
      scanf("%d", &list_option);

      if (list_option == 1)
      {
        printf("Insira um valor.\n");
        scanf("%d", &value);
        l1 = insert(l1, value);
      }
      else if (list_option == 2)
      {
        printf("Insira um valor.\n");
        scanf("%d", &value);
        l2 = insert(l2, value);
      }
    }

    else if (option == 2)
    {
      percorreListPrint(result);
    }
    else if (option == 3)
    {
      List *inv1 = inverte(l1);
      List *inv2 = inverte(l2);
      result = concatena(inv1, inv2);
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

  free(l1);
  free(l2);
  free(result);

  return 0;
}

List *initialize(void)
{
  return NULL;
}

List *insert(List *list, int value)
{
  List *insert = (List *)malloc(sizeof(List));

  if (list == NULL)
  {
    insert->val = value;
    insert->next = NULL;
    return insert;
  }

  insert->val = value;
  insert->next = list;
  printf("Você acaba de inserir: %d!!\n", value);

  return insert;
}

void percorreListPrint(List *result)
{

  List *aux;
  printf("Resultado: \n{");
  for (aux = result; aux != NULL; aux = aux->next)
  {
    printf(" %d ", aux->val);
  }
  printf("}\n");
}

List *concatena(List *l1, List *l2)
{
  if (l1 == NULL && l2 == NULL)
  {
    printf("Listas vazias, impossivel concatenar.");
    exit;
  }
  if (l1 == NULL)
  {
    return l2;
  }
  if (l2 == NULL)
  {
    return l1;
  }

  List *aux = l1;
  while (aux->next != NULL)
  {
    aux = aux->next;
  }
  aux->next = l2;

  return l1;
}

List *inverte(List *l)
{
  if (l == NULL || l->next == NULL)
  {
    return l;
  }

  List *prev = NULL;
  List *atual = l;
  List *next = NULL;

  while (atual != NULL)
  {
    next = atual->next;
    atual->next = prev;
    prev = atual;
    atual = next;
  }

  return prev;
}