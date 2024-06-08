/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:29:45 by arch              #+#    #+#             */
/*   Updated: 2024/06/08 18:50:40 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	first_batch(t_map **map)
{
	if ((*map)->count_collectibles <= 0)
	{
		ft_printf("Wrong amount of collectibles\n");
		return (1);
	}
	if ((*map)->count_players != 1)
	{
		ft_printf("Wrong amount of players\n");
		return (1);
	}
	if ((*map)->count_exits != 1)
	{
		ft_printf("Wrong amount of exits\n");
		return (1);
	}
	return (0);
}

int	second_batch(t_map **map)
{
	if (!(*map)->wall_integrity)
	{
		ft_printf("Wall is broken\n");
		return (1);
	}
	if (!(*map)->tiles[(*map)->exit.x][(*map)->exit.y].pass_check)
	{
		ft_printf("Exit is unreacheble\n");
		return (1);
	}
	if (!(*map)->chests_reachable)
	{
		ft_printf("Some chests are unreacheble\n");
		return (1);
	}
	return (0);
}

int	run_checks(t_map **map)
{
	if (first_batch(map) != 0 || second_batch(map) != 0)
		return (-1);
	return (0);
}
