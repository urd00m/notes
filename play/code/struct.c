#include <stdlib.h>
#include <stdio.h>

struct node {
  char *name;
  char age;
  struct node * next;
};

struct node *list=0;

void insert_by_age(struct node **ptr_to_head, struct node *new)
{
  struct node *head = *ptr_to_head;

  if (!head || (head->age > new->age)) { 
    // insert at head of list if list empty
    // or new node is younger than first node
    new->next = head;
    *ptr_to_head = new;
  } else {
    // scan for position
    // to insert

    struct node *cur = head;
    struct node *prev = 0;

    while (cur && (cur->age <= new->age)) { 
      prev = cur;
      cur = cur->next;
    }

    new->next = prev->next;
    prev->next = new;
  }
}

void print(struct node *cur)
{
  while (cur) { 
    printf("%s => %d\n", cur->name,cur->age);
    cur = cur->next;
  }
}

void fail()
{
  printf("huh?\n");
  exit(-1);
}

int main()
{
  struct node *test;

  printf("Offsets of fields in struct node are:\n");
  printf("name: 0x%lx\nage:  0x%lx\nnext: 0x%lx\n",
	 (long) &test->name - (long)test, 
	 (long) &test->age - (long) test, 
	 (long) &test->next - (long) test);
  printf("sizeof(struct node) = 0x%x\n",sizeof(struct node));

  test = (struct node *)malloc(sizeof(struct node));
  if (!test) { fail(); }
  test->name = "Joe";
  test->age = 34;
  insert_by_age(&list,test);

  test = (struct node *)malloc(sizeof(struct node));
  if (!test) { fail(); }
  test->name = "Jane";
  test->age = 43;
  insert_by_age(&list,test);

  test = (struct node *)malloc(sizeof(struct node));
  if (!test) { fail(); }
  test->name = "Dave";
  test->age = 21;
  insert_by_age(&list,test);

  test = (struct node *)malloc(sizeof(struct node));
  if (!test) { fail(); }
  test->name = "Michela";
  test->age = 27;
  insert_by_age(&list,test);


  print(list);

  return 0;

}
