/*
 * =====================================================================================
 *
 *       Filename:  time_example1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/21/2014 12:18:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enali (Li), johnenali2011@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <time.h>
void dump_time_from_struct_tm(struct tm *time_ptr, int size) {
    unsigned char *char_ptr;
    int i;
    printf("char pointer size is :%ld\n", sizeof(char_ptr));
    char_ptr = (unsigned char *)time_ptr;
    for (i=0; i<size; i++) {
        printf("%02x ", char_ptr[i]);
        if (i % 16 == 15)
            printf("\n");
    }
    printf("\n");
}

int main() {
    long int seconds_time_since_spoch;
    struct tm current_time, *time_ptr;
    int second, minute, hour, *int_ptr, i;
    printf("struct tm pointer size is :%ld\n", sizeof(time_ptr));
    printf("int pointer size is :%ld\n", sizeof(int_ptr));

    seconds_time_since_spoch = time(0);
    printf("seconds since spoch: %ld\n", seconds_time_since_spoch);
    time_ptr = &current_time;
    localtime_r(&seconds_time_since_spoch, time_ptr);
    hour = current_time.tm_hour;
    minute = time_ptr->tm_min;
    second = *((int *)time_ptr);
    printf("current time is : %d : %d : %d\n", hour, minute, second);

    dump_time_from_struct_tm(time_ptr, sizeof(struct tm));
    int_ptr = (int *)time_ptr;
    for (i=0; i<3; i++) {
        printf("int_ptr @%p : %d\n", int_ptr, *int_ptr);
        int_ptr++;
    }

    return 1;
}
