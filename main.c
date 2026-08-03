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
    UserList *list = NULL;
    char *pgm_name;
    char buffer[256];

    // Short option letters for cli params
    const char *short_option = "hu:";

    // format the program name properly
    /* We retrieved the last occurence of / and then
        we got the mem address and moved it u*/
    pgm_name = strrchr(argv[0], '/');
    *pgm_name++;

    if (argc < 2) {
        fprintf(stderr, "usage: %s -u username\n", pgm_name);
        exit(EXIT_FAILURE);
    }

    // ------------------------------------------------    
    // MAIN SUPER LOOP
    // ------------------------------------------------

    // List of valid short opts
    static const struct option long_options[] = {
        {"username", required_argument, NULL, 'u'},
        {"help",     no_argument,       NULL, 'h'},
        {0, 0, 0, 0}
    };

    // Get username from clip and assign to username variable
    int opt;
    while ((opt = getopt_long(argc, argv, short_option, long_options, NULL)) != -1) {

        switch (opt) {
            // USERNAME
            case 'u': {
                size_t username_len = strlen(optarg) + 1; 
                char *username = malloc(username_len);
                
                // Capture failure and report
                if (username == NULL) {
                    perror("malloc");
                    exit(EXIT_FAILURE);
                }

                strncpy(username, optarg, username_len);
                printf("USERNAME: %s\n", username);
                break;
            }
                
            // HELP
            case 'h':
                print_help(stdout, pgm_name, EXIT_SUCCESS);
                break;
            
            default:
                print_help(stderr, pgm_name, EXIT_FAILURE);
        }
    }
   
    free(list);
    return EXIT_SUCCESS;
}