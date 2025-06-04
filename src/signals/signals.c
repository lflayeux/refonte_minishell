/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandemonium <pandemonium@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:49:02 by pandemonium       #+#    #+#             */
/*   Updated: 2025/06/04 23:51:52 by pandemonium      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_ctrl_c_interactive(int signal);
void	handle_ctrl_c_action(int signal);
void	handle_ctrl_dump(int signal);

/**
 * @brief Set default signal handlers for the interactive shell.
 *
 * Initializes the signal actions for `SIGINT` (Ctrl-C) and `SIGQUIT` (Ctrl-\).
 * - `SIGINT`: calls `handle_ctrl_c_interactive` to cleanly reset the prompt.
 * - `SIGQUIT`: is ignored.
 *
 * @param signals A pointer to the `t_signal` structure to configure.
 */
void	set_signal(t_signal *signals)
{
	sigemptyset(&signals->ctrl_c.sa_mask);
	signals->ctrl_c.sa_flags = 0;
	signals->ctrl_c.sa_handler = handle_ctrl_c_interactive;
	sigaction(SIGINT, &signals->ctrl_c, NULL);

	sigemptyset(&signals->ctrl_dump.sa_mask);
	signals->ctrl_dump.sa_flags = 0;
	signals->ctrl_dump.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &signals->ctrl_dump, NULL);
}

/**
 * @brief Update signal handler for the parent process after forking.
 *
 * Sets `SIGINT` (Ctrl-C) to call `handle_ctrl_c_action`, allowing the parent
 * to remain responsive while a child process runs.
 *
 * @param signals A pointer to the `t_signal` structure already configured.
 */
void	parent_signals(t_signal *signals)
{
	signals->ctrl_c.sa_handler = handle_ctrl_c_action;
	sigaction(SIGINT, &signals->ctrl_c, NULL);
}
/**
 * @brief Set default behavior for signals in the child process.
 *
 * Resets `SIGQUIT` (Ctrl-\) to its default behavior (`SIG_DFL`), allowing
 * the child process to terminate normally when receiving this signal.
 *
 * @param signals A pointer to the `t_signal` structure already configured.
 */
void	child_signals(t_signal *signals)
{
	signals->ctrl_dump.sa_handler = SIG_DFL;
	sigaction(SIGQUIT, &signals->ctrl_dump, NULL);
}
/**
 * @brief Restore the default signal behavior for the interactive shell.
 *
 * Used after a command execution or subprocess finishes to reset the
 * signal handlers to interactive mode:
 * - `SIGINT`: handled by `handle_ctrl_c_interactive`
 * - `SIGQUIT`: ignored
 *
 * @param signals A pointer to the `t_signal` structure already configured.
 */
void	reset_signals(t_signal *signals)
{
	signals->ctrl_c.sa_handler = handle_ctrl_c_interactive;
	sigaction(SIGINT, &signals->ctrl_c, NULL);
	signals->ctrl_dump.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &signals->ctrl_dump, NULL);
}