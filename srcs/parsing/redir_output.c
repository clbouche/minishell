/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:54:08 by claclou           #+#    #+#             */
/*   Updated: 2021/10/08 18:09:43 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		recup_file_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' || str[i] != '|' || str[i] != '>'
		|| str[i] != '<')
		i++;
	printf("check i : %i\n", i);
	return (i);
}

char	*recup_filename(char *str)
{
	int	i;
	int	j;
	int	len;
	char	*file_name;

	i = 0;
	j = 0;
	len = recup_file_len(str);
	printf("str : %s\n", str);
	file_name = malloc(sizeof(char) * (len + 1));
	while (str[i] != ' ' || str[i] != '|' || str[i] != '>'
			|| str[i] != '<')
			file_name[j++] = str[i++];
	//faire des tests avec les quotes pcq pas tout a fait clair
	return (file_name);
}