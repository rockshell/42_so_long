/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:24:39 by akulikov          #+#    #+#             */
/*   Updated: 2024/06/04 17:41:04 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/get_next_line.h"

void print_map(t_map *map)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
            printf("%c", map->tiles[x][y].type);
        printf("\n");
    }
    
}

int	main(int argc, char *argv[])
{
    t_map *map;

    if (argc != 2)
    {
        printf("Usage: %s <map file>\n", argv[0]);
        return 1;
    }

    if (load_map(argv[1], &map) == 0)
    {
        printf("Map loaded successfully!\n");
        print_map(map);
    }
    else
    {
        printf("Failed to load map.\n");
        return (1);
    }
    
    check_map(&map);
    printf("There are %i collectibles, %i exits and %i start positions\n", map->count_collectibles, map->count_exits, map->count_players);

    if (map->count_exits != 1)
    {
        printf("Wrong amount of exits\n");
        return(1);
    }
    if (map->count_collectibles <= 0)
    {
        printf("Wrong amount of collectibles\n");
        return(1);
    }

    if (map->count_players != 1)
    {
        printf("Wrong amount of players\n");
        return(1);
    }
    
    
    
    if (map->tiles[map->exit.x][map->exit.y].pass_check)
        printf("Exit is within the reach\n");
    else
    {
        printf("Exit is unreacheble\n");
        return(1);
    }

    if (map->wall_integrity)
        printf("Wall is in place\n");
    else
    {
        printf("Wall is broken\n");
        return (1);
    }
    
    launch_game(&map);
    // for (int i = 0; i < map->height; i++) {
        // free(map->tiles[i]);
    // }
    // free(map->tiles);
    // free(map);

    return (0);
}

