/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:11:18 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/18 15:46:58 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = 0;
	while (s1[size] != 0)
	{
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	str[size] = 0;
	return (str);
}
