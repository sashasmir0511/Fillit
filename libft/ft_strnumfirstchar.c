/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnumfirstchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:46:17 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/17 16:46:19 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strnumfirstchar(char *str, const char *charset)
{
	char			*ptr;
	int				index;
	unsigned int	count;
	unsigned int	tmp;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		index = 0;
		tmp = count;
		while (charset[index])
			if (charset[index++] == *ptr)
				++count;
		if (count == tmp)
			return (count);
		++ptr;
	}
	return (count);
}
