/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:54:02 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/18 20:48:59 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
	{
		i++;
	}
	while (src[j] != 0)
	{
		j++;
	}
	if (dstsize < i)
	{
		return (j + dstsize);
	}
	return (i + j);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)

{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	i = 0;
	j = ft_count(dest, src, dstsize);
	while (dest[len] != 0)
	{
		len++;
	}
	while (src[i] != 0 && i + len + 1 < dstsize)
	{
		dest[len + i] = src[i];
		i++;
	}
	if (len + 1 < dstsize)
	{
		dest[len + i] = 0;
	}
	return (j);
}
