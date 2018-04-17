/*
** EPITECH PROJECT, 2017
** 
** File description:
** basic functions used for bsq
*/

#include "include/bsq.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_strlen(char *str)
{
	int	i = 0;
	
	while (str[i] != '\0')
		i++;
	return (i);
}

int	my_putstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}

char    *my_strcat(char *dest, char *src)
{
	int   i;
	int   j;
	char  *tmp;

	if ((tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (dest != NULL)
	{
		while (dest[j] != '\0')
		{
			tmp[j] = dest[j];
			j = j + 1;
		}
	}
	while (src[i] != '\0')
	{
		tmp[j] = src[i];
		j = j + 1;
		i = i + 1;
	}
	tmp[j] = '\0';
	return (tmp);
}

void my_put_nbr(int nombre)
{
	if( nombre < 0)
	{
		my_putchar('-');
		nombre = -nombre;
	}
	if( nombre >= 9)
	{
		my_put_nbr(nombre / 10);
		my_putchar(nombre % 10 + 48);
	}
	else
		my_putchar(nombre + 48);
}
