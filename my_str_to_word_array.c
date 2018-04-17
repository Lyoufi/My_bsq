/*
** EPITECH PROJECT, 2017
** 
** File description:
** My_str_to_word_array
*/

#include "include/bsq.h"

int tab_size(char *str)
{
	int	size = 0;
	int	i = 0;
	
	if (str == NULL)
		return (0);
	while (str[i]) {
		i++;
		if (str[i] == '\n')
			size++;
	}
	return (size + 1);
}

int show_str(int **tab, char *str, int *i, int n)
{
	int	x = 0;
	
	while (tab[*i] != '\0') {
		tab[n][x] = ret_char(str[*i]);
		*i = *i + 1;
		x++;
	}
	*i = *i + 1;
	return (x);
}

int **my_map_to_int_array(char **map, char *str)
{
	int	n = 0;
	int	j = 0;
	int	**tab = NULL;

	tab = malloc(sizeof(int*) * tab_size(str));
	if (tab == NULL)
		return (NULL);
	if (map == NULL)
		return (NULL);
	while (map[n] != NULL) {
		j = 0;
		tab[n] = malloc(sizeof(int) * str_size(str));
		if (tab[n] == NULL)
			return (NULL);
		while (map[n][j] != '\0') {
			if (map[n][j] == 'o')
				tab[n][j] = 0;
			else if (map[n][j] == '.')
				tab[n][j] = 1;
			else
				tab[n][j] = map[n][j] - '0';
			j++;
		}
		tab[n][j] = -1;
		n++;
	}
	tab[n] = NULL;
	return (tab);
}


char **my_str_to_word_array(char *str)
{
	int	i = 0;
	int	n = 0;
	int	j = 0;
	int	c = str_size(str);
	char	**tab = NULL;
	
	tab = malloc(sizeof(char*) * tab_size(str));
	if (tab == NULL)
		return (NULL);
	if (str == NULL || str[0] == '\0')
		return (NULL);
	while (str[i] != '\0') {
		j = 0;
		tab[n] = malloc(sizeof(char) * c);
		if (tab[n] == NULL)
			return (NULL);
		while (str[i] != '\n' && str[i] != '\0') {
			tab[n][j] = str[i];
			i++;
			j++;
		}
		tab[n][j] = '\0';
		i++;
		n++;
	}
	tab[n] = NULL;
	return (tab);
}
