void SLLDestroy(node_t **node)
{	
	node_t *tmp1 = NULL;
	node_t *tmp2 = NULL; 
	tmp1 = *node;

	assert(NULL != node);

	while (NULL != tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(*node);
	*node = NULL;
}
