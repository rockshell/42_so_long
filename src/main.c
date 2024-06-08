/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:24:39 by akulikov          #+#    #+#             */
/*   Updated: 2024/06/08 12:48:19 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
    t_map *map;

    if (argc != 2)
    {
        ft_printf("Usage: %s <map file>\n", argv[0]);
        return 1;
    }
        // handle_error(ERR_INVALID_ARGUMENT, "Usage: ./so_long <map file>");

    if (load_map(argv[1], &map) == 0)
        ft_printf("Map loaded successfully!\n");
    else
    {
        ft_printf("Failed to load map.\n");
        return (1);
    }
    
    if (check_map(&map) != 0)
        return (1);
    map->count_moves = 0;
    map->exit_available = false;
    launch_game(&map);
    return (0);
}

