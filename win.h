//#define AAA
#ifndef _WIN_H_
#define _WIN_H_
#include <stdlib.h>
#include <stdio.h>
int galoop(void);
int gbloop(void);
int game_init(void);
int game_exit();
int game_start();
void board();
int set_OK();
int	select_rule();
int	game();
int	check_end();
void board(char *);
#define A_status 0
#define B_status 1
#define whosturn 2
#define A_win 3
#define B_win 4
#define rule 5
#define A_DATA 6
#define B_DATA 7
#define board_offset 8
int is_win(char *);


#endif