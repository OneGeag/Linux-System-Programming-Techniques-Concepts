#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PROGRAMM_NAME

#include "dll.h"

typedef struct person_ {
	char name[32];
	int age;
	int weight;
} person_t;

static void
print_person_details(person_t *person)
{
	printf("name   = %s\n", person->name);
	printf("age    = %d\n", person->age);
	printf("weight = %d\n", person->weight);
}

static void
print_person_db(dll_t *person_db)
{
	size_t num = 0;
	if (!person_db || !person_db->head) {
		return;
	}

	dll_node_t *head = person_db->head;
	person_t *data = NULL;

	while (head) {
		data = head->data;
		printf("%zu:\n", num);
		printf("-----\n");
		print_person_details(data);
		printf("-----\n");
		head = head->right;
		num++;
	}
}

#if 0
#define offset(struct_name, field_name) \
	(unsigned int)&(((struct_name *)0)->field_name)
#endif

int
main(int argc, char *argv[])
{
	person_t *person1 = calloc(1, sizeof(person_t));
	strncpy(person1->name, "Abhishek", strlen("Abhishek") + 1);
	person1->age = 31;
	person1->weight = 75;

	person_t *person2 = calloc(1, sizeof(person_t));
	strncpy(person2->name, "Joseph", strlen("Joseph") + 1);
	person2->age = 41;
	person2->weight = 70;
	
	person_t *person3 = calloc(1, sizeof(person_t));
	strncpy(person3->name, "Jack", strlen("Jack") + 1);
	person3->age = 29;
	person3->weight = 55;

	/* Create a new Linked List */
	dll_t *person_db = get_new_dll();
	add_data_to_dll(person_db, person1);
	add_data_to_dll(person_db, person2);
	add_data_to_dll(person_db, person3);

	print_person_db(person_db);

	assert(1 == 2);

	return 0;
}
