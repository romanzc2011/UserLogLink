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
    char *username,
    uuid_t *node_uuid
)
{
    UserList *new_list;
    
    // Alloc memory for UserList
    new_list = malloc(sizeof(UserList));
    if (new_list == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Alloc memory for uuid
    node_uuid = malloc(sizeof(uuid_t));
    if (node_uuid == NULL) {
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
// PRINT LIST
// ---------------------------------------
void print_list(UserList *user_list, uuid_t *node_uuid)
{

}