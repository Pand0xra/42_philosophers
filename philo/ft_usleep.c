/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nana <nana@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:18:31 by nana              #+#    #+#             */
/*   Updated: 2026/05/16 12:18:32 by nana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long long time_in_ms)
{
	long long	start_time;

	start_time = ft_get_time_in_ms();
	while ((ft_get_time_in_ms() - start_time) < time_in_ms)
		usleep(500);
}
