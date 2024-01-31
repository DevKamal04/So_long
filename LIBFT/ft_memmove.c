/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:10:56 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/20 10:12:53 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*csrc;
	unsigned char		*cdst;

	if (dst == src || len == 0)
		return (dst);

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (csrc < cdst)
	{
		while (len > 0)
		{
			len--;
			cdst[len] = csrc[len];
		}
	}
	else if (csrc > cdst)
	{
		ft_memcpy(cdst, csrc, len);	
	}
	
	return (dst);
}
