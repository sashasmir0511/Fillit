/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:11:37 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/06 19:11:40 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *s1, const char *s2)
{
	char *iter;

	iter = s1;
	while (*iter != '\0')
		iter++;
	while (*s2 != '\0')
		*iter++ = *s2++;
	*iter = '\0';
	return (s1);
}
