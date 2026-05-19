/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:56:38 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/14 13:14:48 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_trimdup(char const *src, int start, int len)
{
	int		i;
	char	*array;

	if (len <= 0 || start >= (int)ft_strlen(src))
		return (ft_strdup(""));
	array = malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i] = src[start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	while (s1[end] && ft_in_set(s1[end], set))
		end--;
	return (ft_trimdup(s1, start, end - start + 1));
}
/*
int	main(void)
{
	char	*s1 = ft_strtrim("ababaaaMy name is P4bbaaabbad", "ab");
	printf("%s\n", s1);
	return (0);
}
*/
