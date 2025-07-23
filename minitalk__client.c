/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk__client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:25:04 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/23 17:28:47 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_str(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> (7 - bit)) & 1)
		{	
			if (kill(pid, SIGUSR1))
				return (-1);
		}
		else
			if (kill(pid, SIGUSR2))
				return (-1);
		bit++;
		usleep(DELAY);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 2)
		return (1);
	i = 0;
	pid = atoi(argv[1]);
	while (argv[2][i++])
	{
		if (send_str(pid, argv[1][i]) == -1)
			return (1);
		usleep(DELAY);
	}
	return (0);
}
