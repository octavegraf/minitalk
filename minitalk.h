/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:57:12 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/23 16:51:50 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <sys/types.h>

# define BUFFER 1024
# define DELAY 100

typedef struct s_msg
{
	int		bit;
	int		buff_len;
	char	buffer[BUFFER];
}			t_msg;

#endif