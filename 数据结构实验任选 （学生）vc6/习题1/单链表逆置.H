//µ¥Á´±íÄæÖÃ.h
void invert(linklist* &head)
{
    linklist *temp = NULL;
    linklist *pre = NULL;

	head = head->next;
    while(head != NULL)
    {
        temp = head->next;
        head->next = pre;
        pre = head;
        head = temp;
    }
	head = pre;
}
