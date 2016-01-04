#include "lem_in.h"

int				free_tab(char ***tab,char ***tab2, int ret)
{
	int			i;

	i = 0;
	if (*tab)
	{
		while((*tab)[i])
		{
			free((*tab)[i]);
			i++;
		}
		free(*tab);
	}
	i = 0;
	if (*tab2)
	{
		while((*tab2)[i])
		{
			free((*tab2)[i]);
			i++;
		}
		free(*tab2);
	}
	return (ret);
}

int				len_tab(char **s)
{
	int			i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

static int		browse(t_cab *s, t_env *env, int l, int prof)
{
	int			i;
	int			end;

	i = 0;
	end = 0;	
	if (s && s->check == 0 && prof >= -1)
		s->check = 1;
	else
		return (end);
	while (s && s->link[i] && prof >= 0)
	{
		if (s->link[i]->check == 0 && s->link[i] != env->pos_end)
			end = browse(s->link[i], env, l, prof - 1);
		if (s->link[i] == env->pos_end || end == 1)
		{
			end = 1;
			break ;
		}
		i++;
	}
	if (end == 1 && s->link[i] != env->pos_start)
		add_list(s->link[i], env, l);
	s->check = 0;
	return (end);
}

int				new_bro(t_env *e)
{
	int			prof;
	int			res;

	prof = 0;
	while (prof <= e->start)
	{
		if ((res = browse(e->pos_start, e, 1, prof)) == 1)
			break ;
		prof++;
	}
	return (res);
}