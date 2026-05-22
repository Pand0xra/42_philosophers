/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narginaa <narginaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:10:49 by narginaa          #+#    #+#             */
/*   Updated: 2026/03/20 12:26:20 by narginaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		ft_exit("malloc failed to allocate memory.\n", data);
	ft_memset(data->philos, 0, sizeof(t_philo) * data->philo_count);
	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		i++;
	}
}

void	ft_init_data(int ac, char **av, t_data *data)
{
	int	i;

	ft_memset(data, 0, sizeof(t_data));
	data->philo_count = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat_count = -1;
	if (ac == 6)
		data->must_eat_count = ft_atoi(av[5]);
	data->start_time = ft_get_time_in_ms();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		ft_exit("malloc failed to allocate memory.\n", NULL);
	i = -1;
	while (++i < data->philo_count)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->meal_mutex, NULL);
}

void	ft_check_args(int ac, char **av)
{
	int	i;

	if (ac != 6 && ac != 5)
		ft_exit("Error: wrong number of arguments\n", NULL);
	i = 0;
	while (++i < ac)
		ft_check_is_pos_num(av[i]);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_check_args(argc, argv);
	ft_init_data(argc, argv, &data);
	ft_init_philos(&data);
	ft_start_sim(&data);
	ft_clean_system(&data);
}
