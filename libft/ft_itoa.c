/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:28:26 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/14 13:16:00 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_nlen(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_ndup(long n, char *str, int sign, int len)
{
	int	i;

	str[len + sign] = '\0';
	if (sign)
		str[0] = '-';
	i = len + sign - 1;
	while (i >= sign)
	{
		str[i--] = (n % 10) + 48;
		n /= 10;
	}
}

static char	*ft_str_min(void)
{
	char	*str_min;
	char	*str;
	int		i;

	str_min = "-2147483648";
	str = malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	i = 0;
	while (str_min[i])
	{
		str[i] = str_min[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	long	nb;
	char	*str;

	if (n == -2147483648)
		return (ft_str_min());
	sign = n < 0;
	nb = n;
	if (sign)
		nb = -n;
	len = ft_nlen(nb);
	str = malloc(sizeof(char) * (len + sign + 1));
	if (!str)
		return (NULL);
	ft_ndup(nb, str, sign, len);
	return (str);
}
/*
int	main(void)
{
	char	*s1 = ft_itoa(INT_MIN);
	printf("%s\n", s1);
	free(s1);
	return (0);
}
*/
