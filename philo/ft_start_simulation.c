/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nana <nana@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:11:34 by narginaa          #+#    #+#             */
/*   Updated: 2026/05/16 12:17:59 by nana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_philo_routine_helper(t_philo *philo)
{
	while (1)
	{
		if (ft_check_is_dead(philo) == 1)
			break ;
		if (ft_taking_forks(philo))
			break ;
		ft_print_status(philo, "is eating");
		pthread_mutex_lock(&philo->data->meal_mutex);
		philo->last_meal_time = ft_get_time_in_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		ft_print_status(philo, "is thinking");
		if (philo->data->philo_count % 2 != 0)
			ft_usleep(philo->data->time_to_eat / 4);
	}
}

void	*ft_philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	ft_philo_routine_helper(philo);
	return (NULL);
}

static int	ft_check_and_set_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->meal_mutex);
	if (ft_get_time_in_ms()
		- data->philos[i].last_meal_time >= data->time_to_die)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		pthread_mutex_lock(&data->dead_mutex);
		data->is_dead = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		pthread_mutex_lock(&data->write_mutex);
		printf("%lld %d died\n", ft_get_time_in_ms() - data->start_time,
			data->philos[i].id);
		pthread_mutex_unlock(&data->write_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

void	*ft_monitor(void *arg)
{
	int		i;
	int		all_ate_enough;
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		all_ate_enough = 0;
		while (i < data->philo_count)
		{
			if (ft_check_and_set_death(data, i) == 1)
				return (NULL);
			pthread_mutex_lock(&data->meal_mutex);
			if (data->must_eat_count != -1
				&& data->philos[i].meals_eaten >= data->must_eat_count)
				all_ate_enough++;
			pthread_mutex_unlock(&data->meal_mutex);
			i++;
		}
		if (ft_check_must_eat_count(all_ate_enough, data))
			return (NULL);
		ft_usleep(1);
	}
}

void	ft_start_sim(t_data *data)
{
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, &ft_philo_routine,
				&data->philos[i]) != 0)
			ft_exit("Failed to create thread\n", data);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, &ft_monitor, data) != 0)
		ft_exit("Failed to create monitor thread\n", data);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
			ft_exit("Failed to join thread\n", data);
		i++;
	}
	pthread_join(monitor_thread, NULL);
}
