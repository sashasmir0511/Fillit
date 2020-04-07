/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:56:11 by lhaired           #+#    #+#             */
/*   Updated: 2019/10/09 13:50:21 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dup(void const *content, size_t content_size)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	void			*new;
	size_t			i;

	i = 0;
	if (!(new = ft_memalloc(content_size)))
		return (NULL);
	ptr = (unsigned char*)content;
	ptr2 = (unsigned char*)new;
	while (*ptr && i < content_size)
	{
		*(ptr2++) = *(ptr++);
		i++;
	}
	return (new);
}
