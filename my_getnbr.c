/*
** EPITECH PROJECT, 2017
**
** File description:
*/

#include "include/bsq.h"

int	my_getnbr(char const *str)
{
	int   i = 0;
	int   j = 1;
	int   n;

	while (str[i] && (str[i] == '+' || str[i] == '-')) {
		if (str[i] == '-')
			j = j - 1;
		i = i + 1;
	}
	str = str + i;
	n = 0;
	while (str[i]) {
		if (str[i] >= '0' && str[i] <= '9') {
		  n = n * 10;
		  n = n - (str[i] - '0');
		}
		i = i + 1;
	  }
	  return (n * j * -1);
}
