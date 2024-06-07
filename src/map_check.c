/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:21:22 by arch              #+#    #+#             */
/*   Updated: 2024/06/07 17:14:09 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    count_specific_tiles(t_map **map, char c)
{
    int i;
    int j;
    int counter;

    i = 0;
    counter = 0;
    while (i < (*map)->width)
    {
        j = 0;
        while (j < (*map)->height)
        {
            if ((*map)->tiles[i][j].type == c)
                counter++;
            j++;
        }
        i++;
    }
    if (c == 'C')
        (*map)->count_collectibles = counter;
    if (c == 'P')
        (*map)->count_players = counter;
    if (c == 'E')
        (*map)->count_exits = counter;
}

void flood_fill(t_map **map, int x, int y)
{
    if (x < 0 || x >= (*map)->width || y < 0 || y >= (*map)->height)
        return;
    if(!(*map)->tiles[x][y].passable || (*map)->tiles[x][y].pass_check)
        return;
   (*map)->tiles[x][y].pass_check = true;
   flood_fill(map, x + 1, y);
   flood_fill(map, x - 1, y);
   flood_fill(map, x, y + 1);
   flood_fill(map, x, y - 1);
   return;
}

void    wall_is_valid(t_map **map)
{
    int i;

    i = 0;
    (*map)->wall_integrity = false;
    while (i < (*map)->width)
    {
        if ((*map)->tiles[i][0].type != '1' || (*map)->tiles[i][(*map)->height-1].type != '1')
            return;
        i++;
    }
    i = 0;
    while (i < (*map)->height)
    {
        if((*map)->tiles[0][i].type != '1' || (*map)->tiles[(*map)->width-1][i].type != '1')
            return;
        i++;
    }
    (*map)->wall_integrity = true;
}

void check_map(t_map **map)
{
    count_specific_tiles(map, 'C');
    count_specific_tiles(map, 'P');
    count_specific_tiles(map, 'E');
    flood_fill(map, (*map)->player.x, (*map)->player.y);
    wall_is_valid(map);
}