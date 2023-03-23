#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
  int id;
  char name[64];
  int age;
  struct student *next;
};
typedef struct student Student;

struct turma
{
  char teacher_name[64];
  struct student *students;
};
typedef struct turma Turma;

Turma initialize(Turma cl, char name[64]);
void insert(Turma *class);
void pop(Turma *class);
int subMenu(Turma teachers[5]);
void listStudents(Turma *class);

int main()
{
  int option = 1, i, sub;
  char name_t[64];
  Turma teachers[5] = {};
  Turma new_class;

  do
  {
    Student s;
    printf("*******************************\n");
    printf("* 1 - Inserir novo professor. *\n");
    printf("* 2 - Inserir aluno.          *\n");
    printf("* 3 - Remover aluno.          *\n");
    printf("* 4 - Listar                  *\n");
    printf("* 0 - Sair!                   *\n");
    printf("*******************************\n");
    scanf("%d", &option);

    if (option == 1)
    {
      printf("\nDigite o nome do professor.\n");
      scanf("%s", name_t);

      for (i = 0; i < 5; i++)
      {
        if (strlen(teachers[i].teacher_name) == 0)
        {
          new_class = initialize(new_class, name_t);
          /*printf("newclass= %s", new_class.teacher_name);*/
          teachers[i] = new_class;
          break;
        }
      }
    }

    else if (option == 2)
    {
      sub = subMenu(teachers);
      insert(&teachers[sub]);
    }
    else if (option == 3)
    {
      sub = subMenu(teachers);
      pop(&teachers[sub]);
    }
    else if (option == 4)
    {
      sub = subMenu(teachers);
      listStudents(&teachers[sub]);
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

Turma initialize(Turma cl, char name[64])
{
  strcpy(cl.teacher_name, name);
  cl.students = NULL;
  return cl;
}

int subMenu(Turma teachers[5])
{
  int optionT, i;
  
    printf("-------- Escolha uma turma -------.\n");

    for (i = 0; i < 5; i++)
    {
      if (strlen(teachers[i].teacher_name) > 0)
      {
        printf("%d - Turma do professor - %s.\n", (i + 1), teachers[i].teacher_name);
      }
    }
    scanf("%d", &optionT);
    
    return optionT-1;
}

void insert(Turma *class)
{
  Student* s = (Student *) malloc(sizeof(Student));

  printf("\nDigite o id.\n");
  scanf("%d", &(s->id));
  printf("\nDigite o nome do aluno.\n");
  scanf("%s", s->name);
  printf("\nDigite a idade.\n");
  scanf("%d", &(s->age));

  if (class->students == NULL)
  {
    class->students = s;
    class->students->next = NULL;
  }
  else
  {
    s->next = class->students;
    class->students = s;
  }

  printf("\nSucess!!\n");
}
void pop(Turma *class)
{
  free(class->students);
  class->students = class->students->next;
}

void listStudents(Turma *turma)
{
  int i = 1;
  Student *p;
  for (p = turma->students; p != NULL; p=p->next)
  {
    printf("------ %d - Aluno -------", i);
    printf("\nNome = %s\n", p->name);
    printf("Idade = %d\n", p->age);
    i++;
  }

}