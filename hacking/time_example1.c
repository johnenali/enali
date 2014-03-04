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

int main() {
    long int seconds_time_since_spoch;
    struct tm current_time, *time_ptr;
    int second, minute, hour;

    seconds_time_since_spoch = time(0);
    printf("seconds since spoch: %ld\n", seconds_time_since_spoch);
    time_ptr = &current_time;
    localtime_r(&seconds_time_since_spoch, time_ptr);
    hour = current_time.tm_hour;
    minute = time_ptr->tm_min;
    second = *((int *)time_ptr);
    printf("current time is : %d : %d : %d\n", hour, minute, second);

    return 1;
}
