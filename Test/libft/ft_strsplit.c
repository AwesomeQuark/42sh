/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:50:47 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:46:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		count_lett(char *word, char c)
{
	size_t i;

	i = 0;
	while (word[i] != c && word[i] != '\0')
		i++;
	return (i);
}

static	char		*ft_extract_word(char *str, size_t *i, char c)
{
	char		*word;
	size_t		i_word;

	i_word = 0;
	while (str[*i] == c)
		(*i)++;
	if (!(word = (char *)malloc(sizeof(char) * (count_lett(&str[*i], c) + 1))))
		return (0);
	while (str[*i] != c && str[*i] != '\0')
	{
		word[i_word] = str[*i];
		(*i)++;
		i_word++;
	}
	word[i_word] = '\0';
	return (word);
}

static	size_t		ft_count_word(char *str, char c)
{
	size_t i;
	size_t nbr_mots;

	i = 0;
	nbr_mots = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			nbr_mots++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (nbr_mots);
}

char				**ft_strsplit(char *str, char c)
{
	size_t		i;
	size_t		y;
	size_t		hauteur_tab;
	char		**tab;

	if (str == NULL)
		return (NULL);
	hauteur_tab = ft_count_word(str, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (hauteur_tab + 1))))
		return (NULL);
	tab[hauteur_tab] = NULL;
	y = 0;
	i = 0;
	while (y < hauteur_tab)
	{
		if (!(tab[y] = ft_extract_word(str, &i, c)))
			return (0);
		y++;
	}
	return (tab);
}
