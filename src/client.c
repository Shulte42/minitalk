/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:47:32 by bruda-si          #+#    #+#             */
/*   Updated: 2024/06/18 11:06:34 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!(str[i] > '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

static void	send_len(pid_t pid, char *str)
{
	int	length;
	int	bit;

	bit = 31;
	length = 0;
	while (*(str++))
		length++;
	while (bit >= 0)
	{
		if ((length >> bit & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(400);
	}
}

static void	send_char(pid_t pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if ((str[i] >> j & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(400);
			j--;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		i++;
		usleep(400);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	if (pid < 1)
		return (1);
	send_len(pid, av[2]);
	send_char(pid, av[2]);
	return (0);
}
