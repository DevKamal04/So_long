/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SO_LONG.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:05:27 by kamsingh          #+#    #+#             */
/*   Updated: 2024/01/26 17:54:39 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "LIBFT/libft.h"
# include "ft_printf/ft_printf.h"
// # include "get_next_line/get_next_line_bonus.c"
// # include "get_next_line/get_next_line_bonus_utils.c"
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_objects
{
	mlx_t			*mlx;
	mlx_texture_t	*txt_wall;
	mlx_image_t		*img_wall;
	mlx_texture_t	*txt_bird;
	mlx_image_t		*img_bird;
	mlx_texture_t	*txt_donut;
	mlx_image_t		*img_donut;
	mlx_image_t		*img_grass;
	mlx_texture_t	*txt_grass;
	mlx_texture_t	*txt_exit;
	mlx_image_t		*img_exit;
	mlx_texture_t   *txt_tornado;
	mlx_image_t 	*img_tornado;
	char			**game;
	char			**mapss;
	int32_t			**coins_map;
	int				coins;
	int				coins_tmp;
	int				axis_y;
	int				*new_y;
	int				axis_x;
	int				*new_x;
	int				i;
	 int				count_E;
 	int				count_P;
	 int				count_C;
	int counter;
	int				collected_coins;
	int x;
	int y;
	int j;
	int key_x;
	int key_y;
	int position_x;
	int position_y;
	int coins_x;
	int coins_y;
	int k;
}					t_objects;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;


typedef struct s_birdy
{
	int				x;
	int				y;
	int				*coins_tmp;
	int				*coins;
}					t_birdy;

int					load(t_objects *objects);
int					texture(t_objects *objects);
char				**read_map(const char *filename, int *width, int *height);
int					initialize_game(t_objects *objects, const char *filename);
void				map_filler(t_objects *objects);
int					is_border_filled_with_1(t_objects *objects);
int					map_init(t_objects *objects, const char *filename);
bool				fill(t_objects *objects, t_point cur, char to_fill);
bool				can_reach_exit(t_objects *objects, t_point begin);
void				map_filler_helper(t_objects *objects);
// void				ft_hook(void *param);
// void				ft_player(void *param);
// int					ft_check_wall(t_objects *objects, int y, int x);
char				*get_next_line(int fd);
int					count_E_P_C(t_objects *objects, int *count_E, int *count_P, int *count_C);
// int					check_E_surrounded_by_1(t_objects *objects);
void	map_coins_filler(t_objects *objects);
int check_E_surrounded_by_1(t_objects *objects);
int					check_map_surroundings(t_objects *objects);
void				checkRectangularMap(t_objects *objects);
int					ft_check_wall(t_objects *objects, int y, int x);
void				ft_player(void *param);
void 				ft_hook_one(mlx_key_data_t keydata, void* param);
void				ft_hook(void *param);
int	count_lines(const char *filename);
void free_all(t_objects *objects);
int check_surroundings(t_objects *objects);
int check_letters(t_objects *objects);
int check_E_surrounded_by_1(t_objects *objects);
int check__map(t_objects *objects);
int	ft_exit(t_objects *objects, int y, int x);
int upper_move(t_objects *objects);
int down_move(t_objects *objects);
int right_move(t_objects *objects);
int left_move(t_objects *objects);
void get_position(t_objects *objects);
bool open_map(t_objects *objects, int y, int x);
void copy_map(t_objects *objects);
bool ft_game_is_reachable(t_objects *objects, int y, int x);
bool rechk(t_objects *objects, int y, int x);
bool open_map(t_objects *objects, int y, int x);
void print_map(t_objects *objects);
char	**flood_fill(t_objects *obj,int x, int y, int dir);
int	check_everything(t_objects *objects);
int last_check(t_objects *objects);
void check_ber(int argc, char *argv[]);
void coin_map(t_objects *objects);
#endif