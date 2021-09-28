/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:48:09 by algabrie          #+#    #+#             */
/*   Updated: 2021/09/28 13:08:18 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
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

void	ft_organizer(char *ptr, int i)
{
	int		j;

	j = 0;
	while (ptr[i])
	{
		ptr[j] = ptr[i];
		i++;
		j++;
	}
	ft_bzero(ptr + j, (BUFFER_SIZE + 1) - j);
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
	return (i);
}
