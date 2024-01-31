/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:38:25 by kamsingh          #+#    #+#             */
/*   Updated: 2023/11/03 14:53:51 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// static int	get_num_digits(int n)
// {
// 	int	numdigits;

// 	numdigits = 1;
// 	while (n / 10 != 0)
// 	{
// 		n /= 10;
// 		numdigits++;
// 	}
// 	return (numdigits);
// }

// char	*ft_itoa(int num)
// {
// 	long	n;
// 	int		sign;
// 	int		numdigits;
// 	char	*str;

// 	n = num;
// 	sign = 1;
// 	if (n < 0)
// 	{
// 		sign = -1;
// 		n = -n;
// 	}
// 	numdigits = get_num_digits(n) + (sign == -1);
// 	str = (char *)malloc((numdigits + 1) * sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	str[numdigits] = '\0';
// 	while (numdigits > 0)
// 	{
// 		str[--numdigits] = '0' + (n % 10);
// 		n /= 10;
// 	}
// 	if (sign == -1)
// 		str[0] = '-';
// 	return (str);
// }


#include "libft.h"
#include <unistd.h>

int ft_numlen(long long n)
{
    int len = 0;
    if (n == 0)
        return 1;
    if (n < 0)
    {
        len++;
        n = -n;
    }
    while (n)
    {
        n /= 10;
        len++;
    }
    return len;
}

char *ft_itoa(int n)
{
    char *dest;
    int i;
    int len;
    long long temp;
    long long num;

    if (n == -2147483648)
        num = -2147483648;
    else
        num = n;

    len = ft_numlen(num);
    dest = malloc((len + 1) * sizeof(char));
    if (dest == NULL)
        return NULL;

    i = len - 1;
    temp = num;

    if (num < 0)
        num = -num;

    while (i >= 0)
    {
        dest[i--] = (num % 10) + '0';
        num /= 10;
    }

    if (temp < 0 && dest[0] == '0')
        dest[0] = '-';

    dest[len] = '\0';

    return dest;
}