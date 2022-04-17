/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrabi <hdrabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:22:39 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/17 02:31:32 by hdrabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_stjoin(char *str1, char *str2)
{
	int		l;
	char	*result;
	int		i;
	int		j;

	result = NULL;
	i = -1;
	j = -1;
	if (!str1)
	{
		str1 = malloc(1);
		if (!str1)
			exit(0);
		str1[0] = '\0';
	}
	result = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!result)
		exit(0);
	while (str1[++i])
		result[i] = str1[i];
	while (str2[++j])
		result[i + j] = str2[j];
	result[i + j] = '\0';
	free(str1);
	return (result);
}

char	*get_line(int fd)
{
	char	*line;
	char	*buffer;
	int		a;

	line = NULL;
	buffer = NULL;
	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		exit(0);
	a = 1;
	while (a > 0)
	{
		a = read(fd, buffer, 1);
		if (a < 0)
			exit(0);
		else if (a == 0)
			break ;
		else
		{
			buffer[1] = '\0';
			line = ft_stjoin(line, buffer);
		}
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	if (fd < 0)
		exit(0);
	line = get_line(fd);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*str;

	i = 0;
	l = ft_strlen(s1);
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		exit(0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
