/* main.c */
/* Date  : 20 October 2015
 * Author: Ankit Pati
 */

#include "defs/functions.h"
#include "defs/structures.h"

int main(int argc, char **argv)
{
    int i; /* counters */
    int sh_allowed, echo_allowed;
    char hotel_current[NAME_MAXIMUM + 1], *user_input, *command;
    char *p;
    int c,b,l,d;

    sh_allowed = system(NULL);
    echo_allowed = 1;
    *hotel_current = '\0';

    for(i = 1; i < argc; ++i){
             if(!strcmp(argv[i], "--no-shell-escape")) sh_allowed &= 0;
        else if(!strcmp(argv[i], "--no-prompt")) echo_allowed &= 0;
        else die("Incorrect usage! Use\n\t--no-shell-escape\n\t--no-prompt");
    }


    for(;;){
        errno = 0;

        if(echo_allowed){
            fprintf(stderr, "%s%s> ", *hotel_current ? "@" : "",
                    *hotel_current ? hotel_current : "hotel-sh");
            fflush(stderr);
        }

        user_input = getstr();
        if(feof(stdin) || ferror(stdin)) goto cleanup;
        command = strtok(user_input, " ");

        p=strtok(NULL, "");
        c=0,b=0,d=0;
        while(*(p+b)==' ') b++;
        while(*(p+c+b)!='\0'){
            *(p+c)=*(p+c+b);
            c++;
        }

        while(*(p+d)!='\0'){
            if(*(p+d)!=' ') l=d;
            d++;
        }
        *(p+l+1)='\0';

             if(!command) goto loop_cleanup;
        else if(!strcmp(command, "help")) help(strtok(NULL, ""));
        else if(!strcmp(command, "prompt"))
            prompt(hotel_current, &echo_allowed, p);
        else if(!strcmp(command, "cd")) cd(p);

        else if(!strcmp(command, "init")) init(p);
        else if(!strcmp(command, "list")) list(hotel_current,p);
        else if(!strcmp(command, "drop")) drop(hotel_current, p);

        else if(!strcmp(command, "create-service"))
            create_service(p);
        else if(!strcmp(command, "service"))
            serve(hotel_current, strtok(NULL, ""));
        else if(!strcmp(command, "bill")) bill(hotel_current, p);
        else if(!strcmp(command, "checkout"))
            checkout(hotel_current, p);

        else if(!strcmp(command, "switch"))
            switching(hotel_current, p);
        else if(!strcmp(command, "book")) book(hotel_current,p);
        else if(!strcmp(command, "back")) back(hotel_current);

        else if(!strcmp(command, "exit")) exit(0);

        else if(sh_allowed){
            if(strtok(NULL, "")) user_input[strlen(user_input)] = ' ';
            system(user_input);
        }
        else error_print("Unknown command!");

    loop_cleanup:
        free(user_input);
        //free(p);
    }

    return 0;

cleanup:
    if(echo_allowed) putchar('\n');
    free(user_input);
    exit(0);
    return 0;
}
/* end of main.c */
