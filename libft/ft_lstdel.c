/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:42:24 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/14 13:42:26 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = *alst;
	while (ptr)
	{
		tmp = ptr;
		ft_lstdelone(&ptr, del);
		ptr = tmp->next;
	}
	*alst = NULL;
}
