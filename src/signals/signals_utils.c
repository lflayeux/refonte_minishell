/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:49:39 by pandemonium       #+#    #+#             */
/*   Updated: 2025/06/04 23:50:36 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Handle SIGINT (Ctrl-C) in interactive mode.
 *
 * This function is called when the user presses Ctrl-C while the shell is waiting
 * for input. It clears the current line and redisplays the prompt.
 *
 * @param signal The signal number received (should be SIGINT).
 */
void	handle_ctrl_c_interactive(int signal)
{
	if (signal != SIGINT)
		return ;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
/**
 * @brief Handle SIGINT (Ctrl-C) during command execution.
 *
 * This function is called when Ctrl-C is pressed while a command is running.
 * It simply prints a newline to keep the shell output clean.
 *
 * @param signal The signal number received (should be SIGINT).
 */
void	handle_ctrl_c_action(int signal)
{
	if (signal != SIGINT)
		return ;
	printf("\n");
}
/**
 * @brief Handle SIGQUIT (Ctrl-\) signal.
 *
 * This function is called when the user presses Ctrl-\. It clears the current
 * input line, but does not redisplay the prompt, leaving the output clean.
 *
 * @param signal The signal number received (should be SIGQUIT).
 */
void	handle_ctrl_dump(int signal)
{
	if (signal != SIGQUIT)
		return ;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}