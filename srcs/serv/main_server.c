/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:43 by lea               #+#    #+#             */
/*   Updated: 2022/07/06 19:20:15 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

static void	print_pid(void)
{
	pid_t	pid;
	char	*str_pid;

	pid = getpid();
	str_pid = ft_itoa(pid);
	if (!str_pid)
		error_exit(2);
	write(1, str_pid, ft_strlen(str_pid));
	write(1, "\n", 1);
	free(str_pid);
}

static void	print_char(char *given_char)
{
	int		i;
	int		pow;
	char	c;
	
	i = 0;
	c = 0;
	pow = 128;
	while (given_char[i])
	{	
		if (given_char[i] != '0')
			c += pow;
		i++;
		pow /= 2;
	}
	write(1, &c, 1);
}

void	handler(int sigid, siginfo_t *data, void *whatev)
{
	static int	i = 0;
	static char	value = 0;
	
	(void)data;
	(void)whatev;
	i ++;
	if (sigid == SIGUSR1)
		value <<= 1;
	else if (sigid == SIGUSR2)
		value = (value << 1) + 1;
	if (i >= 8)
	{
		i = 0;
		print_char(&value);
		value = 0;
	}
	
}

int	main(void)
{
	struct sigaction	sig;
	
	print_pid();
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sig.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
}
