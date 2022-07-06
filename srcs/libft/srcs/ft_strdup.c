/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:11:00 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/06 22:37:30 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(src);
	new_str = ft_calloc(sizeof(char), len + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, src, len + 1);
	return (new_str);
}
