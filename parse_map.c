/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrabi <hdrabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:02:08 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/17 02:32:27 by hdrabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_norm_remplir_var1(t_map *data, int *i, int *j, int *a)
{
	while (data->files[*i][*j] == ' ')
		*j = *j + 1;
	if (data->files[*i][*j] == 'N' && data->files[*i][*j + 1] == 'O')
	{
		if (data->file_no != NULL)
			*a = 0;
		*j = *j + 2;
		while (data->files[*i][*j] == ' ')
			*j = *j + 1;
		data->file_no = ft_strdup(&data->files[*i][*j]);
		*j = *j + ft_strlen(&data->files[*i][*j]);
	}
	if (data->files[*i][*j] == 'S' && data->files[*i][*j + 1] == 'O')
	{
		if (data->file_so)
			*a = 0;
		*j = *j + 2;
		while (data->files[*i][*j] == ' ')
			*j = *j +1 ;
		data->file_so = ft_strdup(&data->files[*i][*j]);
		*j = *j + ft_strlen(&data->files[*i][*j]);
	}
}

void	ft_norm_remplir_var2(t_map *data, int *i, int *j, int *a)
{
	if (data->files[*i][*j] == 'W' && data->files[*i][*j + 1] == 'E')
	{
		if (data->file_we)
			*a = 0;
		*j = *j + 2;
		while (data->files[*i][*j] == ' ')
			*j = *j + 1;
		data->file_we = ft_strdup(&data->files[*i][*j]);
		*j = *j + ft_strlen(&data->files[*i][*j]);
	}
	if (data->files[*i][*j] == 'E' && data->files[*i][*j + 1] == 'A')
	{
		if (data->file_ea)
			*a = 0;
		*j = *j + 2;
		while (data->files[*i][*j] == ' ')
			*j = *j + 1;
		data->file_ea = ft_strdup(&data->files[*i][*j]);
		*j = *j + ft_strlen(&data->files[*i][*j]);
	}
}

void	ft_norm_remplir_var3(t_map *data, int *i, int *j, int *a)
{
	if (data->files[*i][*j] == 'C')
	{
		if (data->file_c != -1)
			*a = 0;
		*j = *j + 1;
		while (data->files[*i][*j] == ' ')
			*j = *j + 1;
		ft_hexa(&data->file_c, &data->files[*i][*j]);
		*j = *j + ft_strlen(&data->files[*i][*j]);
	}
	if (data->files[*i][*j] == 'F')
	{
		if (data->file_f != -1)
			*a = 0;
		*j = *j + 1;
		while (data->files[*i][*j] == ' ')
			*j = *j + 1;
		ft_hexa(&data->file_f, &data->files[*i][*j]);
		*j = *j + ft_strlen(&data->files[*i][*j]);
	}
}

void	ft_parse_map1(int nb, t_map *data, char *map)
{
	int	fd;
	int	i;

	i = 0;
	ft_initiale(data);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_message_and_exit("Error : file doesn't exist or permission denied");
	data->line = get_next_line(fd);
	if (!data->line)
		ft_message_and_exit("Error : file is empty");
	if (data->line[0] == 0)
		ft_message_and_exit("error in folder map");
	data->pos = ft_handel_map(data->line);
	if (data->pos == -1)
		ft_message_and_exit("Error : map not found");
	ft_divis_line(data);
	if (ft_check_line(data->var2) == -1)
		ft_message_and_exit("Error: newline found");
	ft_check_content_data(nb, data->var2);
	data->map = ft_split(data->var2, '\n');
	free(data->var2);
	get_width_height(data);
	free(data->line);
}

int	main(int ac, char *av[])
{
	t_map	data;

	if (ac != 2)
	{
		printf("Error\n");
		exit(0);
	}
	ft_parse_map(1, &data, av[1]);
	ft_printf_data(&data);
	ft_free_double_pointer(data.map);
	free(data.file_no);
	free(data.file_so);
	free(data.file_we);
	free(data.file_ea);
}
