/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:57:13 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/16 17:12:17 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_width_height(t_map *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
	{
		if (data->width < ft_strlen(data->map[i]))
			data->width = ft_strlen(data->map[i]);
	}
	data->height = i;
}

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

void	ft_remplir_map(t_map *data)
{
	int		i;
	int		j;
	char	*buffer;

	i = -1;
	buffer = malloc(sizeof(char) * (data->width + 1));
	if (!buffer)
		return ;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (j < ft_strlen(data->map[i]))
				buffer[j] = data->map[i][j];
			else
				buffer[j] = ' ';
		}
		buffer[j] = '\0';
		free(data->map[i]);
		data->map[i] = ft_strdup(buffer);
	}
	free(buffer);
}

int	ft_check_map_horizontal(char **map, int width, int height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (map[i][++j])
		{
			while (map[i][j] == ' ')
				j++;
			if (!map[i][j])
				break ;
			if (map[i][j] != '1')
				return (-1);
			else
			{
				while (map[i][j] != ' ' && map[i][j] != '\0')
					j++;
				if (map[i][j - 1] != '1' && map[i][j] != '\0')
					return (-1);
			}
		}
	}
	return (0);
}

int	ft_handel_map(char *line)
{
	int	pos;
	int	i;
	int	a;

	pos = -1;
	i = 0;
	while (line[i] == ' ' || line[i] == '\n')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (-1);
	while (line[i])
	{
		while (line[i] != '\n' && line[i] != '1' && line[i] != '0')
			i++;
		if (line[i] == '\n')
		{
			while (line[i] == '\n')
				i++;
			pos = i;
			i++;
			while (line[i] == ' ')
				i++;
			if (line[i] == '1' || line[i] == '0')
				return (pos);
		}
		i++;
	}
	return (-1);
}
