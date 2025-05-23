/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:09:40 by flima             #+#    #+#             */
/*   Updated: 2025/03/23 12:01:37 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_current_line(int fd, char *buffer, char *line)
{
	ssize_t	nbyte;
	char	*temp;

	nbyte = 1;
	while (nbyte > 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
		{
			free(line);
			return (NULL);
		}
		else if (nbyte == 0)
			break ;
		buffer[nbyte] = '\0';
		if (line == NULL)
			line = gnl_strdup("");
		temp = line;
		line = gnl_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

static char	*set_line(char *current_line, unsigned int len)
{
	unsigned int	i;
	char			*new_line;

	if (current_line == NULL)
		return (NULL);
	new_line = (char *)malloc((len + 1) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (current_line[i] != '\n')
	{
		new_line[i] = current_line[i];
		i++;
	}
	new_line[i] = '\n';
	new_line[len] = '\0';
	return (new_line);
}

static char	*set_strings(char **line)
{
	unsigned int	i;
	char			*rest_of_line;
	char			*temp;

	i = 0;
	while ((*line)[i] != '\n' && (*line)[i] != '\0')
		i++;
	if ((*line)[i] == '\0' || (*line)[1] == '\0' || (*line)[i + 1] == '\0')
		return (NULL);
	temp = *line;
	*line = set_line(temp, i + 1);
	if (*line == NULL)
	{
		free(temp);
		return (NULL);
	}
	rest_of_line = gnl_substr(temp, (i + 1), (gnl_strlen(temp) - i));
	free(temp);
	return (rest_of_line);
}

static char	*free_static_var(char **rest_of_line)
{
	free(*rest_of_line);
	*rest_of_line = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static char		*rest_of_line[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_static_var(&rest_of_line[fd]));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (free_static_var(&rest_of_line[fd]));
	line = get_current_line(fd, buffer, rest_of_line[fd]);
	free(buffer);
	if (line == NULL)
	{
		rest_of_line[fd] = NULL;
		return (NULL);
	}
	rest_of_line[fd] = set_strings(&line);
	return (line);
}
