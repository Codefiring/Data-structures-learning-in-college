#pragma once
void resolve(linklist *head, linklist *&letter, linklist *&digit, linklist *&other)
{
	linklist *p = head->next,*t;
	head->next = NULL;
	while (p != NULL)
	{
		t = p;
		p = p->next;
		if (t->data >= '0'&&t->data <= '9')
			insert(digit, t);
		else if ((t->data >= 'a'&&t->data <= 'z') || (t->data >= 'A'&&t->data <= 'Z'))
			insert(letter, t);
		else insert(other, t);
			
	}

}