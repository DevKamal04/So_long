/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:27:23 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/18 20:48:04 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*q;
	unsigned char	*p;
	size_t			i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	q = (unsigned char *)s1;
	p = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*p != *q)
			return (*q - *p);
		p++;
		q++;
		i++;
	}
	return (0);
}
