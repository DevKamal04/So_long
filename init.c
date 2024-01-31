/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:55:47 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/30 10:50:52 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SO_LONG.h"

int	initialize_game(t_objects *objects, const char *filename)
{
	objects->game = read_map(filename, &objects->axis_x, &objects->axis_y);
	if (check_surroundings(objects) == 1)
		exit(EXIT_FAILURE);
	if (check_letters(objects) == 1)
		exit(EXIT_FAILURE);
	if (check__map(objects) == 1)
		exit(EXIT_FAILURE);
	get_position(objects);
	copy_map(objects);
	coin_map(objects);
	objects->mapss = flood_fill(objects , objects->position_x, objects->position_y, ' ');
	if (last_check(objects) == 1)
		exit(EXIT_FAILURE);
	objects->mlx = mlx_init(objects->axis_x * 64, objects->axis_y * 64, "MY GAME", false);
	return (0);
}


int map_init(t_objects *objects, const char *filename)
{
	objects->i = 0;
	objects->collected_coins = 0;
	initialize_game(objects, filename);
	map_filler(objects);
	return (0);
}

void leak()
{
	system("leaks so_long");
}

// void check_ber(int argc, char *argv[])
// {
// 	char *let;
// 	const char *filename;

// 	(void)argc;
// 	filename = argv[1];
// 	let = ".ber";
// 	if (strcmp(filename, let) != 0)
// 		{
// 			ft_printf("error");
// 			exit(EXIT_FAILURE);
// 		}
// }


int main(int argc, char *argv[])
{
	t_objects *objects;
	const char *filename;
	// char *let;
	atexit(leak);
	filename = argv[1];
	if (argc != 2)
	{
		ft_printf("map name wrong\n");
		return (1);
	}	
	// if (*filename && *filename != ".ber")
	// 	ft_printf("kalexi");
	objects = malloc(sizeof(t_objects));
	if (objects == NULL)
		return (-1);
	if (map_init(objects, filename) != 0)
	{
		free(objects);
		return (-1);
	}
	mlx_key_hook(objects->mlx, ft_hook_one, (void *)objects);
	mlx_loop(objects->mlx);
	free_all(objects);
	return 0;
}
