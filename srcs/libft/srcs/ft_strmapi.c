/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:18:12 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/06 22:37:56 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_str = ft_calloc(sizeof(char), len + 1);
	if (!new_str)
		return (NULL);
	while (len--)
		new_str[len] = (*f)(len, s[len]);
	return (new_str);
}
