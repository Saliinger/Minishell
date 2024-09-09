/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:04:59 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/25 16:10:18 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		str = ft_gnl_strdup(s2);
	else if (!s2)
		str = ft_gnl_strdup(s1);
	else
		str = ft_gnl_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

static char	*ft_parse_line(char *buffer, char *stash, int *error)
{
	int		ind_endline;
	char	*line;

	if (*error || !buffer)
		return (*error = ERR_GNL_PARSE, free(buffer), NULL);
	ind_endline = ft_ind_strchr(buffer, '\n');
	line = malloc((ind_endline + 2) * sizeof(char));
	if (!line)
		return (*error = ERR_GNL_MALLOC, free(buffer), NULL);
	line = ft_gnl_memmove(line, buffer, ind_endline + 1);
	if (!line)
		return (*error = ERR_GNL_MALLOC, free(buffer), NULL);
	line[ind_endline + 1] = '\0';
	stash = ft_gnl_memmove(stash, &buffer[ind_endline + 1], \
		(ft_gnl_strlen(buffer) - ind_endline));
	if (!stash)
		return (*error = ERR_GNL_MALLOC, free(buffer), NULL);
	stash[(ft_gnl_strlen(buffer) - ind_endline)] = '\0';
	free(buffer);
	return (line);
}

static char	*ft_read_line(int fd, char *buffer, int *ind_endline, int *error)
{
	int		did_read;
	char	*post_it;

	did_read = BUFFER_SIZE;
	while ((did_read == BUFFER_SIZE) && (*ind_endline == -1))
	{
		post_it = malloc(BUFFER_SIZE + 1);
		if (!post_it)
			return (*error = ERR_GNL_MALLOC, NULL);
		did_read = read(fd, post_it, BUFFER_SIZE);
		if (did_read == -1)
			return (free(buffer), free(post_it), *error = ERR_GNL_READ, NULL);
		if (did_read == 0)
			return (free(post_it), buffer);
		post_it[did_read] = '\0';
		buffer = ft_strjoin_free(buffer, post_it);
		if (!buffer)
			return (*error = ERR_GNL_MALLOC, NULL);
		*ind_endline = ft_ind_strchr(buffer, '\n');
		if (did_read < BUFFER_SIZE)
			return (buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	stash[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			error;
	int			ind_endline;

	error = 0;
	line = NULL;
	if (!stash[fd][0])
		line = NULL;
	else
		line = ft_gnl_strdup(stash[fd]);
	ind_endline = ft_ind_strchr(line, '\n');
	if (ind_endline == -1)
		line = ft_read_line(fd, line, &ind_endline, &error);
	if (error)
		return (stash[fd][0] = '\0', free(line), NULL);
	if (!line || ind_endline == -1)
		return (stash[fd][0] = '\0', line);
	line = ft_parse_line(line, stash[fd], &error);
	if (error)
		return (free(line), NULL);
	return (line);
}
