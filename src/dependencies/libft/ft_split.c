/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/10/24 14:42:23 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_next_set_occurency(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	get_word_count(char const *s, char c)
{
	size_t	i;
	size_t	is_in_word;
	size_t	count;

	i = -1;
	is_in_word = 0;
	count = 0;
	while (s[++i])
	{
		if (s[i] == c)
			is_in_word = 0;
		else if (is_in_word++ == 0)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	total_len;
	size_t	next_char_index;
	char	**tab;

	i = 0;
	total_len = get_word_count(s, c) * sizeof(char *) + sizeof(NULL);
	tab = (char **)malloc(total_len);
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			next_char_index = get_next_set_occurency(s, c);
			tab[i++] = ft_substr(s, 0, next_char_index);
			s += next_char_index;
		}
	}
	tab[i] = NULL;
	return (tab);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[] = "a	b b";
// 	char	**tab = ft_split(str, ' ');
// 	size_t	i = 0;

// 	while (tab[i] != NULL)
// 		printf("- %s\n", tab[i++]);
// 	//printf("%c", dest1[4]);
// 	return (0);
// }