#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *next;
    struct node *prev;
    char *string;
};

struct doubly_linked_list
{
    struct node *first;
    struct node *last;
    int length;
};

void read_input();
void insert_item(struct doubly_linked_list *list);
void find_item(struct doubly_linked_list *list);
void delete_item(struct doubly_linked_list *list);
void print_list(struct doubly_linked_list *list);

#define MAX_LENGTH 256
char input_string[MAX_LENGTH];
int input_string_length;

int main(int argc, char const *argv[])
{
    struct doubly_linked_list list = {.first = NULL, .last = NULL, .length = 0};

    while (1)
    {
        char command;
        printf("\n");
        print_list(&list);
        printf("  1. Insert new item.\n");
        printf("  2. Find item.\n");
        printf("  3. Delete item\n");
        printf("  ctrl+c to exit.\n");
        printf("Enter option: ");

        command = getchar();
        getchar();

        if (command == '1')
        {
            printf("Enter string: ");
            insert_item(&list);
        }
        else if (command == '2')
        {
            printf("Enter string: ");
            find_item(&list);
        }
        else if (command == '3')
        {
            printf("Enter string: ");
            delete_item(&list);
        }
        else
        {
            printf("Incorrect option. Try again.\n");
        }
    }
    return 0;
}

void read_input()
{
    char c;
    int i = 0;
    input_string_length = 0;
    while (1)
    {
        c = getchar();

        if (i == MAX_LENGTH - 1)
        {
            input_string[MAX_LENGTH] = '\0';
            break;
        }

        if (c == '\n')
        {
            input_string[i] = '\0';
            break;
        }
        else
        {
            input_string[i] = c;
            i += 1;
            input_string_length += 1;
        }
    }
}

void insert_item(struct doubly_linked_list *list)
{
    read_input();
    struct node *new_node = malloc(sizeof(struct node));
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->string = malloc((input_string_length + 1) * sizeof(char));
    strcpy(new_node->string, input_string);

    if (list->last == NULL)
    {
        list->last = new_node;
        list->first = new_node;
    }
    else
    {
        list->last->next = new_node;
        new_node->prev = list->last;
        list->last = new_node;
    }
    list->length += 1;
}

void find_item(struct doubly_linked_list *list)
{
    read_input();
    int index;

    struct node *current_node;
    current_node = list->first;

    while (1)
    {
        if (current_node == NULL)
        {
            printf("Could not find \"%s\".\n", input_string);
            return;
        }

        int result = strcmp(input_string, current_node->string);
        if (result == 0)
        {
            printf("\"%s\" is element #%d\n", input_string, index);
            return;
        }
        else
        {
            current_node = current_node->next;
            index += 1;
        }
    }
}

void delete_item(struct doubly_linked_list *list)
{
    read_input();
    struct node *current_node;
    current_node = list->first;

    while (1)
    {
        if (current_node == NULL)
        {
            printf("Could not find \"%s\".\n", input_string);
            return;
        }

        int result = strcmp(input_string, current_node->string);
        if (result == 0)
        {
            if (current_node->prev != NULL)
            {
                current_node->prev->next = current_node->next;
            }

            if (current_node->next != NULL)
            {
                current_node->next->prev = current_node->prev;
            }

            if (current_node == list->first)
            {
                list->first == current_node->next;
            }

            if (current_node == list->last)
            {
                list->last == current_node->prev;
            }

            free(current_node->string);
            free(current_node);

            return;
        }
        else
        {
            current_node = current_node->next;
        }
    }
}

void print_list(struct doubly_linked_list *list)
{
    struct node *current_node;
    current_node = list->first;

    printf("Your list: ");
    printf("[");
    while (1)
    {
        if (current_node == NULL)
        {
            break;
        }

        printf("\"%s\", ", current_node->string);

        current_node = current_node->next;
    }
    printf("]\n");
}