/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:17:13 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:45 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms	*fill_room(t_rooms *room, char **data, t_rooms *start)
{
	room->name = ft_strdup(data[0]);
	room->positionx = ft_strdup(data[1]);
	room->positiony = ft_strdup(data[2]);
	room->tracked = 0;
	room->isroom = 1;
	room = check_map(room, start);
	if (!room)
		return (NULL);
	if (check_name_rooms(room, start) == 0)
		return (NULL);
	return (room);
}

t_rooms	*fill_tube(t_rooms *room, char **link, char *line, t_rooms *start)
{
	room->isroom = 0;
	room->name = ft_strdup(line);
	room->from = ft_strdup(link[0]);
	room->to = ft_strdup(link[1]);
	room->position = 0;
	ft_strdel(&line);
	start = start->next;
	if (check_name_tube(room->to, start) == 0 || \
		check_name_tube(room->from, start) == 0)
		return (NULL);
	return (room);
}

t_rooms	*read_inter_rooms(char *line, t_rooms *start, t_rooms *room)
{
	char	**data;
	char	**link;

	data = ft_strsplit(line, ' ');
	link = ft_strsplit(line, '-');
	if (data[1] && (data[2]))
	{
		ft_strdel(&line);
		room = fill_room(room, data, start);
		free_char_tab(data);
	}
	else if (!line || !link[0] || !link[1] || link[2])
		return (NULL);
	else
		room = fill_tube(room, link, line, start);
	free_char_tab(data);
	free_char_tab(link);
	free(data);
	free(link);
	return (room);
}

t_rooms	*read_rooms(char *line, t_rooms *start)
{
	t_rooms	*room;
	int		r;

	if (!line || ft_strcmp("", line) == 0)
		return (NULL);
	g_map[g_index++] = ft_strdup(line);
	r = 10;
	room = (t_rooms*)malloc(sizeof(t_rooms));
	while (0 < r && line[0] == '#' && line[1] != '#')
	{
		ft_strdel(&line);
		r = get_next_line(0, &line);
		g_map[g_index++] = ft_strdup(line);
	}
	if (!line)
		return (NULL);
	while (line[0] == '#' && line[1] == '#')
	{
		room->position = start_end(line);
		ft_strdel(&line);
		get_next_line(0, &line);
		g_map[g_index++] = ft_strdup(line);
	}
	return (read_inter_rooms(line, start, room));
}

t_rooms	*create_rooms(t_rooms *lst, char *line)
{
	t_rooms	*start;
	int		r;

	r = 1;
	start = malloc(sizeof(t_rooms));
	start->x = -1;
	start->y = -1;
	while (get_next_line(0, &line))
	{
		lst = read_rooms(line, start);
		if (!lst)
		{
			ft_strdel(&g_map[g_index - 1]);
			break ;
		}
		ft_lstadd_room(start, lst);
	}
	start = start->next;
	return (start);
}
