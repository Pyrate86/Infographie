#include "mlx_tools.h"

void	draw_poly_from_pts(void *img_ptr, t_coord *pts, int h, int c)
{
	int	i;

	i = 0;
	while (i < h)
	{
		draw_line(img_ptr, pts[i], pts[i == h - 1 ? 0 : i + 1], c);
		i++;
	}
}

int		is_in_poly(t_coord p, int max, t_coord *pts, int h)
{
	t_line	a;
	t_line	b;
	int		i;
	int		inter;
	t_coord	*tmp;

	a.p1 = coord(p.x, p.y);
	a.p2 = coord(p.x + 1, max);
	i = 0;
	inter = 0;
	while (i < h)
	{
		b.p1 = pts[i];
		b.p2 = pts[i == h - 1 ? 0 : i + 1];
		tmp = intersect(a, b);
		if (tmp)
			inter++;
		i++;
	}
	if (inter % 2 == 1)
		return (1);
	return (0);
}

void	draw_fpoly_from_pts(void *img_ptr, t_coord *pts, int h, int c)
{
	int	i;
	int x;
	int y;
	t_coord min;
	t_coord max;

	i = 0;
	min = coord(pts[i].x, pts[i].y);
	max = coord(pts[i].x, pts[i].y);
	while (i < h)
	{
		min.x = pts[i].x < min.x ? pts[i].x : min.x;
		min.y = pts[i].y < min.y ? pts[i].y : min.y;
		max.x = pts[i].x > max.x ? pts[i].x : max.x;
		max.y = pts[i].y > max.y ? pts[i].y : max.y;
		i++;
	}
	x = min.x;
	while (x <= max.x)
	{
		y = min.y;
		while (y <= max.y)
		{
			if (is_in_poly(coord(x, y), max.y + 2, pts, h))
				mlx_pixel_put_img(img_ptr, x, y, c);
			y++;
		}
		x++;
	}
}

void			draw_polygone(void *img_ptr, t_circle c, int h, int color)
{
	int		i;
	t_coord	a;
	t_coord	b;

	i = 0;
	while (i < h)
	{
		a.x = c.radius * cos(2 * M_PI * i / h - (M_PI / 2)) + c.center.x;
		a.y = c.radius * sin(2 * M_PI * i / h - (M_PI / 2)) + c.center.y;
		b.x = c.radius * cos(2 * M_PI * (i + 1) / h - (M_PI / 2)) + c.center.x;
		b.y = c.radius * sin(2 * M_PI * (i + 1) / h - (M_PI / 2)) + c.center.y;
		draw_line(img_ptr, a, b, color);
		i++;
	}
}

void			draw_fpolygone(void *img_ptr, t_circle cl, int h, int c)
{
	(void)img_ptr;
	(void)cl;
	(void)h;
	(void)c;
}