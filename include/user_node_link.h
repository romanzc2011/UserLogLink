#ifndef USER_NODE_LINK_H_
#define USER_NODE_LINK_H_

#include <uuid/uuid.h>

#define DATA_DIVIDER    "################################################################\n"

// USER NODE STRUCT
typedef struct UserNode
{
    char *username;
    uuid_t node_uuid;
    char uuid_str[37];
    struct UserNode *next;
} UserNode;

// ---------------------------------------------------
// FUNCTIONS
// ---------------------------------------------------
UserNode *user_node_init(void);
UserNode *add_user_node(UserNode *user_node, char *username);
int user_delete(UserNode *user_node);
int user_list_size(void);
void print_user_node_list(UserNode *user_node, uuid_t node_uuid);
void print_help(FILE *stream, const char *pgm_name, int exit_code);

#endif