/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:43 by lea               #+#    #+#             */
/*   Updated: 2022/07/13 18:02:01 by lbisson          ###   ########.fr       */
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

void	handler(int sigid)
{
	static int	i = 0;
	static char	value[9];

	if (sigid == SIGUSR1)
		value[i] = '0';
	else if (sigid == SIGUSR2)
		value[i] = '1';
	i++;
	if (i >= 8)
	{
		i = 0;
		print_bin_to_char(value);
	}
}

int	main(void)
{
	ft_printf("Server PID : %d\n", getpid());
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		pause();
	return (1);
}
