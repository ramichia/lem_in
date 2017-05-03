/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:16:09 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:31 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	**initiate_tab(void)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * 10000);
	while (i < 10000)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

t_rooms	*get_next_room(t_links **tab, char **tabus)
{
	int		i;
	t_rooms *tmp;

	i = 0;
	while (tab[i]->from)
	{
		tmp = tab[i]->dest;
		if (tmp->tracked == 1 || is_already_in_tab(tmp->name, tabus) == 0)
			i++;
		else
			return (tmp);
	}
	return (NULL);
}

int		get_last_tab(char **tab, t_rooms *start)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	i--;
	while (start)
	{
		if (ft_strcmp(start->name, tab[i]) == 0)
			break ;
		start = start->next;
	}
	if (start->position == 2)
		return (1);
	else
		return (0);
}

char	**first_path(t_rooms *start, char **tab)
{
	t_rooms	*lst;
	int		i;

	tab[0] = ft_strdup(g_start);
	i = 1;
	lst = get_next_room(start->links, tab);
	if (!lst)
		return (NULL);
	lst->tracked = 1;
	while (lst)
	{
		tab[i] = ft_strdup(lst->name);
		if (lst->position == 2)
			break ;
		lst = get_next_room(lst->links, tab);
		if (lst == NULL)
			break ;
		lst->tracked = 1;
		i++;
	}
	return (tab);
}

void	find_path(t_rooms *start)
{
	t_rooms	*tmp;
	char	**tab;
	int		i;

	tmp = start;
	while (tmp->position != 1)
		tmp = tmp->next;
	tmp->tracked = 1;
	tab = initiate_tab();
	tab = first_path(tmp, tab);
	if (!tab)
		return ;
	if (get_last_tab(tab, start) == 0)
	{
		cut_last_room(tab, start);
		i = last_index(tab);
		real_rec_path(tab, i, start);
	}
	else
	{
		g_result = copytab(tab);
		free_char_tab(tab);
		free(tab);
	}
}
