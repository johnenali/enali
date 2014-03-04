/*
 * =====================================================================================
 *
 *       Filename:  notetaker.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/20/2014 03:11:47 PM
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
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

void usage(char* prog_name, char* filename)
{
    printf("Usage:%s <data to add to %s>\n", prog_name, filename);
    exit(0);
}

void fatal(char*);
void *ec_malloc(unsigned int);

int main(int argc, char* argv[])
{
    int usrid, fd;
    char *buffer, *datafile;

    buffer = (char *)ec_malloc(100);
    datafile = (char *)ec_malloc(20);
    strcpy(datafile, "/var/notes");

    if (argc<2)
        usage(argv[0], datafile);
    
    strcpy(buffer, argv[1]);

    printf("[DEBUG] buffer @%p:\'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @%p:\'%s\'\n", datafile, datafile);

    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if (fd == -1)
        fatal("in main() while opening file");
    printf("[DEBUG] file descriptor is %d\n", fd);

    usrid = getuid();

    if (write(fd, &usrid, 4) == -1)
        fatal("in main() while writing usrid to file");
    write(fd, "\n", 1);

    if (write(fd, buffer, strlen(buffer)) == -1) 
        fatal("in main() while writing buffer to file");
    write(fd, "\n", 1);

    if (close(fd) == -1)
        fatal("in main() while closing file");
    printf("Note has been saved.\n");
    free(buffer);
    free(datafile);
}
