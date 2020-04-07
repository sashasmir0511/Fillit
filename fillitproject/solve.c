/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:55:29 by lhaired           #+#    #+#             */
/*   Updated: 2019/11/24 13:55:30 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				overlap(t_map *map, t_tetrino *piece)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = piece->x_map[i] + piece->x_offset;
	y = piece->y_map[i] + piece->y_offset;
	while (i < 4 && map->array[y][x] == '.')
	{
		i++;
		x = piece->x_map[i] + piece->x_offset;
		y = piece->y_map[i] + piece->y_offset;
	}
	return (i != 4);
}

void			place(t_tetrino *piece, t_map *map, char letter)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i <= 3)
	{
		x = piece->x_map[i] + piece->x_offset;
		y = piece->y_map[i] + piece->y_offset;
		map->array[y][x] = letter;
		i++;
	}
}

int				in_bounds(t_tetrino *piece, int size, char axis)
{
	if (axis == 'y')
		return (piece->y_map[0] + piece->y_offset < size
		&& piece->y_map[1] + piece->y_offset < size
		&& piece->y_map[2] + piece->y_offset < size
		&& piece->y_map[3] + piece->y_offset < size);
	else
		return (piece->x_map[0] + piece->x_offset < size
		&& piece->x_map[1] + piece->x_offset < size
		&& piece->x_map[2] + piece->x_offset < size
		&& piece->x_map[3] + piece->x_offset < size);
}

static int		solve_map(t_map *map, t_tetrino *piece, int map_size)
{
	if (!piece)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;
	while (in_bounds(piece, map_size, 'y'))
	{
		while (in_bounds(piece, map_size, 'x'))
		{
			if (!overlap(map, piece))
			{
				place(piece, map, piece->letter);
				if (solve_map(map, piece->next, map_size))
					return (1);
				else
					place(piece, map, '.');
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}

int				solve(t_tetrino *list)
{
	t_map	*map;
	int		map_size;

	map_size = round_up_sq_rt(count_tetrino(list) * 4);
	if (!(map = new_map(map_size)))
		return (1);
	while (!solve_map(map, list, map_size))
	{
		free_map(map, map_size);
		map_size++;
		if (!(map = new_map(map_size)))
			return (1);
	}
	print_map(map, map_size);
	free_map(map, map_size);
	return (0);
}
