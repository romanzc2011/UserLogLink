#ifndef LOG_LINK_H_
#define LOG_LINK_H_

#include <uuid/uuid.h>

// USER LIST STRUCT
typedef struct UserList
{
    uuid_t node_uuid;
    char *username;
    struct UserList *next;
} UserList;

// ---------------------------------------------------
// FUNCTIONS
// ---------------------------------------------------
UserList *list_init(void);
UserList *list_insert(UserList *list, char *username);
int list_delete(UserList *user_list);
int list_size(void);
void print_list(UserList *user_list, uuid_t *node_uuid);
void print_help(FILE *stream, const char *pgm_name, int exit_code);

#endif