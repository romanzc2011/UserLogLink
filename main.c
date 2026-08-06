#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#include "user_node_link.h"

// ------------------------------------------------
// MAIN
// ------------------------------------------------
#include <getopt.h>
int main(int argc, char *argv[])
{
    // VARIABLES
    UserNode *user_node = user_node_init();
    UserNode *new_node = malloc(sizeof(UserNode));
    FILE *fp;

    char *pgm_name = NULL;
    char *username = NULL;
    char *code = NULL;
    char buffer[8] = {0};
    char uuid_str[37] = {0};
    char usrnme_buf[100] = {0}; 
    
    size_t username_len = 0;
    int opt = 0;
    int c = 0;

    // format the program name properly
    /* We retrieved the last occurence of / and then
        we got the mem address and moved it u*/
    pgm_name = strrchr(argv[0], '/');
    *pgm_name++;

    // ------------------------------------------------    
    // MAIN SUPER LOOP
    // ------------------------------------------------
    while(1)
    {
        // Get user data to insert into user log user_log
        printf("Enter operation code: ");
        fgets(buffer, sizeof(buffer), stdin);

        switch(buffer[0]) {

            case 'a': {
                // Get username from user
                printf("Enter username: ");
                fgets(usrnme_buf, sizeof(usrnme_buf), stdin);

                username_len = strlen(usrnme_buf) + 1;
                username = malloc(username_len);

                // Capture failure and report
                if (username == NULL) {
                    perror("malloc");
                    exit(EXIT_FAILURE);
                }
                
                // Strip trailing new if present
                size_t len = strlen(usrnme_buf);
                if (len > 0 && usrnme_buf[len - 1] == '\n') {
                    usrnme_buf[len - 1] = '\0';
                    strncpy(username, usrnme_buf, username_len);
                }

                // Add user node data to list
                new_node = add_user_node(user_node, username);

                // Open users_data to write the new node to file to save
                fp = fopen("./users_data", "a");
                if (fp == NULL) {
                    perror("fopen");
                    exit(EXIT_FAILURE);
                }

                // Now write the data struct data
                fprintf(fp, "%s", DATA_DIVIDER);
                fprintf(fp, "USERNAME: %s\n", username);
                fprintf(fp, "UUID: %s\n", new_node->uuid_str);
                fprintf(fp, "%s", DATA_DIVIDER);
                fclose(fp);

                free(username);
                break;
            }

            // PRINT USAGE
            case 'p':
                break;
              
            // DELETE NODE
            case 'd':
                break;
            
            // QUIT
            case 'q':
                exit(EXIT_SUCCESS);
        }


    }

    free(user_node);
    return EXIT_SUCCESS;
}