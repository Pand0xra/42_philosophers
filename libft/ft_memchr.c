/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:29:32 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/16 17:21:03 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	x;

	i = 0;
	x = (unsigned char) c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == x)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	int nu = 420;
	int	*nb = &nu;

	unsigned int x = 1;
    if (*(unsigned char *)&x == 1)
        printf("Little endian\n");
    else
        printf("Big endian\n");
	unsigned char *res = (unsigned char *) ft_memchr(nb, 0xA4, 4);
	printf("%x\n", *res);
}
*/
