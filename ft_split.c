/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:56:12 by ojamil            #+#    #+#             */
/*   Updated: 2022/04/16 20:59:43 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_word(char *s, char c)
{
	int	i;
	int	flage;
	int	cp;

	i = 0;
	flage = 0;
	cp = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && flage == 0)
		{
			cp++;
			flage = 1;
		}
		else if (s[i] == c && flage == 1)
			flage = 0;
		i++;
	}
	return (cp);
}

int	ft_count_and_alloc(char *s, char c)
{
	int	i;
	int	cp;

	i = 0;
	cp = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		cp++;
	}
	if (cp == 0)
		return (0);
	return (cp);
}

int	ft_split_2(char *s, char c, char **str, int i)
{
	int	j;
	int	k;

	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			k = 0;
			str[j] = (char *)malloc(ft_count_and_alloc((char *)&s[i], c) + 1);
			if (!str[j])
				exit(0);
			while (k < ft_count_and_alloc((char *)&s[i], c))
			{
				str[j][k] = s[i + k];
				k++;
			}
			str[j++][k] = 0;
			i += k;
		}
	}
	str[j] = 0;
	return (-1);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * count_word(s, c) + 1);
	if (!str)
		exit(0);
	j = ft_split_2(s, c, str, 0);
	if (j != -1)
	{
		while (j >= 0)
		{
			free(str[j]);
			j--;
		}
		free(str);
	}
	return (str);
}
