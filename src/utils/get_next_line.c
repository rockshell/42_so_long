/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akulikov <akulikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:54:24 by akulikov          #+#    #+#             */
/*   Updated: 2024/05/18 15:37:31 by akulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../include/get_next_line.h"

char	*join_and_free(char *main_buffer, char *last_read_buffer)
{
	char	*temp_buffer;

	if (main_buffer)
	{
		temp_buffer = ft_strjoin(main_buffer, last_read_buffer);
		free(main_buffer);
	}
	else
		temp_buffer = ft_strdup(last_read_buffer);
	return (temp_buffer);
}

char	*read_from_file(int fd, char *buffer)
{
	char	*temp_buffer;
	int		bytes_read;

	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(temp_buffer);
		return (NULL);
	}
	while (bytes_read > 0)
	{
		temp_buffer[bytes_read] = '\0';
		buffer = join_and_free(buffer, temp_buffer);
		if (ft_strchr(temp_buffer, '\n'))
			break ;
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	}
	free(temp_buffer);
	return (buffer);
}

char	*get_the_line_from_buffer(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_buffer(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		return (NULL);
	}
	res = malloc((ft_strlen(buffer) - i) * sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (fd == -1 && buffer)
			free(buffer);
		return (NULL);
	}
	buffer = read_from_file(fd, buffer);
	if (!buffer)
	{
		line = NULL;
		return (line);
	}
	line = get_the_line_from_buffer(buffer);
	temp_buffer = update_buffer(buffer);
	free (buffer);
	buffer = temp_buffer;
	return (line);
}
