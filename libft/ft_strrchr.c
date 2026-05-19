/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:13:05 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/14 12:04:56 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*occ;
	unsigned char	uc;

	occ = NULL;
	uc = (unsigned char) c;
	while (*s)
	{
		if ((unsigned char)*s == uc)
			occ = (char *) s;
		s++;
	}
	if ((unsigned char) *s == uc)
		return ((char *)s);
	return (occ);
}
