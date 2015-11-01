/* get-name.c */
/* Date  : 31 October 2015
 * Author: Ankit Pati
 */

#include "../defs/functions.h"
#include "../defs/structures.h"

char *get_name(char *prompt, char *name, char *argument)
{
    char *user_input;

    if(!argument){
        printf("%s: ", prompt);
        fflush(stdout);

        user_input = argument = getstr();
    }
    else user_input = NULL;

    if(strlen(argument) > NAME_PRE_MAXIMUM){
        error_print("Too large!");
        free(user_input);
        return NULL;
    }

    strcpy(name, to_name(argument));

    free(user_input);
    return name;
}
/* end of get-name.c */