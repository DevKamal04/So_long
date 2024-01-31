/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:06:09 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/26 17:46:15 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SO_LONG.h"

int	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		y++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (y);
}

char	**read_map(const char *filename, int *width, int *height)
{
	int		fd;
	int		y;
	char	**map;

	*height = count_lines(filename);
	if (*height < 1)
	{
		write(1,"wrong maps", 10);
		exit(EXIT_FAILURE);
	}
	map = calloc(*height + 1, sizeof(char *));
	y = 0;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		map[y] = get_next_line(fd);
		if (!map[y])
			break ;
		y++;
	}
	*width = ft_strlen(map[0]) - 1;
	close(fd);
	return (map);
}

int	check_surroundings(t_objects *objects)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < objects->axis_x)
	{
		if (objects->game[0][i] != '1' || objects->game[objects->axis_y
			- 1][i] != '1')
			return (1);
		i++;
	}
	while (j < objects->axis_y)
	{
		if (objects->game[j][0] != '1' || objects->game[j][objects->axis_x
			- 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check__map(t_objects *objects)
{
	int	i;

	i = 1;
	while (i < objects->axis_y)
	{
		if (i == objects->axis_y - 1 && ft_strlen(objects->game[0])
			- 1 != ft_strlen(objects->game[i]))
			{
			ft_printf("error\n");
			return (1);
			}
		if (i != objects->axis_y - 1
			&& ft_strlen(objects->game[0]) != ft_strlen(objects->game[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_letters(t_objects *objects)
{
	objects->count_E = 0;
	objects->count_P = 0;
	objects->count_C = 0;
	objects->axis_y = 0;
	while (objects->game[objects->axis_y])
	{
		objects->axis_x = 0;
		while (objects->game[objects->axis_y][objects->axis_x])
		{
			if (objects->game[objects->axis_y][objects->axis_x] == 'E')
				objects->count_E++;
			if (objects->game[objects->axis_y][objects->axis_x] == 'C')
				objects->count_C++;
			if (objects->game[objects->axis_y][objects->axis_x] == 'P')
				objects->count_P++;
			objects->axis_x++;
		}
		objects->axis_y++;
	}
	if (objects->count_E != 1 || objects->count_P != 1 || objects->count_C == 0)
	{
		ft_printf("wrong characters !\n");
		return (1);
	}
	return (0);
}
