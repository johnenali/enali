/*
 * =====================================================================================
 *
 *       Filename:  hacking.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/20/2014 02:32:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
void fatal(char* message)
{
    char error_message[100];

    strcpy(error_message, "[!!] Fatal Error ");
    strncat(error_message, message,83);
    perror(error_message);
    exit(-1);
}

void *ec_malloc(unsigned int size)
{
    void* ptr;
    ptr = malloc(size);
    if (ptr == NULL)
        fatal("in ec_malloc() on memory allocation");
    return ptr;
}
