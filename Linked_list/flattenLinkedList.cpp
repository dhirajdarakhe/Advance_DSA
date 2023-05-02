//     https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
    Node* join(Node* h1, Node* h2)
{     
	  Node* node = new Node(0);
      Node* pre = node;
      while(h1 && h2)
	  {
		  if(h1->data < h2->data)
		  {
			  pre->bottom = h1;
			  h1 = h1->bottom;
		  }
		  else 
		  {
			  pre->bottom = h2;
			  h2 = h2->bottom;
		  }
		  pre = pre->bottom;
	  }
	  if(h1) pre->bottom = h1;
	  if(h2) pre->bottom = h2;
	  return node->bottom;
}
Node* flatten(Node* head) 
{
	// Write your code here
	if(head == NULL || head->next == NULL) return head;
	head->next = flatten(head->next);
	return join(head, head->next);
}
