/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:44:22 by lea               #+#    #+#             */
/*   Updated: 2022/07/06 02:36:55 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_char(char *given_str)
{
	
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sig;

	if (ac != 3)
		error_exit(1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		error_exit(2);
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	
	
}
