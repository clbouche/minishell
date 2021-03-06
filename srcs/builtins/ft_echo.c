/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:18:32 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/16 13:31:03 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Echo function write (illimiteds) arguments
** to the standard output with a new line 
** unless the -n option is set. 
*/
static int	handle_multiarg(char **cmd, int i)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	while (cmd[i] != NULL)
	{
		if (cmd[i + 1] == NULL)
			ft_putstr_fd(cmd[i], 1);
		else
		{
			ft_putstr_fd(cmd[i], 1);
			ft_putchar_fd(' ', 1);
		}
		i++;
	}
	return (0);
}

int	ft_echo(char **cmd, t_data *d)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	(void)d;
	if (cmd[1] == NULL)
		return (1);
	else if (cmd[i] && ft_strncmp("-n", cmd[i], 2) == 0)
	{
		while (cmd[i + 1] && ft_strncmp(cmd[i + 1], "-n", 2) == 0)
			i++;
		handle_multiarg(cmd, i + 1);
	}
	else
	{
		handle_multiarg(cmd, i);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
