/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:44:38 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/06 22:38:05 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strnstr(const char *big, const char *smol, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (smol[j] == '\0')
		return ((char *)big);
	while (i + j < len && big[i])
	{
		while (i + j < len && big[i + j] == smol[j] && big[i + j] && smol[j])
			j++;
		if (!smol[j])
			return ((char *)big + i);
		j = 0;
		i++;
	}	
	return (NULL);
}
