#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#include "user_log_link.h"

// ------------------------------------------------
// MAIN
// ------------------------------------------------
int main(int argc, char *argv[])
{
    // VARIABLES
    UserList *list = NULL;

    char *pgm_name = NULL;
    char *username = NULL;
    char *code = NULL;
    char buffer[8] = {0};
    char usrnme_buf[100] = {0}; 
    
    size_t username_len = 0;
    int opt = 0;
    int c = 0;

    // Short option letters for cli params
    const char *short_option = "hu:";

    // format the program name properly
    /* We retrieved the last occurence of / and then
        we got the mem address and moved it u*/
    pgm_name = strrchr(argv[0], '/');
    *pgm_name++;

    // List of valid short opts
    static const struct option long_options[] = {
        {"username", required_argument, NULL, 'u'},
        {"help",     no_argument,       NULL, 'h'},
        {0, 0, 0, 0}
    };

    // ------------------------------------------------    
    // MAIN SUPER LOOP
    // ------------------------------------------------
    while(1)
    {
        // Get user data to insert into user log list
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
                
                strncpy(username, usrnme_buf, username_len);
                break;
            }
                

            case 'd':
                break;
        }

        // Save current list to file
        FILE *fd = fopen("./users_data", "a");
        if (!fd) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        fprintf(fd, "%s\n", username);
        fclose(fd);

    }

    


    free(list);
    return EXIT_SUCCESS;
}