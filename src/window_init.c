/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:05:16 by arch              #+#    #+#             */
/*   Updated: 2024/06/04 12:58:05 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_assets(mlx_t *mlx, t_assets *assets) {
    assets->player = mlx_texture_to_image(mlx, mlx_load_png("assets/player.png"));
    assets->wall = mlx_texture_to_image(mlx, mlx_load_png("assets/wall.png"));
    assets->chest = mlx_texture_to_image(mlx, mlx_load_png("assets/chest.png"));
    assets->exit = mlx_texture_to_image(mlx, mlx_load_png("assets/exit.png"));
    assets->floor = mlx_texture_to_image(mlx, mlx_load_png("assets/floor.png"));
}

mlx_t *init_mlx(t_map **map, t_assets *assets)
{
    mlx_set_setting(MLX_MAXIMIZED, true);
    mlx_t* mlx = mlx_init((*map)->width*100, (*map)->height*100, "So long", false);
    load_assets(mlx, assets);
    return (mlx);
}

int launch_game(t_map **map)
{
    t_assets    assets;

    mlx_t* mlx = init_mlx(map, &assets);
    mlx_image_to_window(mlx, assets.player, 100, 100);
    mlx_image_to_window(mlx, assets.chest, 200, 100);
    mlx_image_to_window(mlx, assets.floor, 100, 200);
    mlx_image_to_window(mlx, assets.wall, 0, 0);
    mlx_image_to_window(mlx, assets.exit, 300, 100);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}