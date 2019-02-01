/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:54:52 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/10 11:00:39 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_print_tab(char **tab)
{
	int x;
	
	x = 0;
	while (tab[x])
	{
		ft_putendl(tab[x]);
		x++;
	}
}
int main(int ac, char **av)
{
	char **tab;

	if (ac == 2)
	{
		tab = ft_strsplit(av[1], ' ');
		ft_print_tab(tab);
	}
	return (1);
}
