/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:55:39 by kamsingh          #+#    #+#             */
/*   Updated: 2023/10/18 19:17:01 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char const *s, char c )
{
	int	count;
	int	word;

	word = 0;
	count = 0;
	while (s && *s != 0)
	{
		if (*s != c && word == 0)
		{
			word = 1;
			count ++;
		}
		else if (*s == c)
		{
			word = 0;
		}
		s++;
	}
	return (count);
}

static void	*freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i++]);
	}
	free(str);
	return (NULL);
}

void	skip(const char **s, unsigned int i, char c)
{
	(*s) = (*s) + i;
	while (**s != 0 && **s == c)
		(*s)++;
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	int				a;
	int				num;

	num = count_words(s, c);
	a = 0;
	str = malloc(sizeof(char *) * (num + 1));
	if (str == NULL)
		return (NULL);
	while (*s != 0 && *s == c)
		s++;
	while (a < num && num != 0)
	{
		i = 0;
		while (s[i] != 0 && s[i] != c)
			i++;
		str[a] = ft_substr(s, 0, i);
		if (str[a++] == NULL)
			return (freeall(str));
		skip(&s, i, c);
	}
	str[num] = 0;
	return (str);
}

// int main() {
//     char str[] = "Hello World! This is a test.";
//     char delimiter = ' ';
//     char** words = ft_split(str, delimiter);

//     if (words != NULL) {
//         for (int i = 0; words[i] != NULL; i++) {
//             printf("Word %d: %s\n", i + 1, words[i]);
//         }
//     }

//     return 0;
// }