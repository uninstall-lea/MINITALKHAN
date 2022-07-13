/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:44:22 by lea               #+#    #+#             */
/*   Updated: 2022/07/13 03:36:19 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

static void	send_bin(pid_t pid, char *str)
{
	int		i;
	int		bits;

	i = 0;
	while (str[i])
	{
		bits = 7;
		while (bits >= 0)
		{
			if ((str[i] >> bits) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bits--;
			usleep(10);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		error_exit(1);
	pid = ft_atoi(av[1]);
	// verif si que chiffre avec ft_isdigit
	if (pid <= 0)
		error_exit(2);
	send_bin(pid, av[2]);
	return (1);
}
