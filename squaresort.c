/*
** EPITECH PROJECT, 2017
**
** File description:
** sort for bsq
*/

#include "include/bsq.h"

int minesweeper(int **tab, int x, int y)
{
       	int     top;
	int	top_left;
	int	left;
	
	top_left = (x > 0 && y > 0)?tab[x - 1][y - 1]:0;
	left = (x > 0)?tab[x - 1][y]:0;
	top = (y > 0)?tab[x][y - 1]:0;
	if (top <= left && top <= top_left)
		return (top + 1);
	else if (left <= top && left <= top_left)
		return (left + 1);
	else if (top_left <= top && top_left <= left)
		return (top_left + 1);
	else
		return (tab[x][y] + 1);
}

int get_nbline(char	*str)
{
	int	scan = 0;
	int	count = 0;

	while (str[scan] != '\0') {
		if (str[scan] == '\n')
			count++;
		scan++;
	}
	return (count);
}

int	get_cols(char *str)
{ 
	int	i = 0;

	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int check_tab_for_fill(int **tab, char *str, coord_t *coord)
{
	int	i = 0;
	int	n = 0;
	int	pos = 0;
	
	while (i < get_nbline(str)) {
		while (n < get_cols(str)) {
			if (tab[i][n] > 0) {
				tab[i][n] = minesweeper(tab, i, n);
				if (pos < tab[i][n]) {
					pos = tab[i][n];
					coord->x = i;
					coord->y = n;
				}
			}
			n++;
		}
		i++;
		n = 0;
	}
	return (pos);
}

void to_coords(int **tab, char **map, coord_t *coord, char *str)
{
	int	pos = check_tab_for_fill(tab, str, coord);
	int	pos_x = coord->x;
	int	pos_y = coord->y;
	int	x = pos;
	int	y = pos;

	while (x > 0) {
		while (y > 0) {
			map[pos_x][pos_y] = 'x';
			pos_y = pos_y - 1;
			y = y - 1;
		}
		y = pos;
		pos_x = pos_x - 1;
		x = x - 1;
		pos_y = coord->y;
	}
}
