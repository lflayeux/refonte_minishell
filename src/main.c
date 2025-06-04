/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:43:33 by pandemonium       #+#    #+#             */
/*   Updated: 2025/06/05 00:13:23 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;
	
	(void)argc;
	(void)argv;
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (free_all(shell), write(2, "malloc error\n", 13));
	init_shell(shell, envp);
	while (1)
	{
		shell->input = readline(PROMPT);
		if (input == NULL || ft_strcmp(input, "exit") == 0)
			return (free_all(shell), printf("exit"), 0);
		else
		{
			tokenize();
			add_history(input);
		
		}
		reset_shell(shell);
	}
	free_all(shell);
}
