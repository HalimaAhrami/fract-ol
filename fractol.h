/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:40:35 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/04/08 08:54:16 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"
# define WIDTH 1000
# define HIGHT 1000
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

typedef struct s_cmoplix{
	double	x;
	double	y;
}	t_complix;

typedef struct s_img{
	void	*imgs;
	void	*pixel;
	int		bp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_stractal{
	char	*name;
	void	*mlx_c;
	void	*mlx_w;
	t_img	img;
	double	escape_value;
	double	julia_x;
	double	julia_y;
	int		iterations;
	double	shift_x;
	double	shift_y;
	int		color;
	double	zoom;
}	t_fractal;

double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
void		init_fractol(t_fractal *f);
void		put_fractol(t_fractal *fractal);
int			ft_close(t_fractal *f);
void		ft_evant(t_fractal *f);
t_complix	z_2_c(t_complix z, t_complix c);
t_complix	z__2_c(t_complix z, t_complix c);

#endif