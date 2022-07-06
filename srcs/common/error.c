/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:46:22 by lea               #+#    #+#             */
/*   Updated: 2022/07/06 19:21:15 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../incs/minitalk.h"

void	error_exit(int error)
{
    if (error == 1)
		write(2, "Expected : ./client [server-PID] [server message]\n", 51);
	else if (error == 2)
		write(1, "Bad PID\n", 9);
	else if (error == 3)
		write(2, "Bad malloc\n", 12);
	exit(EXIT_FAILURE);
}