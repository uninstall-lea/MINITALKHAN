/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:49:39 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/14 00:19:33 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

size_t	ft_strlen(const char *start)
{
	const char	*end;

	if (!start)
		return (0);
	end = start;
	while (*end)
		end++;
	return (end - start);
}
