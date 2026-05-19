/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <narginaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:11:09 by narginaa          #+#    #+#             */
/*   Updated: 2026/03/20 12:40:11 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	if (ft_check_is_dead(philo) == 0)
		printf("%lld %d %s\n", ft_get_time_in_ms() - philo->data->start_time,
			philo->id, status);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

int	ft_check_must_eat_count(int all_ate_enough, t_data *data)
{
	if (data->must_eat_count != -1 && all_ate_enough == data->philo_count)
	{
		pthread_mutex_lock(&data->dead_mutex);
		data->is_dead = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		return (1);
	}
	return (0);
}

int	ft_check_is_dead(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->data->dead_mutex);
	status = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (status);
}

void	ft_check_is_pos_num(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		ft_exit("Error: the argument is negative.\nExpected: postive value!\n",
			NULL);
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			ft_exit("Error: wrong arguments.\nExpected: Only digits\n", NULL);
		i++;
	}
}

long long	ft_get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
