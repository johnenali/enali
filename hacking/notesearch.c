/*
 * =====================================================================================
 *
 *       Filename:  notesearch.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/20/2014 07:02:56 PM
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
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "hacking.h"
#define FILENAME "/var/notes"

int print_notes(int fd, int uid, char *searchString);
int find_user_note(int fd, int uid);
int search_note(char *note, char *keyword);
void fatal(char *message);

int main(int argc, char *argv[])
{
    int userid, printing=1, fd;
    char searchString[100];

    if (argc > 1)
        strcpy(searchString, argv[1]);
    else
        searchString[0] = 0;

    userid = getuid();
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1)
        fatal("in main() while opening file for reading");

    while (printing)
        printing = print_notes(fd, userid, searchString);
    printf("--------[ end of note data ]--------\n");
    close(fd);
}

int print_notes(int fd, int uid, char *searchString)
{
    int note_length, i;
    char byte=0, note_buffer[100];

    note_length = find_user_note(fd, uid);
    if (note_length == -1)
        return 0;

    if (read(fd, note_buffer, note_length) != note_length) {
        return -1;
    }
    note_buffer[note_length] = 0;

    if (search_note(note_buffer, searchString))
        printf("%s", note_buffer);
    return 1;
}

int find_user_note(int fd, int uid)
{
    int note_uid = -1;
    unsigned char byte;
    int length;

    while (note_uid != uid) {
        if (read(fd, &note_uid, 4) != 4)
            return -1;
        if (read(fd, &byte, 1) != 1)
            return -1;

        byte = length = 0;
        while (byte != '\n') {
            if (read(fd, &byte, 1) != 1)
                return -1;
            length++;
        }
    }
    lseek(fd, length * -1, SEEK_CUR);

    //printf("[DEBUG] found a %d byte for user id %d\n", length, note_uid);
    return length;
}

int search_note(char *note, char *keyword) 
{
    int i, keyword_length, match=0;
    keyword_length = strlen(keyword);
    if (keyword_length == 0)
        return 1;
    for (i=0; i<strlen(note); i++) {
        if (note[i] == keyword[match])
            match++;
        else {
            if (note[i] == keyword[0])
                match = 1;
            else 
                match = 0;
        }
        if (match == keyword_length)
            return 1;
    }
    return 0;
}
