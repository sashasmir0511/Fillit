/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:55:41 by ltalitha          #+#    #+#             */
/*   Updated: 2019/11/24 13:55:42 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_letter_line(char *str)
{
	int i;

	i = 0;
	while (i < SIZE_LINE - 1)
	{
		if (str[i] != '.' && str[i] != '#')
			return (1);
		i++;
	}
	if (str[i] != '\n')
		return (1);
	return (0);
}

int		valid_size_tetrino_buf(char *str)
{
	int		i;

	i = 0;
	while (i < MIN_BUF)
	{
		if (valid_letter_line(&str[i]))
			return (1);
		i += SIZE_LINE;
	}
	return (0);
}

int		valid_tetrino_form(char *str)
{
	int		i;
	int		count;
	int		count_s;

	i = 0;
	count = 0;
	count_s = 0;
	while (i < MIN_BUF)
	{
		if (str[i] == '#')
		{
			count_s++;
			if (i + 1 < MIN_BUF && str[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && str[i - 1] == '#')
				count++;
			if (i + 5 < MIN_BUF && str[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && str[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count_s != 4 || (count != 6 && count != 8))
		return (1);
	return (0);
}

int		valid(char *buf, int bytecount)
{
	int		i;

	i = 0;
	while (i <= bytecount)
	{
		if (bytecount - i < MIN_BUF)
			return (1);
		if (valid_size_tetrino_buf(&buf[i]))
			return (1);
		if (valid_tetrino_form(&buf[i]))
			return (1);
		i += MIN_BUF + 1;
		if (!buf[i])
			return (0);
		if (buf[i] != '\n')
			return (1);
		i += 1;
	}
	return (0);
}
