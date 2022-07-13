/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:46:22 by lea               #+#    #+#             */
/*   Updated: 2022/07/13 04:01:29 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../incs/minitalk.h"

void	error_exit(int error)
{
    if (error == 1)
		ft_printf("Expected : ./client [server-PID] [message]\n");
	else if (error == 2)
		ft_printf("Bad PID\n");
	else if (error == 3)
		ft_printf("Bad malloc\n");
	exit(EXIT_FAILURE);
}