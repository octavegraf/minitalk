/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk__client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:25:04 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/25 15:10:36 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_str(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << (7 - bit))))
		{
			if (kill(pid, SIGUSR1))
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR2))
				return (-1);
		}
		bit++;
		usleep(DELAY);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		return (1);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		if (send_str(pid, argv[2][i]) == -1)
			return (ft_putstr("Server error.\n"), 1);
		i++;
	}
	send_str(pid, '\0');
	return (0);
}
