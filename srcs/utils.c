/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:31:51 by fcatteau          #+#    #+#             */
/*   Updated: 2023/09/20 17:12:48 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] != '\0' && (str[i] == 32
			|| str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		return (-1);
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit (str[i]) == 0)
			return (-1);
		result = result * 10 + str[i] - '0';
		i ++;
	}
	return (result * neg);
}

void	join_threads(t_all *all_data)
{
	int	i;

	i = 0;
	while (i < all_data->global.number_of_philosophers)
	{
		pthread_join(all_data->global.threads[i], NULL);
		i++;
	}
	free(all_data->global.threads);
}

long	diffe_time(int actual_time, int previous_time)
{
	return (actual_time - previous_time);
}
