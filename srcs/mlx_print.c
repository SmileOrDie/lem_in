#include "lem_in.h"

void	resol(t_env *e, int a)
{
	init_env(e);
	new_bro(e);
	if (a == 3 && e->browse)
		drw_cab(e);
}

void		draw_line(t_map *w, t_point *p)
{ 
	t_drw	d;

	d.dx = abs(p->xb - p->xa);
	d.sx = p->xa < p->xb ? 1 : -1;
	d.dy = abs( p->yb - p->ya);
	d.sy = p->ya < p->yb ? 1 : -1;
	d.err = (d.dx > d.dy ? d.dx : -(d.dy)) / 2;
	while ((p->xa != p->xb || p->ya != p->yb))
	{
		put_pixel_to_img(w, p->xa, p->ya);
		d.e2 = d.err;
		if (d.e2 >-d.dx)
		{
			d.err -= d.dy;
			p->xa += d.sx;
		}
		if (d.e2 < d.dy)
		{
			d.err += d.dx;
			p->ya += d.sy;
		}
	}
}

void	draw_frame()

void	draw_lst_frame(t_mlx *mlx, t_list *lst)
{
	int x; 
	int y;
	int len;

	while (lst)
	{
		len = ft_strlen(lst->name);
		x = lst->pos[1] - (len /2);
		y = lst->pos[0] - 5;

		lst = lst->next;
	}
}

void	print_h(t_env *e)
{
	t_list		*tmp;
	int			len

	tmp = e->browse;
	draw_lst_frame(&e->drw, tmp);
	mlx_put_image_to_window(e->drw.mlx, e->drw.win, e->drw.img, 0, 0);
	while (tmp)
	{
		mlx_string_put(e->drw.mlx, e->drw.win, tmp->pos[0] - ((ft_strlen(tmp->name) / 2), tmp->pos[1], 0xFF0000, tmp->name);
		tmp = tmp->next;
	}
}

void		mlx_affiche(t_env *e, char **ac)
{
	int fd;

	fd = open(ac[2], O_RDONLY);
	if ((ft_strcmp(ac[1], "-mlx") != 0) && (-1 == (parsefile(e, fd))))
		return ;
	e->drw.mlx = mlx_init();
	e->drw.win = mlx_new_window(e->drw.mlx, e->drw.width, e->drw.height, "Lem-in");
	e->drw.img = mlx_new_image(e->drw.mlx, e->drw.width, e->drw.height);
	e->drw.data = mlx_get_data_addr(e->drw.img, &(e->drw.bpp), &(e->drw.sizeline), &(e->drw.endian));
}