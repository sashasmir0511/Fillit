/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:54:18 by lhaired           #+#    #+#             */
/*   Updated: 2019/11/24 13:54:20 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		round_up_sq_rt(int num)
{
	int		size;

	size = 2;
	while (size * size < num)
		size++;
	return (size);
}

void	print_map(t_map *map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map *map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

t_map	*new_map(int map_size)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if (!(map->array = (char **)ft_memalloc(sizeof(char *) * map_size)))
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		if (!(map->array[i] = ft_strnew(map_size)))
			return (NULL);
		ft_memset(map->array[i], '.', map_size);
		i++;
	}
	return (map);
}

size_t	count_tetrino(t_tetrino *list)
{
	size_t	count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}
