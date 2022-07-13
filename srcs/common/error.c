/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:46:22 by lea               #+#    #+#             */
/*   Updated: 2022/07/14 01:31:55 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minitalk.h"

void	error_exit(int error)
{
	if (error == 1)
		ft_printf("Expected : ./client [server-PID] [message]\n");
	else if (error == 2)
		ft_printf("Bad PID\n");
	else if (error == 3)
		ft_printf("Bad malloc\n");
	else if (error == 4)
		ft_printf("Bad signal in client\n");
	else if (error == 5)
		ft_printf("Bad signal in server\n");
	exit(EXIT_FAILURE);
}
