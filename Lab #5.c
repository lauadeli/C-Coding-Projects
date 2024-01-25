#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
} node;


typedef struct LL{
    node *head;
    int size;
} LL;


void create_node(node **p_n, int data)
{
    *p_n = (node*)malloc(sizeof(node));
    (*p_n)->next = NULL;
    (*p_n)->data = data;
}

// created a linked list that looks like data[0]->data[1]->data[2]->...->data[size-1]
void create_LL_from_data(LL **p_LL, int *data_arr, int size)
{
    (*p_LL) = (LL*)malloc(sizeof(LL));
    (*p_LL)->size = 0;
    node *cur = NULL;
    for(int i = 0; i < size; i++){
        node *n;
        create_node(&n, data_arr[i]); // n is a pointer to a node with data = data[i], next = NULL
        if(cur == NULL){
            (*p_LL)->head = n;
        }
        else{
            cur->next = n;
        }
        cur = n;
        (*p_LL)->size++;
    }
}


void LL_append(LL *my_list, int new_elem)
{
    node *cur = my_list->head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    node *n;
    create_node(&n, new_elem);
    cur->next = n;
    my_list->size++;
}

void LL_insert(LL *my_list, int new_elem, int index)
{
    if(index == 0){
        node *n;
        create_node(&n, new_elem);
        n->next = my_list->head;
        my_list->head = n;
    } else {
        node *cur = my_list->head;
        for(int i = 0; i < index - 1; i++){
            cur = cur->next;
        }
        node *n;
        create_node(&n, new_elem);
        
        n->next = cur->next;
        cur->next = n;
        my_list->size++;
    }
}

void LL_delete(LL *my_list, int index)
{
    // TODO
    // Delete element at index index in linked list my_list
    node* temp = my_list->head;
    if (index == 0){
        my_list->head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index - 1; i++){
        temp = temp->next;
        }
    if (temp == NULL || temp->next == NULL)
        return;
    node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    
}

void LL_free_all(LL *my_list)
{
    // TODO
    // Free all memory allocated for linked list my_list,
    // including all the nodes
    node *head = my_list->head;
    node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}


int LL_get_rec(LL *my_list, int index)
{
    // TODO
    // Return the element at index index in linked list my_list
    // Use recursion. you must not use for, while, or do-while loops
    // You should use a helper function
}

typedef struct ArrayList{
    int *data;
    int size;
    int capacity;
} ArrayList;

void create_AL_from_data(ArrayList **p_AL, int *data_arr, int size)
{
    // TODO
    (*p_AL) = (ArrayList*)malloc(sizeof(ArrayList));
    (*p_AL)->size = 0;
    (*p_AL)->capacity = size;
    (*p_AL)->data = (int *)malloc(sizeof(int)*(*p_AL)->capacity);
    for(int i = 0; i < size; i++){
        (*p_AL)->data[i] = data_arr[i];
        (*p_AL)->size++;
    }
}

void AL_append(ArrayList *my_list, int new_elem)
{
    if(my_list->capacity == my_list->size){
        my_list->data = (int *)realloc(my_list->data, 2*(sizeof(int))*(my_list)->capacity);
        my_list->capacity = 2*(my_list->capacity);
    }
    my_list->size++;
    my_list->data[my_list->size - 1] = new_elem;
}

void AL_insert(ArrayList *my_list, int new_elem, int index)
{
    if(my_list->capacity == my_list->size){
        my_list->data = (int *)realloc(my_list->data, 2*(sizeof(int))*(my_list)->capacity);
        my_list->capacity = 2*(my_list->capacity);
    }
    (my_list)->size++;
    int temp = ((my_list)->data)[index];
    ((my_list)->data)[index] = new_elem;
    for(int i = (my_list)->size; i > index+1; i -=1){
        ((my_list)->data)[i] = ((my_list)->data)[i-1];
    }
    ((my_list)->data)[index + 1] = temp; 
}

void AL_delete(ArrayList *my_list, int index)
{
    for(int i = index; i < my_list->size; i++){
        (my_list->data)[i] = (my_list->data)[i + 1];
    }
    my_list->size-=1;
}

void AL_free(ArrayList *my_list)
{
    free(my_list->data);
    free(my_list);
}


int main()
{
    printf("________LinkedList_________\n");
    int data_arr[] = {1, 2, 3, 4, 5};
    LL *my_list;
    create_LL_from_data(&my_list, data_arr, 5);
    LL_append(my_list, 6);
    LL_insert(my_list, 8, 4);
    LL_delete(my_list, 4);
    node *cur = my_list->head;
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    LL_free_all(my_list);


    printf("________ArrayList_________\n");
    ArrayList *my_listA;
    create_AL_from_data(&my_listA, data_arr, 5);
    AL_append(my_listA, 8);
    AL_insert(my_listA, 5, 2);
    AL_delete(my_listA, 5);
    for(int i = 0; i < my_listA->size; i++){
        printf("%d\n", (my_listA->data)[i]);
    }
    AL_free(my_listA);
    return 0;
}