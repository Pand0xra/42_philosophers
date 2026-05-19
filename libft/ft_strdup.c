/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:23:46 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/14 12:12:19 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		s_size;

	s_size = ft_strlen(s) + 1;
	copy = malloc(sizeof(char) * s_size);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, s_size);
	return (copy);
}
