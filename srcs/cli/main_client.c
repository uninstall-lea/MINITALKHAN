/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:44:22 by lea               #+#    #+#             */
/*   Updated: 2022/07/13 22:16:42 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

int	g_to_go_or_not_to_go = 0;

void	send_bin(pid_t pid, char *str)
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
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_printf("Bad signal in client\n");
			}	
			else
			{	
				if (kill(pid, SIGUSR1) == -1)
					ft_printf("Bad signal in client\n");
			}
			bits--;
			while (g_to_go_or_not_to_go != TO_GO)
				pause();
		}
		i++;
	}
}

void	sighandler(int sigid, siginfo_t *data, void *whatev)
{
	(void)whatev;
	(void)data;
	if (sigid == SIGUSR1)
		g_to_go_or_not_to_go = TO_GO;
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sig;

	if (ac != 3)
		error_exit(1);
	pid = ft_atoi(av[1]);
	// verif si que chiffre avec ft_isdigit
	if (pid <= 0)
		error_exit(2);
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &sighandler;
	send_bin(pid, av[2]);
	return (1);
}
