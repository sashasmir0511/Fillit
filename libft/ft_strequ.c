/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:58:04 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/14 14:58:06 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char	*ptr1;
	char	*ptr2;

	if (!s1 || !s2)
		return (s1 == s2 ? 1 : 0);
	if (ft_strlen((char *)s1) != ft_strlen((char*)s2))
		return (0);
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (*ptr1 && *ptr2)
	{
		if (*ptr1 != *ptr2)
			return (0);
		ptr1++;
		ptr2++;
	}
	return (1);
}
