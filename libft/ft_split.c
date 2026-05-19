/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <narginaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:13:32 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/28 15:30:46 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_splitdup(const char *s, const int s_len)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char) * (s_len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	ft_free_words(char **strs, int i)
{
	while (i-- > 0)
		free(strs[i]);
	free(strs);
}

static int	ft_fill_words(char **strs, char const *s, int count, char c)
{
	int			i;
	const char	*start_word;

	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		start_word = s;
		while (*s && *s != c)
			s++;
		strs[i] = ft_splitdup(start_word, s - start_word);
		if (!strs[i])
		{
			ft_free_words(strs, i);
			return (0);
		}
		i++;
	}
	strs[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**strs;

	count = ft_count_words(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	if (!ft_fill_words(strs, s, count, c))
		return (NULL);
	return (strs);
}
