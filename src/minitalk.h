/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:19:08 by bruda-si          #+#    #+#             */
/*   Updated: 2024/05/31 17:45:47 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_global
{
	char	*str;
	int		length;
	int		bits_length;
	int		bit_char;
	int		character;

}	t_global;

#endif
