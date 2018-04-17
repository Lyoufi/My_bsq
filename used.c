/*
** EPITECH PROJECT, 2017
**
** File description:
** fonctions used
*/

#include "include/bsq.h"

int str_size(char *str)
{
	int     a = 0;
	int     b = 0;

	if (str == NULL)
		return (0);
	while (str[a] != '\n' && str[a] != '\0')
		a++;
	a++;
	b = a;
	while (str[a] != '\n')
		a++;
	b = b - a;
	return (a - b + 1);
}

int ret_char(char c)
{
	if (c == 'o')
		return (0);
	return (1);
}
