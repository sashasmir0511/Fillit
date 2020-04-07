/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:44:20 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/07 17:44:22 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char			*iter;
	unsigned int	i;

	i = 0;
	iter = dest;
	while (*iter != '\0')
		iter++;
	while (*src != '\0' && i < n)
	{
		*iter++ = *src++;
		i++;
	}
	*iter = '\0';
	return (dest);
}
