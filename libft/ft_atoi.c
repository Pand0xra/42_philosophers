/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <narginaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:22:06 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/28 15:29:38 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nu;
	int	sign;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nu = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nu = nu * 10 + (str[i] - 48);
		i++;
	}
	return (nu *= sign);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi("420"));
}
*/
