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
UserList *list_insert(
    UserList *list,
    char *username
)
{
    UserList *new_list;
    FILE *fp;

    fp = fopen("./users_data", "a");

    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    // Alloc memory for UserList
    new_list = malloc(sizeof(UserList));
    if (new_list == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Copy username to list username element
    strncpy(new_list->username, username, (strlen(username) + 1));
    uuid_generate(new_list->node_uuid);
    
    // Point next to the new list if there is already a list
    if (!(list == NULL)) {
        list->next = new_list;
    }

    return new_list;
}

// ---------------------------------------
// LIST SIZE
// ---------------------------------------
int list_size(void)
{
    FILE *fp;
    fp = fopen("./user_uuid", "a");

    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
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