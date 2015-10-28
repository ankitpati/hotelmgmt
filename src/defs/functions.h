/* functions.h */
/* Date  : 28 October 2015
 * Author: Ankit Pati
 */

#ifndef apFUNCTIONS_H
#define apFUNCTIONS_H

#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>

char *getstr();

void die(char *message);

char *to_filename(char *s);
char *to_name(char *s);
int to_whole(char *s);

void init(char *hotel_name);
void list();
void drop(char *hotel_current, char *hotel_name);
void switching(char *hotel_current, char *hotel_name);
void back(char *hotel_current);
void book(char *hotel_current, char *guest);

int main(int argc, char **argv);

#endif
/* end of functions.h */