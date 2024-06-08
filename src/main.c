/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:24:39 by akulikov          #+#    #+#             */
/*   Updated: 2024/06/08 18:59:05 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	if ((*map) == NULL)
		return ;
	if ((*map)->tiles != NULL)
	{
		while (i < (*map)->width)
		{
			if ((*map)->tiles[i])
				free((*map)->tiles[i]);
			i++;
		}
		free((*map)->tiles);
	}
	free(*map);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error!\nUsage: %s <map file>\n", argv[0]);
		return (1);
	}
	if (load_map(argv[1], &map) != 0)
	{
		ft_printf("Failed to load map.\n");
		return (1);
	}
	if (check_map(&map) != 0)
	{
		free_map(&map);
		return (1);
	}
	map->count_moves = 0;
	map->exit_available = false;
	launch_game(&map);
	free_map(&map);
	return (0);
}
