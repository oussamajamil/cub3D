/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:12:00 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/16 18:15:04 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

void	ft_message_and_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
}

int	ft_check_data_final(t_map *dt)
{
	if (dt->file_ea == NULL || dt->file_no == NULL
		|| dt->file_so == NULL || dt->file_we == NULL
		|| dt->file_c == -1 || dt->file_f == -1)
		return (-1);
	return (0);
}

void	ft_check_content_data(int nb, char *str)
{
	int	i;
	int	cp;

	i = 0;
	cp = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n')
			i++;
		if (str[i] == 'E' || str[i] == 'W' || str[i] == 'S' || str[i] == 'N')
		{
			if (cp >= 1)
				ft_message_and_exit("Error : Duplicate player");
			cp++;
		}
		if ((str[i] == 'F' || str[i] == 'D' || str[i] == 'T') && nb == 0)
			ft_message_and_exit("Error: invalid identifier");
		if (str[i] != 'E' && str[i] != 'W' && str[i] != 'S'
			&& str[i] != 'N' && str[i] != 'F'
			&& str[i] != 'D' && str[i] != '0' && str[i] != '1')
			ft_message_and_exit("Error: invalid identifier");
		i++;
	}
}

void	ft_parse_map(int nb, t_map *data, char *map)
{
	if(map[0] == 0)
		ft_message_and_exit("Error: param invalid");
	ft_check_extens_map(map);
	ft_parse_map1(nb, data, map);
	ft_remplir_map(data);
	if (ft_check_map_horizontal(data->map, data->width, data->height) == 0
		&& ft_check_map_vertical(data->map, data->width, data->height) == 0)
	{
		data->files = ft_split(data->var1, '\n');
		ft_remplir_var(data);
		if (ft_check_data_final(data) == -1)
			ft_message_and_exit("Error: missing informations");
		if
		(ft_check_file_exist(data->file_no) == -1
			|| ft_check_file_exist(data->file_so) == -1
			|| ft_check_file_exist(data->file_we) == -1
			|| ft_check_file_exist(data->file_ea) == -1)
			ft_message_and_exit("Error : invalid texture files");
	}
	else
		ft_message_and_exit("Error: Map not enclosed by walls");
}

void	ft_remplir_var(t_map *data)
{
	int	i;
	int	j;
	int	k;
	int	a;

	i = -1;
	a = -1;
	while (data->files[++i])
	{
		j = -1;
		while (data->files[i][++j])
		{
			ft_norm_remplir_var1(data, &i, &j, &a);
			ft_norm_remplir_var2(data, &i, &j, &a);
			ft_norm_remplir_var3(data, &i, &j, &a);
		}
	}
	if (a == 0)
		ft_message_and_exit("Error : Duplicate informations");
}
