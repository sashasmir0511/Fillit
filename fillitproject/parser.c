/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:54:29 by ltalitha          #+#    #+#             */
/*   Updated: 2019/11/26 22:11:59 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				free_tetrino(t_tetrino *lst)
{
	t_tetrino	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

static t_tetrino	*maketetrino(char *buf)
{
	t_tetrino	*list;
	int			i;
	int			x_y;

	i = 0;
	x_y = 0;
	if (!(list = (t_tetrino *)malloc(sizeof(t_tetrino))))
		return (NULL);
	while (i < MIN_BUF)
	{
		if (buf[i] == '#')
		{
			list->x_map[x_y] = i % SIZE_LINE;
			list->y_map[x_y] = i / SIZE_LINE;
			x_y += 1;
		}
		i++;
	}
	list->x_offset = 0;
	list->y_offset = 0;
	list->next = NULL;
	return (align(list));
}

static t_tetrino	*makelist(char *buf, int size_buf)
{
	t_tetrino	*head;
	t_tetrino	*cur;
	int			i;
	char		letter;

	i = 21;
	letter = 'A';
	if ((head = maketetrino(buf)) == NULL)
		return (NULL);
	head->letter = letter++;
	cur = head;
	while (i < size_buf)
	{
		if ((cur->next = maketetrino(&buf[i])) == NULL)
		{
			free_tetrino(head);
			return (NULL);
		}
		cur = cur->next;
		cur->letter = letter++;
		i += 21;
	}
	return (head);
}

t_tetrino			*parser(char *filename)
{
	char	buf[MAX_BUF + 11];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, MAX_BUF + 10);
	close(fd);
	if (bytecount > MAX_BUF || bytecount < MIN_BUF)
		return (NULL);
	buf[bytecount] = '\0';
	if (valid(buf, bytecount))
		return (NULL);
	return (makelist(buf, bytecount));
}
