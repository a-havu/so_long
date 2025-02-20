/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:03:21 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:36:50 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *tmp;
    
    if (!*lst || !del)
        return ;
    while (*lst)
    {
        tmp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = tmp;
    }
    *lst = NULL;
}
