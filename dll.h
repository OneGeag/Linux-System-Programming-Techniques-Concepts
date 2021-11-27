#ifndef DLL_H
#define DLL_H

typedef struct dll_node_ {
	void *data;
	struct dll_node_ *left;
	struct dll_node_ *right;
} dll_node_t;

typedef struct dll_ {
	dll_node_t *head;
} dll_t;


dll_t *
get_new_dll();

/*
	Be carefull !!!
	Each node in the linked list just points to the data, doesn't copy it
	So we have a risk to get segmentation fault if we add data from stack memory to our list
*/

int
add_data_to_dll(dll_t *dll, void *app_data);


#endif /* DLL_H */
