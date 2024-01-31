/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:28:48 by kamsingh          #+#    #+#             */
/*   Updated: 2023/11/17 16:21:16 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"

char	*ft_line(char *remember)
{
	char	*line;
	int		i;
	int		with_nl;

	i = 0;
	while (remember[i] && remember[i] != '\n')
		i++;
	if (remember[i] == '\n')
		with_nl = 2;
	else
		with_nl = 1;
	line = ft_calloc(i + with_nl, 1);
	if (!line)
		return (free(remember), NULL);
	i = 0;
	while (*remember && *remember != '\n')
	{
		line[i++] = *remember++;
	}
	if (*remember && *remember == '\n')
	{
		line[i++] = '\n';
		remember++;
	}
	return (line);
}

char	*ft_free(char *remember, char *temp)
{
	temp = ft_strjoin(remember, temp);
	free(remember);
	return (temp);
}

char	*ft_reading(int fd, char *contain)
{
	char		*temp;
	int			chars_read;

	chars_read = 1;
	if (!contain)
		contain = ft_calloc(1, 1);
	if (contain == NULL)
		return (NULL);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (free(contain), NULL);
	while (chars_read)
	{
		chars_read = read(fd, temp, BUFFER_SIZE);
		if (chars_read == -1)
			return (free(temp), free(contain), NULL);
		temp[chars_read] = '\0';
		contain = ft_free(contain, temp);
		if (ft_strchr(contain, '\n'))
			break ;
	}
	free(temp);
	return (contain);
}

char	*ft_newline(char *remember)
{
	int		len;
	int		i;
	char	*remain;
	int		j;

	i = 0;
	while (remember[i] && remember[i] != '\n')
		i++;
	if (!remember[i])
		return (free(remember), NULL);
	len = ft_strlen(remember);
	remain = ft_calloc(len - i + 1, 1);
	if (remain == NULL)
		return (NULL);
	i++;
	j = 0;
	while (remember[i] != 0)
		remain[j++] = remember[i++];
	return (free(remember), remain);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remember;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(remember);
		remember = NULL;
		return (NULL);
	}
	remember = ft_reading(fd, remember);
	if (remember == NULL)
		return (NULL);
	if (remember[0] == '\0')
	{
		free(remember);
		remember = NULL;
		return (NULL);
	}
	line = ft_line(remember);
	if (line == NULL)
		return (free(remember), NULL);
	remember = ft_newline(remember);
	return (line);
}
