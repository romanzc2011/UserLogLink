#ifndef LOG_LINK_H_
#define LOG_LINK_H_

#include <uuid/uuid.h>

typedef struct UserList
{
    uuid_t node_uuid;
    char *username;
    struct UserList *next;
} UserList;

UserList *list_init(void);
UserList *list_insert(UserList *list, char *username, uuid_t *node_uuid);
int list_delete(UserList *user_list);
void print_list(UserList *user_list, uuid_t *node_uuid);

#endif