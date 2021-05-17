/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:34:59 by xli               #+#    #+#             */
/*   Updated: 2021/05/17 16:18:18 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

void	sa(t_deque *stack[2]);
void	sb(t_deque *stack[2]);
void	ss(t_deque *stack[2]);
void	pa(t_deque *stack[2]);
void	pb(t_deque *stack[2]);
void	ra(t_deque *stack[2]);
void	rb(t_deque *stack[2]);
void	rr(t_deque *stack[2]);
void	rra(t_deque *stack[2]);
void	rrb(t_deque *stack[2]);
void	rrr(t_deque *stack[2]);
void	error_exit(void);
void	normal_exit(void);
void	init_stack(t_deque *stack, int *arr, int arr_size);
void	assign_operation(t_deque *stack[2], void *ptr);
int		check_duplicate(int *arr, int arr_size);
int		get_arr_size(int **arr, int ac, char **av);
void	check_instructions(char *str);
void	exit_handle(int ct[2], int *arr[3], t_deque *stack[2]);
void	index_nb(int *arr, int *temp, int arr_size);

#endif
