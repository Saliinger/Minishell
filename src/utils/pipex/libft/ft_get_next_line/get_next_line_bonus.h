/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:35:25 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/25 16:08:56 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h> //malloc

# include <unistd.h> //close

# include <sys/types.h> //open
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 2048
# endif

enum e_gnl_errors
{
	ERR_GNL_MALLOC = 1,
	ERR_GNL_READ = 2,
	ERR_GNL_PARSE = 3
};

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
size_t	ft_gnl_strlen(const char *s);
void	*ft_gnl_memmove(void *dest, const void *src, size_t n);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
int		ft_ind_strchr(const char *s, int c);
char	*ft_gnl_strdup(const char *s);

#endif