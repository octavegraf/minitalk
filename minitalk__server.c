/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk__server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:34:43 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/24 14:32:52 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_msg	g_msg;

void	reset_msg(void)
{
	g_msg.bit = 0;
	g_msg.len = 0;
	ft_bzero(g_msg.buffer, BUFFER);
}

void	sighandler(int sig)
{
	if (g_msg.len == BUFFER - 1)
	{
		ft_printf("%s", g_msg.buffer);
		reset_msg();

	}
	if (g_msg.bit < 8)
	{
		g_msg.buffer[g_msg.len] = (g_msg.buffer[g_msg.len] << 1);
		if (sig == SIGUSR1)
			g_msg.buffer[g_msg.len] |= 1;
		g_msg.bit++;
		if (g_msg.bit == 8)
		{
			g_msg.bit = 0;
			if (!g_msg.buffer[g_msg.len])
			{
				ft_printf("%s\n", g_msg.buffer);
				reset_msg();
			}
			else
				g_msg.len++;
		}
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
	{
		pause();
	}
	return (0);
}
