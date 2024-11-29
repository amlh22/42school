/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:14:27 by amho              #+#    #+#             */
/*   Updated: 2024/11/30 04:37:49 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    t_list *head = NULL;
    t_list *new_node;
    
    int num = 42;
    new_node = ft_lstnew(&num);
    
    ft_lstadd_front(&head, new_node);
    
    printf("First node content: %d\n", *(int *)head->content);
    
    int num2 = 84;
    new_node = ft_lstnew(&num2);
    ft_lstadd_front(&head, new_node);
    
    printf("Content after adding another: %d\n", *(int *)head->content);
    
    free(head->next);  
    free(head);      
    
    return 0;
}
*/
