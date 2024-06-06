/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:51:48 by arch              #+#    #+#             */
/*   Updated: 2024/06/06 15:45:51 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    move_player()
void my_keyhook(mlx_key_data_t keydata, void *window, t_map **map)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		printf("Hello \n");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		printf("World\n");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		printf("!\n");
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		printf("!\n");
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(window);
    
}


