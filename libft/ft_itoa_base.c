/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:38:26 by lea               #+#    #+#             */
/*   Updated: 2022/07/05 21:39:30 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_length(int nb, char *base)
{
	int	i;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base_len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long int nb, char *base)
{
	char	*new_str;
	int		base_len;
	int		nb_len;

	nb_len = number_length(nb, base);
	base_len = ft_strlen(base);
	if (nb < 0)
		nb_len += 1;
	new_str = malloc(sizeof(char) * (nb_len + 1));
	if (new_str == NULL)
		return (NULL);
	if (nb < 0)
	{
		new_str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		new_str[0] = base[0];
	new_str[nb_len] = '\0';
	while (nb != 0)
	{
		new_str[--nb_len] = base[nb % base_len];
		nb /= base_len;
	}
	return (new_str);
}
