/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nana <nana@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:31:45 by narginaa          #+#    #+#             */
/*   Updated: 2026/05/16 12:08:42 by nana             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				is_dead;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	meal_mutex;
	t_philo			*philos;
}					t_data;

/********************************** utils.c ***********************************/
long long			ft_get_time_in_ms(void);
void				ft_print_status(t_philo *philo, char *status);
void				ft_check_is_pos_num(char *num);
int					ft_check_is_dead(t_philo *philo);
int					ft_check_must_eat_count(int all_ate_enough, t_data *data);

/********************************** exit.c ************************************/
void				ft_exit(char *mess, t_data *data);
void				ft_clean_system(t_data *data);

/*************************** ft_start_simulation.c ****************************/
void				ft_start_sim(t_data *data);

/**************************** ft_taking_forks.c *******************************/
int					ft_taking_forks(t_philo *philo);

/******************************** ft_usleep.c *********************************/
void				ft_usleep(long long time_in_ms);

#endif
