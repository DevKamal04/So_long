/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:38:26 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/18 20:44:21 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int main(void)
// {
//     int c = 65; // ASCII value for 'A'
//     int result = ft_isascii(c);
//     if (result == 1)
//         printf("1\n");
//     else
//         printf("0\n");

//     return 0;
// }
