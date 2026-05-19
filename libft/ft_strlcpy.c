/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:09:47 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/14 12:10:04 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (dsize)
	{
		if (len_src + 1 <= dsize)
		{
			ft_memcpy(dst, src, len_src);
			dst[len_src] = '\0';
		}
		else
		{
			ft_memcpy(dst, src, dsize - 1);
			dst[dsize - 1] = '\0';
		}
	}
	return (len_src);
}
