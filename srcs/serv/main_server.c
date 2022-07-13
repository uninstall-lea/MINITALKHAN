/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:43 by lea               #+#    #+#             */
/*   Updated: 2022/07/13 03:08:48 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

/*static void	print_bin_to_char(unsigned char *given_bin)
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
*/
/*void	handler(int sigid) //, siginfo_t *data, void *whatev)
{
	static int				i = 0;
	static unsigned char	value = 0;

//	(void)data;
//	(void)whatev;
	if (sigid == SIGUSR1)
		value <<= 1;
	else if (sigid == SIGUSR2)
		value = (value << 1) + 1;
	if (i >= 8)
	{
		i = 0;
		write(1, &value, 1);
		//print_bin_to_char(&value);
		value = 0;
	}
	i++;
}*/

int	main(void)
{
	ft_printf("Server PID : %d\n", getpid());
/*	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &handler;
	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
*/
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		pause();
	return (1);
}
