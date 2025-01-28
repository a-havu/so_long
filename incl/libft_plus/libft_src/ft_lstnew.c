/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:21:21 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:37:25 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *new;

    new = ft_calloc(1, sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;

    return (new);
}