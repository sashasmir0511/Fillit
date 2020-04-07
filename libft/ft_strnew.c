/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:41:44 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/14 14:41:46 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*res;

	if (!(res = (char *)ft_memalloc(size + 1)))
		return (0);
	i = 0;
	while (i < size)
		res[i++] = '\0';
	return (res);
}
