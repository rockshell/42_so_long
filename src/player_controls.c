/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:51:48 by arch              #+#    #+#             */
/*   Updated: 2024/06/06 23:31:54 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void my_keyhook(mlx_key_data_t keydata, void *param)
{
    t_params *params = (t_params *)param;
    t_map **map = params->map;
    mlx_t *window = params->window;
    t_assets assets = params->assets;
    
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
    {
        if ((*map)->tiles[(*map)->player.x][(*map)->player.y-1].passable)
        {
            (*map)->tiles[(*map)->player.x][(*map)->player.y].type = '0';
            (*map)->player.y -= 1;
            (*map)->tiles[(*map)->player.x][(*map)->player.y].type = 'P';
            mlx_image_to_window(window, assets.floor, ((*map)->player.x)*56, ((*map)->player.y + 1)*56);
            mlx_image_to_window(window, assets.player, ((*map)->player.x)*56, ((*map)->player.y)*56);
            printf("w\n");
        }
    }
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        if ((*map)->tiles[(*map)->player.x-1][(*map)->player.y].passable)
        {
            (*map)->tiles[(*map)->player.x][(*map)->player.y].type = '0';
            (*map)->player.x -= 1;
            (*map)->tiles[(*map)->player.x][(*map)->player.y].type = 'P';
            mlx_image_to_window(window, assets.floor, ((*map)->player.x + 1)*56, ((*map)->player.y)*56);
            mlx_image_to_window(window, assets.player, ((*map)->player.x)*56, ((*map)->player.y)*56);
		    printf("a\n");
        }
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        if ((*map)->tiles[(*map)->player.x][(*map)->player.y+1].passable)
        {
            (*map)->tiles[(*map)->player.x][(*map)->player.y].type = '0';
            (*map)->player.y += 1;
            (*map)->tiles[(*map)->player.x][(*map)->player.y].type = 'P';
            mlx_image_to_window(window, assets.floor, ((*map)->player.x)*56, ((*map)->player.y -1)*56);
            mlx_image_to_window(window, assets.player, ((*map)->player.x)*56, ((*map)->player.y)*56);
		    printf("s\n");
        }
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        if ((*map)->tiles[(*map)->player.x+1][(*map)->player.y].passable)
        {
            (*map)->tiles[(*map)->player.x][(*map)->player.y].type = '0';
            (*map)->player.x += 1;
            (*map)->tiles[(*map)->player.x][(*map)->player.y].type = 'P';
            mlx_image_to_window(window, assets.floor, ((*map)->player.x - 1)*56, ((*map)->player.y)*56);
            mlx_image_to_window(window, assets.player, ((*map)->player.x)*56, ((*map)->player.y)*56);
		    printf("d\n");
        }
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(window);
}
