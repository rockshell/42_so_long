/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:58:05 by akulikov          #+#    #+#             */
/*   Updated: 2024/06/01 13:54:13 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	t_mlx;

typedef struct s_tile
{
	char		type;
	int			x;
	int			y;
	bool		passable;
	bool		pass_check;
}	t_tile;

typedef struct s_map
{
	int			width;
	int			height;
	int			count_collectibles;
	int			count_exits;
	int			count_players;
	bool		wall_integrity;
	t_tile		start;
	t_tile		exit;
	t_tile		**tiles;
}	t_map;


int		load_map(const char *filename, t_map **map);
void	check_map(t_map **map);


#endif