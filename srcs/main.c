/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:16:36 by shamdani          #+#    #+#             */
/*   Updated: 2016/01/04 18:04:22 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			creat_s_e(t_env *e, char *line)
{
	char		**tab;
	int			i;
	char		**t;

	t = NULL;
	i = 0;
	if (!(tab = sp_split(line)))
		return ;
	if (len_tab(tab) == 3 && e->start == 1)
	{
		e->pos_start = (t_cab *)malloc(sizeof(t_cab));
		e->pos_start->name = ft_strdup(tab[0]);
		e->pos_start->pos[0] = ft_atoi(tab[1]);
		e->pos_start->pos[1] = ft_atoi(tab[2]);
		e->pos_start->next = NULL;
	}
	else if (len_tab(tab) == 3 && e->end == 1)
	{
		e->pos_end = (t_cab *)malloc(sizeof(t_cab));
		e->pos_end->name = ft_strdup(tab[0]);
		e->pos_end->pos[0] = ft_atoi(tab[1]);
		e->pos_end->pos[1] = ft_atoi(tab[2]);
		e->pos_end->next = NULL;
	}
	free_tab(&tab, &t, 0);
}

void			init_env(t_env *e)
{
	t_cab		*end;

	if (!e->pos_start || !e->pos_end || e->worms == 0)
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
	if (e->cab_l)
	{
		e->cab_l->prev = e->pos_start;
		e->pos_start->next = e->cab_l;
	}
	e->cab_l = e->pos_start;
	end = e->cab_l;
	while (end->next)
		end = end->next;
	e->browse = NULL;
	end->next = e->pos_end;
	e->pos_start->check = 1;
	e->pos_c = 0;
	check_link(e);
}

static void		print_browse(t_list *bro, int i, int max)
{
	t_list		*t;
	int			e;

	t = bro;
	e = 0;
	while (i > 0 && t)
	{
		if (t->n < (unsigned int)max)
		{
			ft_putchar('L');
			ft_putnbr(++t->n);
			ft_putchar('-');
			ft_putstr(t->browse->name);
			ft_putchar(' ');
			e = 1;
		}
		t = t->prev;
		--i;
	}
	if (e)
		write(1, "\n", 1);
}

static void		ft_init(t_env *e)
{
	e->start = 0;
	e->end = 0;
	e->nb = 1;
	e->pos_start = NULL;
	e->pos_end = NULL;
	e->cab_l = NULL;
}

int				main(int a, char **ac)
{
	t_env		e;
	int			i;

	i = 1;
	ft_init(&e);
	if (a > 1 || ac[1] || (-1 == (parsefile(&e))))
	{
		write(2, "ERROR\n", 6);
		return (0);
	}
	init_env(&e);
	new_bro(&e);
	if (e.browse)
		while ((unsigned int)i <= e.worms * e.start)
		{
			print_browse(e.browse, i, e.worms);
			if (e.browse->next)
				e.browse = e.browse->next;
			i++;
		}
	else
		write(2, "ERROR\n", 6);
	return (0);
}
