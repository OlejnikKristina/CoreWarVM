/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 19:08:18 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/29 15:20:52 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function copies cursor
**	@param	- t_cursor *src, cursor to be copied
**			- int pos, position of new cursor
**			- long id, id of parent cursor
**	@return	- t_cursor *new, copied cursor
*/

t_cursor	*cp_cursor(t_cursor *src, int pos, long id)
{
	t_cursor	*new;

	new = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	ft_memcpy(new, src, sizeof(t_cursor));
	new->pos = pos;
	new->id = id;
	new->moved = 1;
	new->prev_xy[0] = -1;
	new->prev_xy[1] = -1;
	return (new);
}

/*
**  @desc   - function moves cursor to new location
**  @param  - t_vm *vm, main struct
**			- t_cursor *c, cursor to move
**			- int move, amount to move
*/

void		mv_cursor(t_cursor *c, int move)
{
	int old_pos;

	old_pos = c->pos;
	c->pos = get_index(old_pos, move);
	c->moved = 1;
}

/*
**	@desc	- function removes cursor from list
**	@param	- head of the linked list
**			- long id, id of cursor to remove
**	@return - t_cursor *head, new head of the linked list
*/

t_cursor	*rm_cursor(t_cursor *head, long id)
{
	t_cursor *prv;
	t_cursor *tmp;

	if (head->id == id)
	{
		tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL;
		return (head);
	}
	tmp = head;
	while (tmp)
	{
		if (tmp->id == id)
		{
			prv->next = tmp->next;
			free(tmp);
			tmp = NULL;
			break ;
		}
		prv = tmp;
		tmp = tmp->next;
	}
	return (head);
}

/*
**  @desc   - function moves cursor to new location
**  @param  - int position, position of the cursor
**			- int r1, value of r1
**			- long id, id of cursor
**	@return	- t_cursor *c, new cursor
*/

t_cursor	*new_cursor(int position, int r1, long id)
{
	t_cursor *c;

	c = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	c->id = id;
	c->pos = position;
	c->reg[0] = r1;
	c->moved = 1;
	c->prev_xy[0] = -1;
	c->prev_xy[1] = -1;
	return (c);
}

/*
**  @desc   - function adds cursor to linked list
**  @param  - t_cursor **head, pointer to head of linked list
**			- t_cursor *new, new cursor to be added
*/

void		add_cursor(t_cursor **head, t_cursor *new)
{
	if (!head)
		return ;
	new->next = *head;
	*head = new;
}
