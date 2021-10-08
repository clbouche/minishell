/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:32:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/07 17:18:22 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** ends a process. Took 2 args max and the second one it's numeric. 
** It's not allowed to have option. 
*/

void	ft_exit()
{
    exit(EXIT_SUCCESS);
    /*  -> si process en cours, tue le process
        -> besoin du pid du process ?
        -> le stocker dans la structure ?
    */
    /*stocker le statut du retour dans la structure*/
    //ft_putstr_fd("exit", 1);
    //exit(0);
}