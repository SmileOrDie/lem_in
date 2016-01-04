/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:39:25 by shamdani          #+#    #+#             */
/*   Updated: 2016/01/04 17:14:21 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

typedef struct			s_link
{
	char				**link;
	struct s_link		*next;
}						t_link;

typedef struct			s_cab
{
	char				*name;
	int					pos[3];
	int					check;
	struct s_cab		*prev;
	struct s_cab		*next;
	struct s_cab		**link;
}						t_cab;

typedef struct			s_list
{
	t_cab				*browse;
	unsigned int		n;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

typedef struct			s_env
{
	char				*tab;
	int					start;
	int					end;
	unsigned int		nb;
	unsigned int		worms;
	unsigned int		pos_c;
	t_list				*browse;
	t_list				*bro_b;
	t_cab				*pos_start;
	t_cab				*pos_end;
	t_link				*link_t;
	t_cab				*cab_l;
}						t_env;

int						len_tab(char **s);
int						new_bro(t_env *e);
int						free_tab(char ***tab, char ***tab1, int ret);

int						parsefile(t_env *e);
t_cab					*ft_l_cab(char *name, t_env *e);
int						nb_link(char *name, t_env *e);

void					check_link(t_env *e);
int						link_save(char **tab, t_env *e);
int						save_cab(char *line, t_env *e);

char					**sp_split(const char *line);
char					**m_split(const char *line);

void					creat_s_e(t_env *e, char *line);
void					add_list(t_cab *s, t_env *e, int i);

#endif
