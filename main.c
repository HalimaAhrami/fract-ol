/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:40:08 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/04/12 21:11:43 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_fractal *f)
{
	mlx_destroy_image(f->mlx_c, f->img.imgs);
	mlx_destroy_window(f->mlx_c, f->mlx_w);
	mlx_destroy_display(f->mlx_c);
	free(f->mlx_c);
	exit (0);
}

t_complix	z_2_c(t_complix z, t_complix c)
{
	t_complix	r;

	r.x = z.x * z.x - z.y * z.y + c.x;
	r.y = 2 * z.x * z.y + c.y;
	return (r);
}

static int	ft_is_double(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'
				&& ft_isdigit(str[i - 1]) && ft_isdigit(str[i + 1])))
			i++;
		else
			return (1);
	}
	return (0);
}

static double	ft_atod(char *nbr)
{
	double	r;
	double	r1;
	int		s;
	int		i;
	int		p;

	i = 0;
	s = 1;
	r = 0;
	r1 = 0;
	p = 1;
	while (nbr[i] && (nbr[i] == '-' || nbr[i] == '+'))
		if (nbr[i++] == '-')
			s *= -1;
	while (nbr[i] && nbr[i] >= '0' && nbr[i] <= '9')
		r = r * 10 + nbr[i++] - '0';
	if (nbr[i] && nbr[i++] == '.')
	{
		while (nbr[i] && nbr[i] >= '0' && nbr[i] <= '9')
		{
			r1 = r1 * 10 + nbr[i++] - '0';
			p *= 10;
		}
	}
	return ((r1 = r1 / p, s * (r + r1)));
}

int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac == 2 && ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1])) == 0)
	{	
		f.name = "Mandelbrot";
		init_fractol(&f);
		put_fractol(&f);
		ft_evant(&f);
		mlx_loop(f.mlx_c);
	}
	else if ((ac == 4 && ft_strncmp(av[1], "Julia", ft_strlen(av[1])) == 0
			&& ft_is_double(av[2]) == 0 && ft_is_double(av[3]) == 0))
	{
		f.name = "Julia";
		f.julia_x = ft_atod(av[2]);
		f.julia_y = ft_atod(av[3]);
		init_fractol(&f);
		put_fractol(&f);
		ft_evant(&f);
		mlx_loop(f.mlx_c);
	}
	else
		exit((ft_putstr_fd("./fractol Mandelbrot\n./fractol Julia x.set y.set\n",
					2), 1));
	return (0);
}
