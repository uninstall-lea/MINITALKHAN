/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:52 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/06 22:36:54 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *) ptr;
	while (i < n)
	{	
		dest[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
