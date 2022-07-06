/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:43 by lea               #+#    #+#             */
/*   Updated: 2022/07/06 01:10:12 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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

int	main(void)
{
	print_pid();
	print_char("01100011");
}
