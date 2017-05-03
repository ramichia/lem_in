/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_recursive_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 12:10:08 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:35 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		last_index(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	i--;
	return (i);
}

void	cut_last_room(char **tab, t_rooms *start)
{
	int		i;
	t_rooms	*lst;

	i = 0;
	while (tab[i])
		i++;
	i--;
	lst = find_room(tab[i], start);
	if (lst->position == 1)
		return ;
	lst->tracked = 1;
	ft_strdel(&tab[i]);
}

char	**copytab(char **tab)
{
	int		i;
	char	**tab2;

	i = 0;
	tab2 = initiate_tab();
	while (tab[i])
	{
		tab2[i] = ft_strdup(tab[i]);
		i++;
	}
	return (tab2);
}

char	**rec_path(char **tab, int i, t_rooms *start)
{
	t_rooms	*lst;

	lst = find_room(tab[i], start);
	i++;
	while (1)
	{
		lst = get_next_room(lst->links, tab);
		if (lst == NULL)
			return (tab);
		tab[i] = ft_strdup(lst->name);
		lst->tracked = 1;
		i++;
		if (lst->position == 2)
			return (tab);
	}
	return (tab);
}

void	real_rec_path(char **tab, int i, t_rooms *start)
{
	while (1)
	{
		tab = rec_path(tab, i, start);
		if (last_index(tab) == 0 && \
			check_link_start(find_room(tab[0], start)) == 0)
		{
			g_result = (char**)malloc(sizeof(char*) * 1);
			g_result[0] = NULL;
			return ;
		}
		if (get_last_tab(tab, start) == 1)
		{
			g_result = copytab(tab);
			free_char_tab(tab);
			free(tab);
			return ;
		}
		cut_last_room(tab, start);
		i = last_index(tab);
	}
}
