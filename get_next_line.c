/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:37:32 by algabrie          #+#    #+#             */
/*   Updated: 2021/09/29 18:57:02 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_lenbuf(char *buff)
{
	int		i;

	i = 0;
	if (buff)
	{
		while (buff[i])
		{
			if (buff[i] == '\n')
			{
				i++;
				break ;
			}
			i++;
		}
	}
	return (i);
}

static int	ft_strcut(char *line, char *new_line)
{
	int		i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			new_line[i] = line[i];
			i++;
		}
		ft_delete(&line);
	}
	return (i);
}

char	*ft_organizer(char *ptr)
{
	int		j;
	int		c;
	char	*save;
	int		i;

	i = ft_lenbuf(ptr);
	c = i;
	j = 0;
	while (ptr[c])
		c++;
	if (c - i == 0)
	{
		ft_delete(&ptr);
		return (0);
	}
	save = (char *)ft_calloc(sizeof(char), (c - i) + 1);
	while (ptr[i])
		save[j++] = ptr[i++];
	ft_delete(&ptr);
	return (save);
}

static char	*ft_newcat(char *line, char *buf, char *end_line)
{
	char	*new_line;
	int		new_line_cont;
	int		buf_cont;

	new_line = (char *)ft_calloc(1, ft_lenbuf(line) + ft_lenbuf(buf) + 1);
	new_line_cont = ft_strcut(line, new_line);
	buf_cont = 0;
	while (buf[buf_cont])
	{
		new_line[new_line_cont++] = buf[buf_cont];
		if (buf[buf_cont] == '\n')
		{
			*end_line = 0;
			break ;
		}
		buf_cont++;
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	char		*end_line;
	int			size_read;

	end_line = (char *)ft_calloc(sizeof(char), 2);
	*end_line = '1';
	line = NULL;
	while (*end_line)
	{
		if (!buf)
			buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		size_read = read(fd, buf, BUFFER_SIZE - ft_strlen(buf));
		if (!(*buf) && (size_read == 0 || size_read == -1))
		{
			ft_delete(&buf);
			ft_delete(&end_line);
			return (line);
		}
		line = ft_newcat(line, buf, end_line);
		buf = ft_organizer(buf);
	}
	ft_delete(&end_line);
	return (line);
}
