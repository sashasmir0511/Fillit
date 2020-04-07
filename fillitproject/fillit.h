/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:49:51 by lhaired           #+#    #+#             */
/*   Updated: 2019/11/24 13:49:52 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdlib.h>

# define MAX_BUF	545
# define MIN_BUF	19
# define SIZE_LINE	5

typedef struct	s_tetrino
{
	int					x_map[4];
	int					y_map[4];
	char				letter;
	int					x_offset;
	int					y_offset;
	struct s_tetrino	*next;
}				t_tetrino;
typedef struct	s_map
{
	char				**array;
}				t_map;
void			free_tetrino(t_tetrino *lst);
t_tetrino		*align(t_tetrino *lst);
t_tetrino		*parser(char *filename);
int				valid(char *buf, int bytecount);
int				solve(t_tetrino *list);
int				round_up_sq_rt(int num);
void			print_map(t_map *map, int size);
void			free_map(t_map *map, int size);
t_map			*new_map(int size);
size_t			count_tetrino(t_tetrino *list);

#endif
