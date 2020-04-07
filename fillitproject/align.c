/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:47:37 by lhaired           #+#    #+#             */
/*   Updated: 2019/11/24 13:47:41 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	align_x(t_tetrino *lst)
{
	int i;

	i = 0;
	while (i < 4)
	{
		lst->x_map[i] -= 1;
		i++;
	}
}

static void		align_y(t_tetrino *lst)
{
	int i;

	i = 0;
	while (i < 4)
	{
		lst->y_map[i] -= 1;
		i++;
	}
}

t_tetrino		*align(t_tetrino *lst)
{
	while (lst->x_map[0] != 0
		&& lst->x_map[1] != 0
		&& lst->x_map[2] != 0
		&& lst->x_map[3] != 0)
		align_x(lst);
	while (lst->y_map[0] != 0
		&& lst->y_map[1] != 0
		&& lst->y_map[2] != 0
		&& lst->y_map[3] != 0)
		align_y(lst);
	return (lst);
}
