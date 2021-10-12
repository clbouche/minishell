/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:28 by claclou           #+#    #+#             */
/*   Updated: 2021/10/12 14:04:08 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** E
*/
void	redir_read_input(char *str, char **input, t_data *data)
{
	(void)str;
	(void)input;
	(void)data;
	//heredoc a se renseigner
}

/*
** E
*/
void	redir_input(char *str, char **input, t_data *data)
{
	(void)str;
	(void)input;
	(void)data;
	//pas compris les moments ou c'est plus utile 
	//que de juste rien mettre
}

/*
** Redirige le contenu de l'information demandee vers un fichier
** sans ecraser son contenu (ajoute a la fin).
*/
void	redir_output_append(char *str, char **input, t_data *data)
{
	(void)str;
	(void)input;
	(void)data;
	//si pas de fichier a ce nom, passer par redir_output
	//else ajouter a la fin du fichier 
}

/*
** Redirige le contenu de l'information demandee vers un fichier.
*/
void	redir_ouput(char *str, char **input, t_data *data)
{
	int		i;
	char	*file_name;

	(void)input;
	(void)data;
	i = 0;
	file_name = recup_filename(str);
	//aller chercher l'arg suivant 
	//recuperer le nom du fichier a creer 
	//creer ce fichier et lui donner tous les flags (je penses?)
	//changer l'output dans les datas 
	//si il n'y a pas d'arg avant la redir : 
	// la creation du file fonctionne quand meme 
}

/*
** Verifie le type de redirections dont il s'agit pour envoyer a la bonne fonction.
*/
void	check_redir(char **input, int i, t_data *data)
{
	char	*str;
	int		j;

	str = *input;
	j = i;
	if (str[i] == '>' && str[i + 1] != '>')
	{
		redir_ouput(&str[i + 1], input, data);
		printf(">\n");
	}
	else if (str[i] == '>' && str[i + 1] == '>')
	{
		//redir_output_append(str, i, input, data);
		printf(">>\n");
	}
	else if (str[i] == '<' && str[i + 1] != '<')
	{
		//redir_input(str, i, input, data);
		printf("<\n");
	}
	else if (str[i] == '<' && str[i + 1] == '<')
	{
		//redir_read_input(str, i, input, data);
		printf("<<\n");
	}
}

/*
** Verifie si on rencontrer une redirection dans la ligne de commande.
*/
int	manage_redir(char **input, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	str = *input;
	while (str[i++])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			check_redir(input, i, data);
			return (1);
		}
	}
	return (0);
}
