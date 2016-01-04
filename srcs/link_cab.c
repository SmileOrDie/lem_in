/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_cab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:16:36 by shamdani          #+#    #+#             */
/*   Updated: 2016/01/04 13:14:53 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_link(t_env *e)
{
	t_cab *t;
	t_link *link;
	int nb;
	int j;

	t = e->pos_start;
	while (t)
	{
		nb = nb_link(t->name, e);
		link = e->link_t;
		t->link = (t_cab**)malloc(sizeof(t_cab*) * nb + 1);
		j = 0;
		t->check = 0;
		while (j < nb && nb > 0)
		{
			if (ft_strcmp(link->link[0], t->name) == 0)
				t->link[j++] = ft_l_cab(link->link[1], e);
			else if (ft_strcmp(link->link[1], t->name) == 0)
				t->link[j++] = ft_l_cab(link->link[0], e);
			link = link->next;
		}
		t->link[j] = NULL;
		t = t->next;
	}
}

static void		link_save2(t_env *e, t_link *s)
{
	t_link		*bg;

	bg = e->link_t;
	if (e->link_t != NULL)
	{
		while (bg->next)
			bg = bg->next;
		bg->next = s;
	}
	else
		e->link_t = s;
	s->next = NULL;
}

int 			link_save(char **tab, t_env *e)
{
	int		i;
	t_link	*s;

	i = 0;
	if (len_tab(tab) == 2)
	{
		if (ft_strcmp(tab[1], tab[0]) == 0)
			return (1);
		++e->nb;
		s = (t_link *)ft_memalloc(sizeof(t_link));
		s->link = (char **)ft_memalloc(sizeof(char *) * 3);
		s->link[2] = NULL;
		s->link[0] = ft_strdup(tab[0]);
		s->link[1] = ft_strdup(tab[1]);
		link_save2(e, s);
	}
	else
		return (-1);
	return (1);
}

static void		save_cab2(t_env *e, t_cab *s)
{
	if (e->cab_l)
	{
		e->cab_l->prev = s;
		s->next = e->cab_l;
	}
	else
		s->next = NULL;
}

int			save_cab(char *line, t_env *e)
{
	t_cab	*s;
	char	**tab;
	char	**t;

	t = NULL;
	if (!(tab = sp_split(line)))
		return (-1);
	if (len_tab(tab) == 3 && tab[0][0] != 'L')
	{
		if (!(s = (t_cab *)malloc(sizeof(t_cab))))
			return (-1);
		s->name = ft_strdup(tab[0]);
		s->pos[0] = ft_atoi(tab[1]);
		s->pos[1] = ft_atoi(tab[2]);
		s->prev = NULL;
	}
	else
		return (free_tab(&tab, &t, -1));
	save_cab2(e, s);
	e->cab_l = s;
	return (free_tab(&tab, &t, 1));
}