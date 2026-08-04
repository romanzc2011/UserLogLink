#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user_log_link.h"

// ---------------------------------------
// LIST INIT
// ---------------------------------------
UserList *list_init(void)
{
    UserList *list;

    if ((list = malloc(sizeof(UserList))) == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    memset(list->node_uuid, 0, sizeof(uuid_t *));
    list->next = NULL;
 
    return list;
}

// ---------------------------------------
// LIST INSERT
// ---------------------------------------
UserList *add_to_list(UserList *node, char *username)
{
    UserList *new_node;
    
    // Alloc memory for UserList
    new_node = malloc(sizeof(UserList));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Copy username to list username element
    strncpy(new_node->username, username, (strlen(username) + 1));
    uuid_generate(new_node->node_uuid);
    new_node->next = node;        

    return new_node;
}

// ---------------------------------------
// LIST SIZE
// ---------------------------------------
int list_size(void)
{
    // Open file stream and count uuids for list size
    FILE *fp;
    char buffer[256];
    fp = fopen("./user_uuid", "a");

    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((fgets(buffer, 256, fp)) != EOF) {
        printf("UUID: %s\n", buffer);
    }

    return 0;
}

// ---------------------------------------
// PRINT LIST
// ---------------------------------------
void print_list(UserList *user_list, uuid_t *node_uuid)
{

}

// ---------------------------------------
// PRINT HELP
// ---------------------------------------
void print_help(FILE *stream, const char *pgm_name, int exit_code)
{
    fprintf(stream, "Usage: %s options\n", pgm_name);
    fprintf(stream, 
        "-u  --username   Username to be added.\n"
        "-h  --help  Help\n"
    );
    exit(exit_code);
}  