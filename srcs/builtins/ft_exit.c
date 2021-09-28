/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:32:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/28 12:03:53 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** ends a process. Took 2 args max and the second one it's numeric. 
** It's not allowed to have option. 
*/

int	ft_exit()
{
    
    /*  -> si process en cours, tue le process
        -> besoin du pid du process ?
        -> le stocker dans la structure ?
    */
    /*stocker le statut du retour dans la structure*/
    ft_putstr_fd("exit", 1);
    exit(0);
}