/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:34:59 by xli               #+#    #+#             */
/*   Updated: 2021/05/22 16:39:02 by xli              ###   ########lyon.fr   */
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
void	init_stack(t_deque *stack, int *arr, int arr_size);
void	assign_operation(t_deque *stack[2], void *ptr);
void	do_operations(t_deque *stack[2], char *str, t_deque *operations);
int		check_duplicate(int *arr, int arr_size);
int		get_arr_size(int **arr, int ac, char **av);
//void	check_instructions(char *str);
int		stack_a_is_sorted(t_deque *stack[2]);
int		is_sorted(t_deque *stack[2]);
void	error_exit(void);
void	normal_exit(void);
int		ft_atoi_with_range(char **str);
int		get_min(t_deque *stack[2]);
int		get_pos(int	nb, t_deque *stack[2]);
void	big_solve(t_deque *stack[2], t_deque *operations);
void	small_solve(t_deque *stack[2], t_deque *operations);
t_deque	*push_swap(t_deque *stack[2]);

#endif
