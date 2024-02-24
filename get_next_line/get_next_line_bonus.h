/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:40:37 by jode-jes          #+#    #+#             */
/*   Updated: 2024/02/20 10:40:11 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// get_next_line functions

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FILES
#  define MAX_FILES 500
# endif

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *str);
char	*ft_gnl_strchr(char *buffer, int target);
char	*ft_gnl_strjoin(char *s1, char const *s2);
char	*ft_get_line(char *buffer);
char	*ft_new_line(char *buffer);
size_t	ft_gnl_strlen(const char *str);

#endif