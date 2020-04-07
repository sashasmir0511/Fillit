/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:46:36 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/14 14:46:38 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*ptr1;
	char			*ptr2;
	unsigned int	i;

	if (!s || !(res = ft_memalloc((size_t)ft_strlen((char *)s) + 1)))
		return (NULL);
	ptr1 = (char*)s;
	ptr2 = res;
	i = 0;
	while (*ptr1)
		*(ptr2++) = (*f)(i++, *(ptr1++));
	return (res);
}
