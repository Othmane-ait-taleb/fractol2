/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:33:55 by otait-ta          #+#    #+#             */
/*   Updated: 2023/02/18 14:11:34 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

struct						s_img_data
{
	void					*img;
	char					*addr;
	int						bpp;
	int						size_line;
	int						endian;
};

struct						s_mlx
{
	void					*mlx_ptr;
	void					*win_ptr;
};
struct						s_coordinates
{
	double					min_re;
	double					max_re;
	double					min_im;
	double					max_im;
};
struct						s_window
{
	double					x;
	double					y;
};

struct						s_fractal
{
	double					x;
	double					y;
};
struct						s_move
{
	double					x;
	double					y;
};

typedef struct s_info
{
	int						ac;
	char					**av;
	int						width;
	int						height;
	int						max_iterations;
	double					c_re;
	double					c_im;
	double					zoom;
	int						iter;
	int						pxl_index;
	struct s_mlx			mlx;
	struct s_img_data		img_data;
	struct s_coordinates	coordinates;
	struct s_window			window;
	struct s_fractal		fractal;
	struct s_move			move;

}							t_info;
void						verify_arg(t_info *info);
void						print_and_exit(char *d);
int							ft_strcmp(const char *s1, const char *s2);
double						ft_atof(const char *str);
void						is_less_than_tow(char *av);
void						initialize_mlx(t_info *info);
void						julia_init(t_info *info);
void						pxl_to_juliamap(t_info *info);
void						pxl_to_mandelbrotmap(t_info *info);
void						iter_to_max(t_info *info);
void						julia_start(t_info *info);
void						put_pixel_color(t_info *info);
void						my_mlx_hook(t_info *info);
void						mandel_start(t_info *info);
void						mandel_init(t_info *info);
int							mouse_hook(int button, int x, int y, t_info *info);
int							key_hook(int key, t_info *info);
int							esc_handler(int key);
int							exit_handler(t_info *info);
void						tow_axis(t_info *info);
#endif