/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:41 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/06 22:37:13 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;

	tmp = n * (1 - (2 * (n < 0)));
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (tmp > 9)
		ft_putnbr_fd(tmp / 10, fd);
	ft_putchar_fd(tmp % 10 + '0', fd);
}
