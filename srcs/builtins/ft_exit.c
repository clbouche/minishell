/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:32:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/07 11:37:26 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
    ft_putchar_fd('\n', 1);
    exit(0);
}