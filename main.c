/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 09:28:31 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/21 14:38:10 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data	data;
	if (ac == 2)
	{
		ft_putendl("test");
		init(av[1], &data);
		ft_putendl("test1");
		create_image(&data);		
		ft_putendl("test2");
		info(data);
		ft_putendl("test3");
		mlx_hook(data.win_ptr, KEY_PRESS, 1L<<0, key_press, &data);
		mlx_key_hook(data.win_ptr, deal_key, &data);
		ft_putendl("test4");
		mlx_loop(data.mlx_ptr);
	}
	return (1);
}
