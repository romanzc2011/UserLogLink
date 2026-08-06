#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user_node_link.h"

// ---------------------------------------
// USER NOCF INIT
// ---------------------------------------
UserNode *user_node_init(void)
{
    UserNode *user_node;
    user_node = malloc(sizeof(UserNode));

    if (user_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    user_node->username = NULL;
    memset(user_node->uuid_str, 0, 37);
    memset(user_node->node_uuid, 0, sizeof(uuid_t));
    user_node->next = NULL;
 
    return user_node;
}

// ---------------------------------------
// ADD USER NODE INSERT
// ---------------------------------------
UserNode *add_user_node(UserNode *user_node, char *username)
{
    UserNode *new_node;
    
    // Alloc memory for UserNode
    new_node = malloc(sizeof(UserNode));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    new_node->username = malloc(strlen(username) + 1);
    if (new_node->username == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Copy username to user_node username element
    strncpy(new_node->username, username, (strlen(username) + 1));
    uuid_generate(new_node->node_uuid);

    // Convert binary uuid into human reable form
    uuid_unparse(new_node->node_uuid, new_node->uuid_str);
    user_node->next = new_node;
    
    return new_node;
}

// ---------------------------------------
// USER NODE SIZE
// ---------------------------------------
int user_node_size(UserNode *user_list)
{
    UserNode *node;
    for(node = user_list; node != NULL; node = node->next) {
        
    }
}

// ---------------------------------------
// PRINT user_node
// ---------------------------------------
void print_user_node(UserNode *user_user_node, uuid_t *node_uuid)
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