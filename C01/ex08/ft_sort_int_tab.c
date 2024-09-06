/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:50:00 by amho              #+#    #+#             */
/*   Updated: 2024/08/29 16:45:19 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	sorted;

	if (size <= 1)
    		return ;
	sorted = 0;
	while (sorted == 0)
	{
    	sorted = 1;
    	i = 0;
    	while (i < size - 1)
    	{
        	if (tab[i] > tab[i + 1])
        	{
            	ft_swap(&tab[i], &tab[i + 1]);
            	sorted = 0;
        	}
        	i++;
    	}
	}
}
