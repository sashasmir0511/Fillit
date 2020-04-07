/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:02:03 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/14 15:02:05 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlennbr(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

char			*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	nbr;
	char			*str;

	nbr = (unsigned int)n;
	if (n < 0)
		nbr = (unsigned int)(n * -1);
	size = (unsigned int)ft_getlennbr(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		size++;
	}
	i = size - 1;
	while (nbr >= 10)
	{
		str[i--] = (char)(nbr % 10 + 48);
		nbr /= 10;
	}
	str[i] = (char)(nbr % 10 + 48);
	str[size] = '\0';
	return (str);
}
