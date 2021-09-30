/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:48:09 by algabrie          #+#    #+#             */
/*   Updated: 2021/09/29 17:51:23 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_delete(char **buf)
{
	int		i;

	i = 0;
	if (*buf)
	{
		while ((*buf)[i])
			(*buf)[i++] = 0;
		free(*buf);
		*buf = NULL;
	}
}

void	ft_bzero(char *s, size_t n)
{
	while (n)
	{
		*(char *)s = 0;
		s++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

char	*ft_strlast(char *p)
{

	while (*p)
		p++;
	return (p);
}

int	ft_strlen(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
		i++;
	if (i > 0)
		return (BUFFER_SIZE);
	return (0);
}
