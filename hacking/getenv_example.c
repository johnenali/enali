/*
 * =====================================================================================
 *
 *       Filename:  getenv_example.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/22/2014 04:08:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    printf("%s address is %p\n", argv[1], getenv(argv[1]));
    return 1;
}
