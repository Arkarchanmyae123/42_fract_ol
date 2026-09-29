/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan-my <achan-my@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 13:53:30 by username          #+#    #+#             */
/*   Updated: 2026/07/07 14:35:31 by achan-my         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_str_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

double	ft_atof(char *str)
{
	double	res;
	double	frac;
	int		sign;
	int		i;

	res = 0.0;
	frac = 1.0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0 + (str[i++] - '0');
		frac *= 10.0;
	}
	return (sign * (res / frac));
}

static void	init_fractal(struct s_fractal *f, int type, char **av)
{
	f->type = type;
	if (type == 1)
	{
		f->c_re = ft_atof(av[2]);
		f->c_im = ft_atof(av[3]);
	}
	f->zoom = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->max_iter = 100;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
}

int	main(int ac, char **av)
{
	struct s_fractal	f;

	if (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0)
		init_fractal(&f, 1, av);
	else if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
		init_fractal(&f, 2, av);
	else
	{
		put_str_fd("Error: Invalid parameters.\n", 2);
		put_str_fd("Usage options:\n", 2);
		put_str_fd("  ./fractol mandelbrot\n", 2);
		put_str_fd("  ./fractol julia <real> <imaginary>\n", 2);
		return (1);
	}
	render_julia(&f);
	mlx_hook(f.win, 2, 1L << 0, key_handler, &f);
	mlx_hook(f.win, 17, 0, close_handler, &f);
	mlx_mouse_hook(f.win, mouse_handler, &f);
	mlx_loop(f.mlx);
	return (0);
}
