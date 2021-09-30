/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:38:13 by algabrie          #+#    #+#             */
/*   Updated: 2021/09/29 18:29:01 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

void	*ft_calloc(size_t nmemb, size_t size);

void	ft_bzero(char *s, size_t n);

char	*ft_strlast(char *p);

void	ft_delete(char **buf);

int		ft_strlen(char *buf);
#endif