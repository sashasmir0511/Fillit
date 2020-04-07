/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnumlastchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:46:02 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/17 16:46:04 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strnumlastchar(char *str, const char *charset)
{
	unsigned int	i;
	unsigned int	index;
	unsigned int	count;
	unsigned int	tmp;

	count = 0;
	i = (unsigned int)ft_strlen(str) - 1;
	while (str[i])
	{
		index = 0;
		tmp = count;
		while (charset[index])
			if (charset[index++] == str[i])
				++count;
		if (count == tmp)
			return (count);
		--i;
	}
	return (count);
}
