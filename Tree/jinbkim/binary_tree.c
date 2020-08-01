#include <stdio.h>
#include <stdlib.h>

#define	NODE_MAX	7

typedef	int	bt_data;

typedef	struct			s_bt_node
{
	bt_data				data;
	struct s_bt_node	*left;
	struct s_bt_node	*right;
}						t_bt_node;

typedef	void (*show_func)(int);



t_bt_node	*make_bt_node(bt_data data)
{
	t_bt_node	*node;

	node = (t_bt_node *)malloc(sizeof(t_bt_node));
	node->data = data;

	node->left = NULL;
	node->right = NULL;
	return (node);
}

void		make_left_sub_free(t_bt_node *parent, t_bt_node *child)
{
	if (parent->left)
		free(parent->left);
	parent->left = child;
}

void		make_right_sub_free(t_bt_node *parent, t_bt_node *child)
{
	if (parent->right)
		free(parent->right);
	parent->right = child;
}

void		show_data(int data)
{
	printf("%d ", data);
}

void		preorder_traverse(t_bt_node *node, show_func f)
{
	if (!node)
		return ;
	f(node->data);
	preorder_traverse(node->left, f);
	preorder_traverse(node->right, f);
}

void		inorder_traverse(t_bt_node *node, show_func f)
{
	if (!node)
		return ;
	inorder_traverse(node->left, f);
	f(node->data);
	inorder_traverse(node->right, f);
}

void		postorder_traverse(t_bt_node *node, show_func f)
{
	if (!node)
		return ;
	postorder_traverse(node->left, f);
	postorder_traverse(node->right, f);
	f(node->data);
}

void		delete_tree(t_bt_node *node)
{
	if (!node)
		return ;
	delete_tree(node->left);
	delete_tree(node->right);
	free(node);
}



int			main(void)
{
	t_bt_node	**node;
	int			i;

	node = (t_bt_node **)malloc(sizeof(t_bt_node *) * NODE_MAX);
	i = -1;
	while (++i < NODE_MAX)
		node[i] = make_bt_node(i);
	
	make_left_sub_free(node[0], node[1]);
	make_right_sub_free(node[0], node[2]);
	make_left_sub_free(node[1], node[3]);
	make_right_sub_free(node[1], node[4]);
	make_left_sub_free(node[2], node[5]);
	make_right_sub_free(node[2], node[6]);

	printf("----- preorder traverse -----\n");
	preorder_traverse(node[0], show_data);
	printf("\n");
	printf("----- inorder traverse -----\n");
	inorder_traverse(node[0], show_data);
	printf("\n");
	printf("----- postorder traverse -----\n");
	postorder_traverse(node[0], show_data);
	printf("\n");

	delete_tree(node[0]);
	free(node);
}