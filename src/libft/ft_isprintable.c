/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:03:54 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/24 20:05:57 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprintable(char *str)
{
	int a;

	a = 0;
	if (!(str[a]))
		return (1);
	while (str[a] >= 33 || str[a] == 127)
	{
		if (str[a + 1] == '\0')
			return (1);
		a++;
	}
	return (0);
}
