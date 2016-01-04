/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:16:36 by shamdani          #+#    #+#             */
/*   Updated: 2016/01/04 17:34:03 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				nb_link(char *name, t_env *e)
{
	int			i;
	t_link		*list_e;

	i = 0;
	list_e = e->link_t;
	while (list_e)
	{
		if (ft_strcmp(list_e->link[1], name) == 0
			|| ft_strcmp(list_e->link[0], name) == 0)
			i++;
		list_e = list_e->next;
	}
	return (i);
}

t_cab			*ft_l_cab(char *name, t_env *e)
{
	t_cab		*t;

	t = e->pos_start;
	e->start++;
	while (t)
	{
		if (ft_strcmp(name, t->name) == 0)
			return (t);
		t = t->next;
	}
	return (NULL);
}

static int		analyse2(char *line, char **str, char **str_p, t_env *e)
{
	if (line && e->start == 1)
	{
		if (len_tab(str_p) != 3 || str_p[0][0] == 'L')
			return (free_tab(&str_p, &str, -1));
		creat_s_e(e, line);
		e->start = -1;
		return (free_tab(&str_p, &str, 1));
	}
	else if (line && e->end == 1)
	{
		if (len_tab(str_p) != 3 || str_p[0][0] == 'L')
			return (free_tab(&str_p, &str, -1));
		creat_s_e(e, line);
		e->end = -1;
		return (free_tab(&str_p, &str, 1));
	}
	if (line && str_p && len_tab(str_p) == 3)
		return (save_cab(line, e));
	else if (line && str && len_tab(str) == 2)
		return (link_save(str, e));
	return (free_tab(&str, &str_p, -1));
}

static int		analyse(char *line, t_env *e, int i)
{
	char		**str_p;
	char		**str;
	int			nb;

	if (line)
	{
		str = m_split(line);
		str_p = ft_strsplit(line, ' ');
	}
	if (i == 0)
	{
		nb = ft_atoi(line);
		if (nb < 0)
			return (-1);
		e->worms = nb;
		return (1);
	}
	else if (line && ft_strcmp(line, "##start") == 0 && e->start == 0)
		return (e->start = 1);
	else if (line && ft_strcmp(line, "##end") == 0 && e->end == 0)
		return (e->end = 1);
	else if (line && line[0] == '#' && (ft_strcmp(line, "##start") != 0
			|| ft_strcmp(line, "##end") != 0))
		return (free_tab(&str, &str_p, 1));
	return (analyse2(line, str, str_p, e));
}

int				parsefile(t_env *e)
{
	char		*line;
	int			ret;
	int			i;
	int			an;

	i = 0;
	while ((ret = get_next_line(0, &line)) >= 0 || !line)
	{
		if (!(an = analyse(line, e, i)))
			return (-1);
		if (line && line[0] != '#' && line[0] != '\0')
			i++;
		ft_putendl(line);
		if (an == -1 || ret == 0)
			break ;
		free(line);
	}
	write(1, "\n", 1);
	if (line)
		free(line);
	return (ret);
}
