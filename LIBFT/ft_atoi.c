/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:53:15 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/22 20:03:03 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	z;
	int	neg_counter;

	i = 0;
	z = 0;
	neg_counter = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			neg_counter++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		z = z * 10 + (str[i] - '0');
		i++;
	}
	if (neg_counter == 1)
	{
		z *= -1;		
	}
	return (z);
}

// #include <stdio.h>

// int ft_atoi(char *str);

// int main()
// {
//     char str[] = "--gekwjg;123";
//     int result = ft_atoi(str);
//     printf("The result is: %d\n", result);
//     return 0;
// }
