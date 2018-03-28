//Êä³öµ¥Á´±í.h
void printlink(linklist*head)
{  linklist *p=head->next;
   while(p!=NULL)
   {  cout<<p->data;
      p=p->next;
   }
   cout<<endl;
}