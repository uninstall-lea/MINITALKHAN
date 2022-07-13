/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:43 by lea               #+#    #+#             */
/*   Updated: 2022/07/13 22:16:08 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

static void	print_bin_to_char(char *given_bin)
{
	char	c;
	int		i;
	int		pow;
	c = 0;
	i = 0;
	pow = 128;
	while (given_bin[i])
	{	
		if (given_bin[i] != '0')
			c += pow;
		i++;
		pow /= 2;
	}
	write(1, &c, 1);
}

void	sighandler(int sigid, siginfo_t *data, void *whatev)
{
	static int	i = 0;
	static char	value[9];

	(void)whatev;
	if (sigid == SIGUSR1)
	{
		value[i] = '0';
		if (kill(data->si_pid, SIGUSR1) == -1)
			ft_printf("Bad signal in server\n");
	}
	else if (sigid == SIGUSR2)
	{
		value[i] = '1';
		if (kill(data->si_pid, SIGUSR1) == -1)
			ft_printf("Bad signal in server\n");
	}
	i++;
	if (i == 8 && !value[i])
	{
		i = 0;
		print_bin_to_char(value);
	}
}

int	main(void)
{
	struct sigaction	sig;
	
	ft_printf("Server PID : %d\n", getpid());
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &sighandler;
	while (1)
		pause();
	return (1);
}
