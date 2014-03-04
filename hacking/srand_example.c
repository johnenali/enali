/*
 * =====================================================================================
 *
 *       Filename:  srand_example.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/21/2014 12:56:50 PM
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

int main() {
    int i;
    printf("RAND_MAX is %d\n", RAND_MAX);
    srand(time());
    for (i=0; i<8; i++) {
        printf("rand result #%d: %d\n", i+1, rand());
    }

    printf("rand between 1 to 20: \n");
    for (i=0; i<8; i++) {
        printf("rand result #%d: %d\n", i+1, (rand()%20)+1);
    }
    return 1;
}
