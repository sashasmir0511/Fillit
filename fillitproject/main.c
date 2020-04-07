/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:53:38 by lhaired           #+#    #+#             */
/*   Updated: 2019/11/24 13:54:10 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetrino	*list;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if ((list = parser(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (solve(list))
	{
		ft_putstr("error\n");
		return (1);
	}
	free_tetrino(list);
	return (0);
}
