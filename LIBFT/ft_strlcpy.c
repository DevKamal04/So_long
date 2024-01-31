/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:50:52 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/18 20:49:12 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)

{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (i + 1 < dstsize && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
	{
		dst[i] = 0;
	}
	while (src[i] != 0)
	{
		i++;
	}
	return (i);
}

// int main() {
//     char src[100] = "Hell++World!";
//     char dst[50];

//     size_t x = ft_strlcpy(dst, src, sizeof(dst));

//     printf("%s   %lu\n", dst, x);  // Outputs: Hello, World!

//     return 0;
// }
