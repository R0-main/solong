/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/27 14:22:07 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!alst || !new)
		return ;
	last = ft_lstlast(*alst);
	if (!last)
	{
		*alst = new;
	}
	else
		last->next = new;
}

// #include <stdio.h>
// int	main()
// {

// 	char	*str = "1";
// 	char	*str2 = "2";
// 	t_list	*my_new_list = ft_lstnew(str2);
// 	t_list	*my_pile = ft_lstnew(str);

// 	ft_lstadd_back(&my_pile, my_new_list);
// 	printf("%s", (char *)my_pile->next->content);
// 	return (0);
// }
