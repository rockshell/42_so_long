/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:51:48 by arch              #+#    #+#             */
/*   Updated: 2024/06/07 18:13:54 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    gather_chest(t_map **map, mlx_t *window, t_assets assets, int x, int y)
{
    mlx_image_to_window(window, assets.floor, x*56, y*56);
    if ((*map)->count_collectibles > 0)
        (*map)->count_collectibles -= 1;
    if ((*map)->count_collectibles == 0)
        (*map)->exit_available = true;
}

void    exit_check(t_map **map, mlx_t *window)
{
    if ((*map)->exit_available)
        mlx_close_window(window);
}

void    move_player(t_map **map, mlx_t *window, t_assets assets, int x, int y)
{
    if (!(*map)->tiles[(*map)->player.x+x][(*map)->player.y+y].passable)
        return ;
    if ((*map)->tiles[(*map)->player.x][(*map)->player.y].type != 'E')
    {
        (*map)->tiles[(*map)->player.x][(*map)->player.y].type = '0';
        mlx_image_to_window(window, assets.floor, ((*map)->player.x)*56, ((*map)->player.y)*56);
    }
    (*map)->player.x += x;
    (*map)->player.y += y;
    if ((*map)->tiles[(*map)->player.x][(*map)->player.y].type == 'C')
        gather_chest(map, window, assets, (*map)->player.x, (*map)->player.y);
    mlx_image_to_window(window, assets.player, ((*map)->player.x)*56, ((*map)->player.y)*56);
    (*map)->count_moves += 1;
    printf("%i\n", (*map)->count_moves);
    if ((*map)->tiles[(*map)->player.x][(*map)->player.y].type == 'E')
        exit_check(map, window);
    (*map)->tiles[(*map)->player.x][(*map)->player.y].type = 'P';
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
    t_params *params = (t_params *)param;
    t_map **map = params->map;
    mlx_t *window = params->window;
    t_assets assets = params->assets;
    
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        move_player(map, window, assets, 0, -1);
        
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        move_player(map, window, assets, -1, 0);
        
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        move_player(map, window, assets, 0, 1);    
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
            move_player(map, window, assets, 1, 0);
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(window);
}
