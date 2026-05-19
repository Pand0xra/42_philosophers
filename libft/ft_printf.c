/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:17:03 by narginaa          #+#    #+#             */
/*   Updated: 2025/11/22 17:17:08 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(int specifier, va_list ap, int *count)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(ap, int), count));
	if (specifier == 's')
		return (ft_print_str(va_arg(ap, char *), count));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_digit(va_arg(ap, int), 0, 10, count));
	if (specifier == 'u')
		return (ft_print_digit(va_arg(ap, unsigned int), 0, 10, count));
	if (specifier == 'x' || specifier == 'X')
		return (ft_print_digit(va_arg(ap, unsigned int),
				specifier == 'X', 16, count));
	if (specifier == 'p')
		return (ft_print_pointer(va_arg(ap, unsigned long), count));
	if (specifier == '%')
		return (ft_print_char('%', count));
	return (-1);
}

static int	ft_eval_format(const char *format, va_list ap, int *count)
{
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			if (ft_format(*format, ap, count) == -1)
				return (-1);
		}
		else
		{
			if (ft_print_char(*format, count) == -1)
				return (-1);
		}
		format++;
	}
	return (0);
}

int	ft_printf_color(char *color, const char *format, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	ft_putstr_fd(color, 1);
	ret = ft_eval_format(format, ap, &count);
	va_end(ap);
	if (ret == -1)
		return (-1);
	ft_putstr_fd("\033[0m", 1);
	return (count);
}
