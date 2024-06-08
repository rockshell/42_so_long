/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:05:16 by arch              #+#    #+#             */
/*   Updated: 2024/06/08 11:15:13 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_assets(mlx_t *mlx, t_assets *assets) {
    assets->player_texture = mlx_load_png("assets/player.png");
    assets->wall_texture = mlx_load_png("assets/wall.png");
    assets->chest_texture = mlx_load_png("assets/chest.png");
    assets->exit_texture = mlx_load_png("assets/exit.png");
    assets->floor_texture = mlx_load_png("assets/floor.png");
    assets->player = mlx_texture_to_image(mlx, assets->player_texture);
    assets->wall = mlx_texture_to_image(mlx, assets->wall_texture);
    assets->chest = mlx_texture_to_image(mlx, assets->chest_texture);
    assets->exit = mlx_texture_to_image(mlx, assets->exit_texture);
    assets->floor = mlx_texture_to_image(mlx, assets->floor_texture);
    mlx_delete_texture(assets->player_texture);
    mlx_delete_texture(assets->wall_texture);
    mlx_delete_texture(assets->chest_texture);
    mlx_delete_texture(assets->exit_texture);
    mlx_delete_texture(assets->floor_texture);
}

static void    render_map(t_map **map, mlx_t *window, t_assets *assets)
{
    int x;
    int y;
    
    y = 0;
    while (y < (*map)->height)
    {
        x = 0;
        while (x < (*map)->width)
        {
            mlx_image_to_window(window, (*assets).floor, x*56, y*56);
            if ((*map)->tiles[x][y].type == '1')
                mlx_image_to_window(window, (*assets).wall, x*56, y*56);
            if ((*map)->tiles[x][y].type == 'C')
                mlx_image_to_window(window, (*assets).chest, x*56, y*56);
            if ((*map)->tiles[x][y].type == 'E')
                mlx_image_to_window(window, (*assets).exit, x*56, y*56);
            if ((*map)->tiles[x][y].type == 'P')
                mlx_image_to_window(window, (*assets).player, x*56, y*56);
            x++;
        }
        y++;
    }
}

mlx_t *init_mlx(t_map **map)
{
    mlx_set_setting(MLX_MAXIMIZED, true);
    mlx_t* mlx = mlx_init((*map)->width*56, (*map)->height*56, "So long", false);
    return (mlx);
}

int launch_game(t_map **map)
{
    t_assets    assets;
    t_params    params;

    mlx_t* mlx = init_mlx(map);
    load_assets(mlx, &assets);
    render_map(map, mlx, &assets);
    params.window = mlx;
    params.map = map;
    params.assets = assets;
    mlx_key_hook(mlx, my_keyhook, &params);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}