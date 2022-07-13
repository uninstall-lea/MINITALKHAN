/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:44:22 by lea               #+#    #+#             */
/*   Updated: 2022/07/14 01:39:31 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

int	g_to_go_or_not_to_go = TO_GO;

static void	handle_error(int ac, char **av)
{	
	int	i;

	i = 0;
	if (ac != 3)
		error_exit(1);
	while (ft_isdigit(av[1][i]))
		i++;
	if (av[1][i] != '\0')
		error_exit(2);
}

static void	handle_last_signal(pid_t pid)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		g_to_go_or_not_to_go = 0;
		if (kill(pid, SIGUSR1) == -1)
			error_exit(4);
		bits--;
		while (g_to_go_or_not_to_go == 0)
			pause();
	}
}

static void	send_bin(pid_t pid, char *str)
{
	int	i;
	int	bits;

	i = 0;
	while (str[i])
	{
		bits = 7;
		while (bits >= 0)
		{
			g_to_go_or_not_to_go = 0;
			if ((str[i] >> bits) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					error_exit(4);
			}	
			else if (kill(pid, SIGUSR1) == -1)
				error_exit(4);
			bits--;
			while (g_to_go_or_not_to_go == 0)
				pause();
		}
		i++;
	}
	if (str[i] == '\0')
		handle_last_signal(pid);
}

void	sighandler(int sigid)
{
	if (sigid == SIGUSR1)
		g_to_go_or_not_to_go = TO_GO;
}

int	main(int ac, char **av)
{
	pid_t				pid;

	handle_error(ac, av);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		error_exit(2);
	signal(SIGUSR1, &sighandler);
	send_bin(pid, av[2]);
	return (1);
}
