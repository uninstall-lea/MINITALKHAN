/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:44:22 by lea               #+#    #+#             */
/*   Updated: 2022/07/06 21:33:53 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

void	send_char_to_bin(pid_t pid, char *str)
{
	int		i;
	int		bits;

	i = 0;
	while (str[i])
	{
		bits = 7;
		while (bits >= 0)
		{
			if (str[i] >> bits & 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					error_exit(2);
			}
			else if (str[i] >> bits & 1)
			{
				if (kill(pid, SIGUSR2))
					error_exit(2);
			}
			bits--;
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
	if (pid <= 0)
		error_exit(2);
	send_char_to_bin(pid, av[2]);	
	while (1)
		pause();
	return (1);
}
