/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:20:07 by bruda-si          #+#    #+#             */
/*   Updated: 2024/06/18 10:32:37 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"	

static t_global	g_global;

void	ft_putnbr(int pid)
{
	char	c;

	if (pid >= 10)
		ft_putnbr(pid / 10);
	c = (pid % 10) + '0';
	write(1, &c, 1);
}

static void	ft_putstr(void)
{
	if (!g_global.str)
		return ;
	while (*(g_global.str))
		write (1, g_global.str++, 1);
}

static	void	ft_end_program(int *interactor)
{
	char	*tmp;

	tmp = g_global.str;
	ft_putstr();
	free(tmp);
	g_global.str = NULL;
	*interactor = 0;
	g_global.character = 0;
	g_global.bits_length = 0;
	g_global.length = 0;
}

static void	ft_handle_signals(int signal)
{
	static int	interactor;

	if (g_global.bits_length++ < 32)
		g_global.length = (g_global.length << 1) + (signal >> 1 & 1);
	else
	{
		if (g_global.bits_length == 33)
		{
			g_global.str = (char *)malloc((g_global.length + 1) * sizeof(char));
			if (!g_global.str)
				exit(1);
			g_global.str[g_global.length] = 0;
		}
		g_global.bit_char++;
		g_global.character = (g_global.character << 1) + (signal >> 1 & 1);
		if (g_global.bit_char == 8)
		{
			g_global.str[interactor++] = g_global.character;
			if (!g_global.character)
				ft_end_program(&interactor);
			g_global.character = 0;
			g_global.bit_char = 0;
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = ft_handle_signals;
	sa.sa_flags = 0;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		write(1, "closing server...\n", 18);
		exit(0);
	}
	while (1)
	{
		usleep(9999);
	}
}
