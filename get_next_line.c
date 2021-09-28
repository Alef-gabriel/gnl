/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:37:32 by algabrie          #+#    #+#             */
/*   Updated: 2021/09/28 13:20:06 by algabrie         ###   ########.fr       */
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
		free(line);
	}
	return (i);
}

static char	*ft_newcat(char *line, char *buf, char *end_line)
{
	char	*new_line;
	int		end_line_bool;
	int		new_line_cont;
	int		buf_cont;

	new_line = (char *)ft_calloc(1, ft_lenbuf(line) + ft_lenbuf(buf) + 1);
	new_line_cont = ft_strcut(line, new_line);
	end_line_bool = 0;
	buf_cont = 0;
	while (buf[buf_cont])
	{
		new_line[new_line_cont++] = buf[buf_cont];
		if (buf[buf_cont] == '\n')
		{
			*end_line = 0;
			ft_organizer(buf, buf_cont + 1);
			end_line_bool = 1;
			break ;
		}
		buf_cont++;
	}
	if (!end_line_bool)
		ft_bzero(buf, buf_cont);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	char		*end_line;
	int			size_read;

	end_line = (char *)malloc(sizeof(char));
	if (!(buf))
		buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	*end_line = '1';
	line = 0;
	while (*end_line)
	{
		size_read = read(fd, ft_strlast(buf), BUFFER_SIZE - ft_strlen(buf));
		if (*buf == 0 && (size_read == 0 || size_read == -1))
		{
			free(end_line);
			return (line);
		}
		line = ft_newcat(line, buf, end_line);
	}
	free(end_line);
	return (line);
}
