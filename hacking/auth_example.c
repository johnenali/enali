/*
 * =====================================================================================
 *
 *       Filename:  auth_example.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/22/2014 11:57:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>

int auth_func(char *passwd) {
    char passwd_buffer[16];
    int flag = 0;
    strcpy(passwd_buffer, passwd);
    if (strcmp(passwd_buffer, "12345") == 0)
        flag = 1;
    if (strcmp(passwd_buffer, "abcdefg") == 0)
        flag = 1;
    return flag;
}

int main(int argc, char *argv[]) {
    if (auth_func(argv[1]))
        printf("success!\n");
    else
        printf("No, sorry!\n");
    return 1;
}
