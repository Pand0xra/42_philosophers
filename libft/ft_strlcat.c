/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:10:29 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/14 12:11:42 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= dsize)
		return (dsize + src_len);
	if (src_len + 1 > dsize - dst_len)
	{
		ft_memcpy(dst + dst_len, src, dsize - dst_len - 1);
		dst[dsize - 1] = '\0';
	}
	else
		ft_memcpy(dst + dst_len, src, src_len + 1);
	return (dst_len + src_len);
}
