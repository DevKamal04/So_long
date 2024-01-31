/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapxis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:39:48 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/30 10:56:26 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SO_LONG.h"

void free_all(t_objects *objects)
{
	int i;
	
	mlx_close_window(objects->mlx);
	mlx_delete_image(objects->mlx, objects->img_bird);
	mlx_delete_image(objects->mlx,objects->img_exit);
	mlx_delete_image(objects->mlx,objects->img_wall);
	mlx_delete_image(objects->mlx,objects->img_grass);
	mlx_delete_image(objects->mlx,objects->img_donut);
	mlx_delete_texture(objects->txt_bird);
	mlx_delete_texture(objects->txt_donut);
	mlx_delete_texture(objects->txt_grass);
	mlx_delete_texture(objects->txt_exit);
	mlx_delete_texture(objects->txt_wall);
	mlx_close_window(objects->mlx);
	i = 0;
	while (objects->game[i])
		free(objects->game[i++]);
	free(objects->game);
	i = 0;
	while (objects->coins_map[i])
		free(objects->coins_map[i++]);
	free(objects->coins_map);
	mlx_terminate(objects->mlx);
	i = 0;
	while (objects->mapss[i])
		free(objects->mapss[i++]);
	free(objects->mapss);
	free(objects);
}


void get_position(t_objects *objects)
{
	objects->k = 0;
    objects->axis_y = 0;
    while (objects->game[objects->axis_y])
    {
        objects->axis_x = 0;
        while (objects->game[objects->axis_y][objects->axis_x])
        {
            if (objects->game[objects->axis_y][objects->axis_x] == 'P')
            {
                objects->position_x = objects->axis_x;
                objects->position_y = objects->axis_y;
            }
			else if (objects->game[objects->axis_y][objects->axis_x] == 'C')
            {
                objects->coins_x = objects->axis_x;
                objects->coins_y = objects->axis_y;
				objects->k++;
            }
            objects->axis_x++;
        }
        objects->axis_y++;
    }
}