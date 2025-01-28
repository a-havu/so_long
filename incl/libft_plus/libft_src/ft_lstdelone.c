/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:43:21 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:36:52 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if(!lst || !del)
        return ;
    del(lst->content);
    free(lst);
}