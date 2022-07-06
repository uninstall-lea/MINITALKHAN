/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:55:08 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/06 22:38:00 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_strncmp(const char *first, const char *second, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	i = 0;
	f = (unsigned char *) first;
	s = (unsigned char *) second;
	if (n == 0)
		return (0);
	while (i < n - 1 && first[i] == second[i] && first[i] && second[i])
		i++;
	return (f[i] - s[i]);
}
