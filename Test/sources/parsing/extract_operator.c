/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:18:15 by mbonati           #+#    #+#             */
/*   Updated: 2019/09/12 12:18:16 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char	*extract_operator(char *line, int *i)
{
	//printf("extract_operator\n");

	char	c_op;
	size_t	operator_size;
	char	*operator;
	size_t	y;

	c_op = line[*i];
	operator_size = 1;
	operator = NULL;
	if (line[*i + 1] == c_op || line[*i + 1] == '&')
		operator_size = 2;
	if (!(operator = malloc(sizeof(char) * (operator_size + 1))))
		return (error_malloc("extract_operator"));
	operator[operator_size] = '\0';
	y = 0;
	while (y < operator_size)
	{
		operator[y] = line[*i];
		(*i)++;
		y++;
	}
	return (operator);
}

char	*extract_separator(int *i)
{
	//printf("extract_separator\n");

	char *res;

	if (!(res = malloc(sizeof(char) * 2)))
		return (error_malloc("extract_separator"));
	res[0] = ';';
	res[1] = '\0';
	(*i)++;
	return (res);
}
