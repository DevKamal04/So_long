/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:18:48 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/30 18:32:28 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SO_LONG.h"

int	load(t_objects *objects)
{
	objects->txt_donut = mlx_load_png("pictures/Staruss.png");
	objects->txt_grass = mlx_load_png("pictures/grass2.png");
	objects->txt_exit = mlx_load_png("pictures/exit.png");
	objects->txt_wall = mlx_load_png("pictures/wall.png");
	objects->txt_bird = mlx_load_png("pictures/Hydrogust.png");
	return (0);
}

int	texture(t_objects *objects)
{
	objects->img_bird = mlx_texture_to_image(objects->mlx, objects->txt_bird);
	objects->img_grass = mlx_texture_to_image(objects->mlx, objects->txt_grass);
	objects->img_donut = mlx_texture_to_image(objects->mlx, objects->txt_donut);
	objects->img_wall = mlx_texture_to_image(objects->mlx, objects->txt_wall);
	objects->img_exit = mlx_texture_to_image(objects->mlx, objects->txt_exit);

	return (0);
}

void	map_filler_helper(t_objects *objects)
{
	objects->axis_y = 0;
	while (objects->game[objects->axis_y]) 
	{
		objects->axis_x = 0;
		while (objects->game[objects->axis_y][objects->axis_x])
		{
			if (objects->game[objects->axis_y][objects->axis_x] == 'P')
			{
				mlx_image_to_window(objects->mlx, objects->img_bird,
					objects->axis_x * 64, objects->axis_y * 64);
			}
			else if (objects->game[objects->axis_y][objects->axis_x] == 'E')
			{
				mlx_image_to_window(objects->mlx, objects->img_exit,
					objects->axis_x * 64, objects->axis_y * 64);
			}
			objects->axis_x++;
		}
		objects->axis_y++;
	}
	map_coins_filler(objects);
}

void	map_coins_filler(t_objects *objects)
{
	objects->axis_y = 0;
	while (objects->game[objects->axis_y])
	{
		objects->axis_x = 0;
		while (objects->game[objects->axis_y][objects->axis_x])
		{
			if (objects->game[objects->axis_y][objects->axis_x] == 'C')
			{
					objects->coins_map[objects->axis_y][objects->axis_x] = mlx_image_to_window(objects->mlx,
						objects->img_donut, objects->axis_x * 64,
						objects->axis_y * 64);
			}
			objects->axis_x++;
		}
		objects->axis_y++;
	}
}

void	map_filler(t_objects *objects)
{
	objects->axis_y = 0;
	load(objects);
	texture(objects);
	while (objects->game[objects->axis_y])
	{
		objects->axis_x = 0;
		while (objects->game[objects->axis_y][objects->axis_x])
		{
			if (objects->game[objects->axis_y][objects->axis_x] == '1')
			{
				mlx_image_to_window(objects->mlx, objects->img_wall,
					objects->axis_x * 64, objects->axis_y * 64);
			}
			else
			{
				mlx_image_to_window(objects->mlx, objects->img_grass,
					objects->axis_x * 64, objects->axis_y * 64);
			}
			objects->axis_x++;
		}
		objects->axis_y++;
	}
	map_filler_helper(objects);
}

void	copy_map(t_objects *objects)
{
	objects->j = 0;
	objects->mapss = malloc((objects->axis_y + 1) * sizeof(char *));
	objects->key_y = 0;
	while (objects->key_y < objects->axis_y)
	{
		objects->mapss[objects->key_y] = ft_strdup(objects->game[objects->key_y]);
		objects->key_y++;
	}
	objects->mapss[objects->key_y] = NULL;
}

void	coin_map(t_objects *objects)
{
	objects->j = 0;
	objects->coins_map = malloc((objects->axis_y + 1) * sizeof(int32_t *));
	objects->key_y = 0;
	while (objects->key_y < objects->axis_y)
	{
		objects->coins_map[objects->key_y] = malloc((objects->axis_x) * sizeof(int32_t));
		objects->key_x = 0;
		while (objects->key_x < objects->axis_x)
		{
			objects->coins_map[objects->key_y][objects->key_x] = -2;
			objects->key_x++;
		}
		objects->key_y++;
	}
	objects->coins_map[objects->key_y] = NULL;
}

int last_check(t_objects *objects)
{
	objects->axis_y = 0;
	while (objects->mapss[objects->axis_y])
	{
		objects->axis_x = 0;
		while (objects->mapss[objects->axis_y][objects->axis_x])
	{
		if(objects->mapss[objects->axis_y][objects->axis_x] == 'E' || objects->mapss[objects->axis_y][objects->axis_x] == 'C')
			{
				write(1,"RETRY THE MAP",13);
				return(1);
			}
		objects->axis_x++;
	}
	objects->axis_y++;
	}
	return (0);
}


char	**flood_fill(t_objects *obj, int x, int y, int dir)
{
	if (y < 0 || x < 0 || x > obj->axis_x - 1 || y > obj->axis_y - 1 || (obj->mapss[y][x] == '1') || (obj->mapss[y][x] == 'X'))
		return (obj->mapss);
	obj->mapss[y][x] = 'X';

	if (dir != 'U')
		obj->mapss = flood_fill(obj, x, y + 1, 'D');
	if (dir != 'D')
		obj->mapss = flood_fill(obj, x, y - 1, 'U');
	if (dir != 'L')
		obj->mapss = flood_fill(obj, x + 1, y, 'R');
	if (dir != 'R')
		obj->mapss = flood_fill(obj, x - 1, y, 'L');
	return (obj->mapss);
}

