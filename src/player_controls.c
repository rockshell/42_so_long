/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:51:48 by arch              #+#    #+#             */
/*   Updated: 2024/06/08 18:39:21 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    gather_chest(t_params *params, t_assets a, int x, int y)
{
	t_map	**m;
	mlx_t	*w;

	m = params->map;
	w = (*m)->window;
	
	mlx_image_to_window(w, a.floor, x*56, y*56);
	(*m)->tiles[(*m)->player.x][(*m)->player.y].type = '0';
	if ((*m)->count_collectibles > 0)
		(*m)->count_collectibles -= 1;
	if ((*m)->count_collectibles == 0)
		(*m)->exit_available = true;
}

void    move_player(t_params *params, t_assets a, int x, int y)
{
	t_map	**m;
	mlx_t	*w;
	// t_tile	player;

	m = params->map;
	w = (*m)->window;
	// player = (*m)->player;
	if (!(*m)->tiles[(*m)->player.x+x][(*m)->player.y+y].passable)
		return ;
	mlx_image_to_window(w, a.floor, ((*m)->player.x)*56, ((*m)->player.y)*56);
	if ((*m)->tiles[(*m)->player.x][(*m)->player.y].type == 'E')
		mlx_image_to_window(w, a.e, ((*m)->player.x)*56, ((*m)->player.y)*56);
	(*m)->player.x += x;
	(*m)->player.y += y;
	if ((*m)->tiles[(*m)->player.x][(*m)->player.y].type == 'C')
		gather_chest(params, a, (*m)->player.x, (*m)->player.y);
	mlx_image_to_window(w, a.player, ((*m)->player.x)*56, ((*m)->player.y)*56);
	(*m)->count_moves += 1;
	ft_printf("%i\n", (*m)->count_moves);
	if ((*m)->tiles[(*m)->player.x][(*m)->player.y].type == 'E')
	{
		if ((*m)->exit_available)
			mlx_close_window(w);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*params;
	t_map		**map;
	mlx_t		*window;
	t_assets	assets;

	params = (t_params *)param;
	map = params->map;
	window = (*map)->window;
	assets = params->assets;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(params, assets, 0, -1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(params, assets, -1, 0);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(params, assets, 0, 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(params, assets, 1, 0);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(window);
}
