/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:28:30 by lbisson           #+#    #+#             */
/*   Updated: 2022/07/14 01:30:22 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

static size_t	ft_nblen(unsigned long nb, size_t base_len)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		return (1);
	while (nb != 0)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned int nb, const char *base, size_t base_len)
{
	char	*conv_value;
	size_t	nb_len;

	nb_len = ft_nblen(nb, base_len);
	conv_value = ft_calloc(sizeof(char), nb_len + 1);
	if (!conv_value)
		return (NULL);
	while (nb_len != 0)
	{
		nb_len--;
		conv_value[nb_len] = base[nb % base_len];
		nb /= base_len;
	}
	return (conv_value);
}
