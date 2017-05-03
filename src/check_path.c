/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:56:35 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:18 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	find_start_end(t_rooms *start)
{
	while (start)
	{
		if (start->position == 1)
			g_start = ft_strdup(start->name);
		else if (start->position == 2)
			g_end = ft_strdup(start->name);
		start = start->next;
	}
}

int		check_links(char *linkname, char **links, char *str)
{
	int		i;

	i = 0;
	while (links[i])
	{
		if (ft_strcmp(links[i], linkname) == 0)
			return (0);
		i++;
	}
	if (ft_strcmp(str, linkname) == 0)
		return (0);
	return (1);
}

int		count_ants(void)
{
	int		i;
	int		count;
	char	*line;

	get_next_line(0, &line);
	g_map[g_index++] = ft_strdup(line);
	i = 0;
	while (line[i])
	{
		if (line[i] < 48 || 57 < line[i])
			return (0);
		i++;
	}
	count = ft_atoi(line);
	ft_strdel(&line);
	g_nbants = count;
	return (count);
}

int		start_end(char *line)
{
	if (ft_strcmp(&line[2], "start") == 0)
		return (1);
	if (ft_strcmp(&line[2], "end") == 0)
		return (2);
	return (0);
}
