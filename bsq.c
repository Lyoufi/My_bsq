/*
** EPITECH PROJECT, 2017
** 
** File description:
** main file
*/

#include "include/bsq.h"


char    *get_buffer_without_nb_row(char *buffer)
{
	char    *new_buff = NULL;
	int	buff_len = 0;
	int     i = 0;
	int	j = 0;

	buff_len = my_strlen(buffer);
	while (buffer[i] != '\n')
		i++;
	i++;
	new_buff = malloc(sizeof(buffer) * buff_len);
	while (buffer[i] != '\0')
	{
		new_buff[j] = buffer[i];
		j++;
		i++;
	}
	new_buff[j] = '\0';
	return (new_buff);

}


char *get_map(char *filename, char *buffer)
{
	int             fd;
	char		*new_buff = NULL;
	struct stat     size;

	if ((stat(filename, &size)) == -1)
		exit(84);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		write(1, "Can't open the file.\n", 21);
	buffer = malloc(sizeof(char) * (size.st_size + 1));
	if (buffer == NULL)
		exit(84);
	if (read(fd, buffer, size.st_size) == -1)
		write(1,"Can't open the file.\n", 21);
	buffer[size.st_size] = '\0';
	if (close(fd) == -1)
		exit(84);
	new_buff = get_buffer_without_nb_row(buffer);
	return (new_buff);
}

void	my_put_tab(char **tab)
{
	int	x = 0;
	int	y = 0;
	
	while (tab[x] != NULL) {
		y = 0;
		while (tab[x][y] != '\0') {
			my_putchar(tab[x][y]);
			y++;
		}
		my_putchar('\n');
		x++;
	}
}

int main(int ac, char **av)
{
	char	*buff = NULL;
	char	**tab;
	int	**int_tab = NULL;
	coord_t	*coord = NULL;

	coord = malloc(sizeof(coord_t));
	ac = ac;
	buff = get_map(av[1], buff);
	tab = my_str_to_word_array(buff);
	int_tab = my_map_to_int_array(tab, buff);
	check_tab_for_fill(int_tab, buff, coord);
	to_coords(int_tab, tab, coord, buff);
	my_put_tab(tab);
	return (0);
}
