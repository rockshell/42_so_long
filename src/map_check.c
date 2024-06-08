/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:21:22 by arch              #+#    #+#             */
/*   Updated: 2024/06/08 12:47:35 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    check_chests(t_map **map)
{
    int i;
    int j;
    int counter;

    i = 0;
    (*map)->chests_reachable = false;
    counter = (*map)->count_collectibles;
    while (i < (*map)->width)
    {
        j = 0;
        while (j < (*map)->height)
        {
            if ((*map)->tiles[i][j].type == 'C' && (*map)->tiles[i][j].pass_check)
                counter--;
            j++;
        }
        i++;
    }
    if (counter == 0)
        (*map)->chests_reachable = true; 
}

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

int check_map(t_map **map)
{
    count_specific_tiles(map, 'C');
    count_specific_tiles(map, 'P');
    count_specific_tiles(map, 'E');
    wall_is_valid(map);
    flood_fill(map, (*map)->player.x, (*map)->player.y);
    check_chests(map);
    if ((*map)->count_collectibles <= 0)
    {
        ft_printf("Wrong amount of collectibles\n");
        return(1);
    }
    if ((*map)->count_players != 1)
    {
        ft_printf("Wrong amount of players\n");
        return(1);
    }
    if ((*map)->count_exits != 1)
    {
        ft_printf("Wrong amount of exits\n");
        return(1);
    }
    if (!(*map)->wall_integrity)
    {
        ft_printf("Wall is broken\n");
        return (1);
    }
    if (!(*map)->tiles[(*map)->exit.x][(*map)->exit.y].pass_check)
    {
        ft_printf("Exit is unreacheble\n");
        return(1);
    }
    if (!(*map)->chests_reachable)
    {
        ft_printf("Some chests are unreacheble\n");
        return(1);
    }
    
    return(0);
}