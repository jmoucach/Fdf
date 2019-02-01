/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:02:21 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/18 15:49:30 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		word_count(char *str, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c & str[i] != '\0')
			i++;
	}
	return (count);
}
int		count_size_map(char *str, int *nbword)
{
	int		fd;
	char	*line;
	int 	i;

	i = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		*nbword = word_count(line, ' ');
		i++;
	}
	close(fd);
	return (i);
}

int		**generate_map(int nbline, int nbword)
{
	int		**map;
	int		i;

	i = 0;
	if (!(map = (int**)malloc(sizeof(*map) * nbline)))
		exit(EXIT_FAILURE);
	while (i < nbline)
	{
		if (!(map[i] = (int*)malloc(sizeof(**map) * nbword)))
			exit(EXIT_FAILURE);
		i++;
	}
	return (map);
}

void	map_filler(t_map *map_data, char *file_name)
{
	int		fd;
	char	*line;
	int		i;
	char	**split;

	i = 0;
	fd = open(file_name, O_RDONLY);
	(*map_data).x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		free(line);
		(*map_data).y = 0;
		while (split[(*map_data).y])
		{
			(*map_data).map[(*map_data).x][(*map_data).y] = atoi(split[(*map_data).y]);
			(*map_data).y++;
		}
		(*map_data).x++;
		free(split);
	}
	close(fd);
}

void	print_int_tab(int **int_tab, int nbline, int nbword)
{
	int i;
	int j;

	i = 0;
	while (i < nbline)
	{
		j = 0;
		while (j < nbword)
		{
			ft_putnbr(int_tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

t_map	map_creation(char *file_name)
{
	t_map	map_data;
	map_data.nbline = count_size_map(file_name, &(map_data.nbword));
	map_data.map = generate_map(map_data.nbline, map_data.nbword);
	map_filler(&map_data, file_name);
	print_int_tab(map_data.map, map_data.nbline, map_data.nbword);
	return (map_data);
}
