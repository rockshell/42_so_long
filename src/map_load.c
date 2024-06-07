/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:28:11 by akulikov          #+#    #+#             */
/*   Updated: 2024/06/07 17:14:16 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_allowed_symbols(const char *line)
{
	const char *allowed_symbols;
	size_t	i;
	
	allowed_symbols = "01CEP\n\0";
	i = 0;
	while (i < ft_strlen(line))
	{
		if (!ft_strchr(allowed_symbols, line[i]))
			return(-1);
		i++;
	}
	return(0);
}

int	check_map_initial(const char *filename)
{
	int	fd;
	size_t	row_length;
	char	*row;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return(-1);
	row = get_next_line(fd);
	row_length = ft_strlen(row);
	while (row)
	{
		if (check_allowed_symbols(row) < 0)
			break;
		row = get_next_line(fd);
		if (row && (ft_strlen(row) != row_length) && row[row_length] != '\0')
			break;
		row_length = ft_strlen(row);
	}
	close(fd);
	if (row)
		return(-1);
	return(0);
}

void	alloc_map_memory(t_map **map, const char *filename)
{
	int	fd;
	int	i;
	char	*row;

	fd = open(filename, O_RDONLY);
	row = get_next_line(fd);
	*map = (t_map *)malloc(sizeof(t_map));
	(*map)->width = (ft_strlen(row) - 1);
	(*map)->height = 0;
	while (row)
	{
		(*map)->height += 1;
		row = get_next_line(fd);
	}
	close(fd);
	free(row);
	(*map)->tiles = (t_tile **)malloc((*map)->width * sizeof(t_tile *));
	i = 0;
	while (i < (*map)->width)
	{
		(*map)->tiles[i] = (t_tile *)malloc((*map)->height * sizeof(t_tile));
		i++;
	}
}

void	parse_row(t_map **map, const char *line, int row_num)
{
	int	i;

	i = 0;
	while (i < (*map)->width)
	{
		(*map)->tiles[i][row_num].x = i;
		(*map)->tiles[i][row_num].y = row_num;
		(*map)->tiles[i][row_num].type = line[i];
		(*map)->tiles[i][row_num].passable = true;
		(*map)->tiles[i][row_num].pass_check = false;
		if (line[i] == '1')
			(*map)->tiles[i][row_num].passable = false;
		if (line[i] == 'P')
			{
				(*map)->player.x = i;
				(*map)->player.y = row_num;
			}
		if (line[i] == 'E')
			{
				(*map)->exit.x = i;
				(*map)->exit.y = row_num;
			}
		i++;
	}
}

int	load_map(const char *filename, t_map **map)
{
	int	fd;
	int	row_num;
	char	*row;

	if (check_map_initial(filename) < 0)
		return(-1);
	alloc_map_memory(map, filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return(-1);
	row = get_next_line(fd);
	row_num = 0;
	while (row)
	{
		parse_row(map, row, row_num);
		row = get_next_line(fd);
		row_num += 1;
	}
	close(fd);
	free(row);
	return (0);
}


