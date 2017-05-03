/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 08:41:56 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:28 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_links	**initiate_startlinks(void)
{
	t_links	**startlinks;
	int		i;

	i = 0;
	startlinks = (t_links**)malloc(sizeof(t_links) * 20);
	while (i < 20)
	{
		startlinks[i] = (t_links*)malloc(sizeof(t_links));
		startlinks[i]->from = NULL;
		i++;
	}
	return (startlinks);
}

t_rooms	*identify_links(char *str, t_rooms *start)
{
	while (start->isroom == 1)
	{
		if (ft_strcmp(start->name, str) == 0)
			return (start);
		start = start->next;
	}
	return (NULL);
}

t_links	**find_links(t_rooms *start, t_rooms *lst)
{
	t_links	**tablinks;
	t_rooms	*tmp;
	int		i;

	i = 0;
	tablinks = initiate_startlinks();
	tmp = start;
	while (tmp->isroom == 1)
		tmp = tmp->next;
	while (tmp)
	{
		if (ft_strcmp(tmp->from, lst->name) == 0 && tmp->tracked != 1)
		{
			tablinks[i]->from = ft_strdup(lst->name);
			tablinks[i++]->dest = identify_links(tmp->to, start);
		}
		else if (ft_strcmp(tmp->to, lst->name) == 0 && tmp->tracked != 1)
		{
			tablinks[i]->from = ft_strdup(lst->name);
			tablinks[i++]->dest = identify_links(tmp->from, start);
		}
		tmp = tmp->next;
	}
	return (tablinks);
}

void	fill_links(t_rooms *start)
{
	t_rooms	*tmp;

	tmp = start;
	while (tmp->isroom == 1)
	{
		tmp->links = find_links(start, tmp);
		tmp = tmp->next;
	}
}
