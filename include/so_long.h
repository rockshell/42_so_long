/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:58:05 by akulikov          #+#    #+#             */
/*   Updated: 2024/06/07 17:49:39 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "../MLX42/include/MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_tile
{
	char		type;
	int			x;
	int			y;
	bool		passable;
	bool		pass_check;
	// bool		is_exit;
}	t_tile;

typedef struct s_map
{
	int			width;
	int			height;
	int			count_collectibles;
	int			count_exits;
	int			count_players;
	int			count_moves;
	bool		wall_integrity;
	bool		exit_available;
	t_tile		player;
	t_tile		exit;
	// t_tile		player;
	t_tile		**tiles;
}	t_map;

typedef struct s_assets {
    mlx_image_t *player;
    mlx_image_t *chest;
	mlx_image_t	*exit;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_texture_t *player_texture;
    mlx_texture_t *chest_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
} t_assets;


typedef struct s_params {
    mlx_t *window;
    t_map **map;
	t_assets assets;
} t_params;


int		load_map(const char *filename, t_map **map);
void	check_map(t_map **map);
int launch_game(t_map **map);
void my_keyhook(mlx_key_data_t keydata, void *param);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
// void    render_map(t_map **map, t_assets assets, mlx_t *mlx);


#endif