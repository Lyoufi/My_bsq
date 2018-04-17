/*
** EPITECH PROJECT, 2017
** 
** File description:
** bsq.h
*/

#ifndef BSQ_H_
#define	BSQ_H_

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct coord
{
	int	x;
	int	y;
}		coord_t;

int my_putstr(char *str);
int str_size(char *str);
int my_strlen(char *str);
int show_str(int **tab, char *str, int *i, int n);
void my_putchar(char c);
char **my_str_to_word_array(char *str);
int **my_map_to_int_array(char **map, char *str);
int ret_char(char c);
char *my_strcat(char *dest, char *src);
int my_getnbr(char const *str);
int minesweeper(int **tab, int x, int y);
int get_nbline(char *str);
int get_cols(char *str);
int check_tab_for_fill(int **tab, char *str, coord_t *coord);
void my_put_nbr(int nombre);
void to_coords(int **tab, char **map, coord_t *coord, char *str);

#endif /* BSQ_H */
