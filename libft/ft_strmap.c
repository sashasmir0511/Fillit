/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:46:26 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/14 14:46:28 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*ptr1;
	char	*ptr2;

	if (!s || !(res = ft_memalloc((size_t)ft_strlen((char *)s) + 1)))
		return (NULL);
	ptr1 = (char*)s;
	ptr2 = res;
	while (*ptr1)
		*(ptr2++) = (*f)(*(ptr1++));
	return (res);
}
