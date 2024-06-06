/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:05:16 by arch              #+#    #+#             */
/*   Updated: 2024/06/06 15:45:37 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_assets(mlx_t *mlx, t_assets *assets) {
    assets->player = mlx_texture_to_image(mlx, mlx_load_png("assets/player.png"));
    assets->wall = mlx_texture_to_image(mlx, mlx_load_png("assets/wall.png"));
    assets->chest = mlx_texture_to_image(mlx, mlx_load_png("assets/chest.png"));
    assets->exit = mlx_texture_to_image(mlx, mlx_load_png("assets/exit.png"));
    assets->floor = mlx_texture_to_image(mlx, mlx_load_png("assets/floor.png"));
}

void    render_map(t_map **map, t_assets assets, mlx_t *mlx)
{
    int x;
    int y;
    
    y = 0;
    while (y < (*map)->height)
    {
        x = 0;
        while (x < (*map)->width)
        {
            mlx_image_to_window(mlx, assets.floor, x*56, y*56);
            if ((*map)->tiles[x][y].type == '1')
                mlx_image_to_window(mlx, assets.wall, x*56, y*56);
            if ((*map)->tiles[x][y].type == 'C')
                mlx_image_to_window(mlx, assets.chest, x*56, y*56);
            if ((*map)->tiles[x][y].type == 'E')
                mlx_image_to_window(mlx, assets.exit, x*56, y*56);
            if ((*map)->tiles[x][y].type == 'P')
                mlx_image_to_window(mlx, assets.player, x*56, y*56);
            // printf("X now is %i\n", x);
            x++;
        }
        // printf("Y now is %i\n", y);
        y++;
    }
    
}

mlx_t *init_mlx(t_map **map, t_assets *assets)
{
    mlx_set_setting(MLX_MAXIMIZED, true);
    mlx_t* mlx = mlx_init((*map)->width*56, (*map)->height*56, "So long", false);
    load_assets(mlx, assets);
    return (mlx);
}

// void my_keyhook(mlx_key_data_t keydata, void *window)
// {
// 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
// 		printf("Hello \n");
// 	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
// 		printf("World\n");
// 	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
// 		printf("!\n");
//     if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
// 		printf("!\n");
//     if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
//         mlx_close_window(window);
    
// }
    
int launch_game(t_map **map)
{
    t_assets    assets;

    mlx_t* mlx = init_mlx(map, &assets);
    render_map(map, assets, mlx);
    
  
    mlx_key_hook(mlx, &my_keyhook, map);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}