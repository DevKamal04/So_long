/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:29:27 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/30 10:58:20 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SO_LONG.h"

int	ft_check_wall(t_objects *objects, int y, int x)
{
	if (y < 0)
	{
		if (objects->game[objects->img_bird->instances[0].y / 64
			- 1][objects->img_bird->instances[0].x / 64] == '1')
			return (1);
	}
	else if (y > 0)
	{
		if (objects->game[objects->img_bird->instances[0].y / 64
			+ 1][objects->img_bird->instances[0].x / 64] == '1')
			return (1);
	}
	else if (x < 0)
	{
		if (objects->game[objects->img_bird->instances[0].y
			/ 64][objects->img_bird->instances[0].x / 64 - 1] == '1')
			return (1);
	}
	else if (x > 0)
	{
		if (objects->game[objects->img_bird->instances[0].y
			/ 64][objects->img_bird->instances[0].x / 64 + 1] == '1')
			return (1);
	}
	return (0);
}

void	ft_check_coin(t_objects *objects)
{
    int	index;

    if (objects->game[objects->img_bird->instances[0].y
        / 64][objects->img_bird->instances[0].x / 64] == 'C')
    {

        index = objects->coins_map[objects->img_bird->instances[0].y / 64][objects->img_bird->instances[0].x / 64];
        if (index >= 0 && objects->img_donut->instances[index].enabled) 
        {
            objects->img_donut->instances[index].enabled = false;
            objects->collected_coins++;
        }
    }
}

int	ft_exit(t_objects *objects, int y, int x)
{
	if (objects->game[y][x] == 'E')
	{
		ft_printf("%d,    %d\n", objects->k, objects->collected_coins);
		if ((int)objects->collected_coins == objects->k)
			exit(0);
		return (1);
	}
	return(0);
}

int upper_move(t_objects	*objects)
{
		if (!ft_exit(objects, objects->img_bird->instances[0].y / 64 - 1,
		 		objects->img_bird->instances[0].x / 64))
			{
				
			objects->img_bird->instances[0].y -= 64;
			ft_printf("Number of movements .. %d\n", objects->counter);
			objects->counter++;		
			}
		ft_check_coin(objects);

	return (0);
}


int down_move(t_objects	*objects)
{
		if (!ft_exit(objects, objects->img_bird->instances[0].y / 64 + 1,
		 		objects->img_bird->instances[0].x / 64))
			{
				
			objects->img_bird->instances[0].y += 64;
			ft_printf("Number of movements .. %d\n", objects->counter);
			objects->counter++;	
			}
		ft_check_coin(objects);
	return (0);
}

int left_move(t_objects	*objects)
{
		if (!ft_exit(objects, objects->img_bird->instances[0].y / 64 ,
		 		objects->img_bird->instances[0].x / 64 - 1))
			{
				objects->img_bird->instances[0].x -= 64;
				ft_printf("Number of movements .. %d\n", objects->counter);
				objects->counter++;				
			}
		
		ft_check_coin(objects);
				
	return (0);
}

int right_move(t_objects	*objects)
{

		if (!ft_exit(objects, objects->img_bird->instances[0].y / 64,
		 		objects->img_bird->instances[0].x / 64 + 1))
			{
				
			objects->img_bird->instances[0].x += 64;
			ft_printf("Number of movements .. %d\n", objects->counter);
			objects->counter++;				
			}
		ft_check_coin(objects);
	return (0);
}


void	ft_hook_one(mlx_key_data_t keydata, void *param)
{
	t_objects	*objects;

	objects = (t_objects *)param;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(objects->mlx);
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_W
		&& ft_check_wall(objects, -1, 0) == 0)
		upper_move(objects);		
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_S
		&& ft_check_wall(objects, +1, 0) == 0)
		down_move(objects);
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_A
		&& ft_check_wall(objects, 0, -1) == 0)
		left_move(objects);
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_D
		&& ft_check_wall(objects, 0, +1) == 0)
		right_move(objects);
}
