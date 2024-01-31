/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:59:59 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/18 20:43:56 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)

{
	const unsigned char	*src;
	unsigned char		uc;
	size_t				i;

	src = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*src == uc)
			return ((void *)src);
		src++;
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char str[] = "Hello,kamsorld!";
//     char *ptr = ft_memchr(str, 'm', strlen(str));
//     if (ptr != 0)
//     {
//         printf ("'m' found at position %ld.\n", ptr-str+1);
//         printf ("search character found:  %s\n", ptr);
//     }
//     else
//     {
//         printf ("search character not found\n");
//     }

//     return 0;
// }
