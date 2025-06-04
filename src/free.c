/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:29:14 by pandemonium       #+#    #+#             */
/*   Updated: 2025/06/04 23:37:34 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_all(t_shell *shell)
{
	if (shell->signals)
		free(shell->signals);
	if (shell->tok)
		ft_lstclear_tok(shell->tok);
	if (shell)
		free(shell);
}