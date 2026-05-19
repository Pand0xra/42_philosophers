/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:36:58 by narginaa          #+#    #+#             */
/*   Updated: 2025/12/07 12:37:00 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c, int *count)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}

int	ft_print_str(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	if (!count)
		return (-1);
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		(*count)++;
		i++;
	}
	return (0);
}

int	ft_print_pointer(unsigned long p, int *count)
{
	if (p == 0)
		return (ft_print_str("(nil)", count));
	if (ft_print_str("0x", count) == -1)
		return (-1);
	return (ft_print_unsigned(p, 16, count));
}

int	ft_print_digit(long n, bool is_uppercase, int base, int *count)
{
	char	*symbols;

	if (is_uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*count)++;
		n = -n;
	}
	if (n >= base)
		if (ft_print_digit(n / base, is_uppercase, base, count) == -1)
			return (-1);
	if (write(1, &symbols[n % base], 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}

int	ft_print_unsigned(unsigned long n, unsigned int base, int *count)
{
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n >= base)
		if (ft_print_unsigned(n / base, base, count) == -1)
			return (-1);
	if (write(1, &symbols[n % base], 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}
