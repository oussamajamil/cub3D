/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:25:26 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/16 04:43:44 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_extens_map(char *str)
{
	char	**res;

	res = NULL;
	res = ft_split(str, '.');
	if (ft_strcmp(res[1], "cub") != 0)
	{
		printf("error map\n");
		ft_free_double_pointer(res);
		exit(0);
	}
	else
		ft_free_double_pointer(res);
}

int	ft_check_file_exist(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	close (fd);
	return (0);
}

void	ft_divis_line(t_map *data)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	j = 0;
	data->var1 = malloc(sizeof(char) * (data->pos + 1));
	if (data->var1 == NULL)
		exit(0);
	while (++i < data->pos)
		data->var1[i] = data->line[i];
	data->var1[i] = 0;
	l = ft_strlen(data->line) - data->pos;
	data->var2 = malloc(sizeof(char) * (l + 1));
	if (data->var2 == NULL)
		exit(0);
	while (j < l - 1)
	{
		data->var2[j] = data->line[i];
		i++;
		j++;
	}
	data->var2[j] = 0;
}

int	ft_check_map_vertical(char **map, int width, int height)
{
	int	i;
	int	j;

	j = -1;
	while (++j < width)
	{
		i = 0;
		while (i < height)
		{
			while (i < height && map[i][j] == ' ')
				i++;
			if (i == height)
				break ;
			if (map[i][j] != '1')
				return (-1);
			while (i < height && map[i][j] != ' ')
				i++;
			if (map[i - 1][j] != '1')
				return (-1);
			while (i < height && map[i][j] == ' ')
				i++;
		}
	}
	return (0);
}

void	ft_printf_data(t_map *data)
{
	printf("C[%d]\n", data->file_c);
	printf("F[%d]\n", data->file_f);
	printf("NO[%s]\n", data->file_no);
	printf("SO[%s]\n", data->file_so);
	printf("EA[%s]\n", data->file_ea);
	printf("WE[%s]\n", data->file_we);
}
