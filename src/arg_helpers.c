/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:36:49 by otait-ta          #+#    #+#             */
/*   Updated: 2023/02/18 13:05:51 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_julia(t_info *info)
{
	if (info->ac == 4)
	{
		is_less_than_tow(info->av[2]);
		is_less_than_tow(info->av[3]);
	}
	initialize_mlx(info);
	julia_init(info);
	julia_start(info);
}

void	verify_arg(t_info *info)
{
	if (info->ac >= 2)
	{
		if (ft_strcmp(info->av[1], "julia") == 0 && (info->ac == 4
				|| info->ac == 2))
			do_julia(info);
		else if (ft_strcmp(info->av[1], "mandelbrot") == 0 && info->ac == 2)
		{
			initialize_mlx(info);
			mandel_init(info);
			mandel_start(info);
		}
		else if (ft_strcmp(info->av[1], "mandelbrot") == 0 && info->ac != 2)
			print_and_exit("you can't enter a point with mandelbrot");
		else
			print_and_exit("d");
		mlx_destroy_image(info->mlx.mlx_ptr, info->img_data.img);
		mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
				info->img_data.img, 0, 0);
		mlx_loop(info->mlx.mlx_ptr);
	}
	print_and_exit("d");
}
