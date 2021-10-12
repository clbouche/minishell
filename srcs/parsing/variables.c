/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:46:38 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/12 15:37:37 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**
*/
int		check_unvalid_char(int i)
{
	if (i == '\\' || i == '$' || i == '"' ||
			i == '\'' || i == '>' || i == '<')
		return (FAILURE);
	return (SUCCESS);
}

/*
** Permet d'aller recuperer le contenu d'une variable dispo dans l'env
** pour que la variable que l'on cree prenne ce nom.
** Si aucune variable dans l'env n'existe avec ce nom : error.
*/
char	*create_variable(char *line, t_data *data)
{
	(void)data;
	printf("check content of future variable : %s\n", line);
	//parcourir l'env a la recherche de la variable
	return (line);
}

/*
** Recuperer le nom et le contenu de la variable a ajouter
** ou a ecrire
*/
void    manage_variable(char *line, t_data *data)
{
	char    *name = NULL; // a malloc
	char    *content;
	int		i;

	i = 0;
	while(line[i] != ' ') 
	{
		if (line[i] == '=')
			content = create_variable(&(line[i + 1]), data);
		if (check_unvalid_char(line[i]) == FAILURE)
			i++;
		else
		{
			name[i] = line[i];
			i++;
		}
	}
	//si aucune variable n'existe, juste afficher un retour a la ligne
	//si content est NULL, on veut juste afficher la variable.
	//apres le = recuperer son content;
	//recreer une ligne avec le nouvel arg ? 
	//besoin de parcourir l'environnement pour savoir si une var existe deja
}


/*
** Retourne le retour de la derniere ligne de commande
*/
void	return_last_rtn(t_data	*data)
{
	//verifier que le fichier d'historique n'est pas vide
	//si rempli, aller la fin du fichier
	//recuperer la derniere ligne 
	//et l'executer
	(void)data;
	printf("return history\n");
}