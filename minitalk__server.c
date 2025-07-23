/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk__server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:34:43 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/23 17:28:26 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_msg	g_msg;

void	msg_reset(void)
{
	ft_bzero(g_msg.buffer, BUFFER * sizeof(char));
	g_msg.buff_len = 0;
	g_msg.bit = 0;
}

void	sighandler(int sig)
{
	if (g_msg.buff_len == BUFFER - 1)
	{
		ft_printf("%s", g_msg.buffer);
		msg_reset();
	}
	if (g_msg.bit < 8)
	{
		g_msg.buffer[g_msg.buff_len] = (g_msg.buffer[g_msg.buff_len] << 1);
		if (sig == SIGUSR1)
			g_msg.buffer[g_msg.buff_len] |= 1;
		g_msg.bit++;
	}
	else
	{
		g_msg.bit = 0;
		if (g_msg.buffer[g_msg.buff_len] == '\0')
		{
			ft_printf("%s\n", g_msg.buffer);
			msg_reset();
		}
		else
			g_msg.buff_len++;
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
