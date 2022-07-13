/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:43 by lea               #+#    #+#             */
/*   Updated: 2022/07/13 03:47:40 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

void	handler(int sigid)
{
	static int				i = 0;
	static unsigned char	value = 0;

	value <<= 1;
	if (sigid == SIGUSR2)
		value++;
	i++;
	if (i >= 8)
	{
		i = 0;
		write(1, &value, 1);
		value = 0;
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
