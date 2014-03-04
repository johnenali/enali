/*
 * =====================================================================================
 *
 *       Filename:  game_of_chance.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/21/2014 02:20:53 PM
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
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "hacking.h"

#define DATAFILE "/var/chance.data"

struct user {
    int uid;
    int credits;
    int highScore;
    char name[100];
    int (*current_game)();
};

int get_player_data();
void register_new_player();
void update_player_data();
void show_highscore();
void jackpot();
void input_name();
void print_cards(char *, char *, int);
int take_wager(int, int);
void play_the_game();
int pick_a_number();
int dealer_no_match();
int find_the_ace();
void fatal(char *);

struct user player;

int main() {

}

int get_player_data() {
    int userid, fd, read_bytes;
    struct user entry;
    userid = getuid();
    if ((fd = open(DATAFILE, O_RDONLY)) == -1)
        fatal("in get_player_data() while opening the datafile");
    do {
        read_bytes = read(fd, &entry, sizeof(struct user));
    } while (entry.uid!=userid && read_bytes>0);
    close(fd);
    if (read_bytes == sizeof(struct user))
        return 1;
    else
        return -1;
}
int register_new_player() {
    int fd;
    player.uid = getuid();
    player.credits = 100;
    player.highScore = 0;
    input_name();
    if ((fd = open(DATAFILE, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR)) == -1)
        fatal("in register_new_player() while opening datafile");
    if (write(fd, &player, sizeof(struct user)) == -1)
        fatal("in register_new_player() while write datafile");
    close(fd);
    return 1;
}
void input_name() {
    char scanf_char, *char_ptr;
    do
        scanf("%c", &scanf_char);
    while (scanf_char == '\n');
    char_ptr = (char *)&(player.name);
    do {
        *char_ptr++ = scanf_char;
        scanf("%c", &scanf_char
    } while (scanf_char != '\n');
    *char_ptr = 0;
}
void show_highscore() {
    int top_score, fd;
    if ((fd=open(DATAFILE, O_RDONLY)) == -1)
        fatal("in show_highscore() while opening the datafile");

}
