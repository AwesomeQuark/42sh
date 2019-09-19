/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strsplit_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:33:44 by mbonati           #+#    #+#             */
/*   Updated: 2019/06/11 10:33:48 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int			is_charset(char c, char *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	size_t		count_let(char *word, char *set)
{
	size_t i;

	i = 0;
	while (!(is_charset(word[i], set) && word[i] != '\0'))
		i++;
	return (i);
}

static	char		*ft_extract_word(char *str, size_t *i, char *set)
{
	char		*word;
	size_t		i_word;

	i_word = 0;
	while (is_charset(str[*i], set))
		(*i)++;
	if (!(word = (char *)malloc(sizeof(char) * (count_let(&str[*i], set) + 1))))
		return (0);
	while (!(is_charset(str[*i], set) && str[*i] != '\0'))
	{
		word[i_word] = str[*i];
		(*i)++;
		i_word++;
	}
	word[i_word] = '\0';
	return (word);
}

static	size_t		ft_count_word(char *str, char *set)
{
	size_t i;
	size_t nbr_mots;

	i = 0;
	nbr_mots = 0;
	while (str[i] != '\0')
	{
		while (is_charset(str[i], set))
			i++;
		if (str[i] != '\0')
			nbr_mots++;
		while (!(is_charset(str[i], set)) && str[i] != '\0')
			i++;
	}
	return (nbr_mots);
}

char				**ft_strsplit_set(char *str, char *set)
{
	size_t		i;
	size_t		y;
	size_t		hauteur_tab;
	char		**tab;

	if (str == NULL)
		return (NULL);
	hauteur_tab = ft_count_word(str, set);
	if (!(tab = (char **)malloc(sizeof(char *) * (hauteur_tab + 1))))
		return (NULL);
	tab[hauteur_tab] = NULL;
	y = 0;
	i = 0;
	while (y < hauteur_tab)
	{
		if (!(tab[y] = ft_extract_word(str, &i, set)))
			return (0);
		y++;
	}
	return (tab);
}
