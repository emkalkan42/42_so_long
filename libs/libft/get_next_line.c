/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:12:14 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/01 16:23:01 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_linesbuffer(int fd, char *rest, char *buffer);
static char	*fixline(char *line);

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(rest);
		free(buffer);
		rest = 0;
		buffer = 0;
		return (0);
	}
	line = fill_linesbuffer(fd, rest, buffer);
	free(buffer);
	buffer = 0;
	if (!line)
		return (0);
	rest = fixline(line);
	return (line);
}

static char	*fixline(char *line_buffer)
{
	char	*rest;
	size_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0)
		return (0);
	rest = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*rest == 0)
	{
		free(rest);
		rest = 0;
	}
	line_buffer[i + 1] = 0;
	return (rest);
}

static char	*fill_linesbuffer(int fd, char *rest, char *buffer)
{
	int		readstatus;
	char	*tmp;

	readstatus = 1;
	while (readstatus > 0)
	{
		readstatus = read(fd, buffer, BUFFER_SIZE);
		if (readstatus == -1)
			return (0);
		else if (readstatus == 0)
			break ;
		buffer[readstatus] = '\0';
		if (!rest)
		{
			rest = (char *)malloc(1);
			rest[0] = '\0';
		}
		tmp = rest;
		rest = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = 0;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (rest);
}