void print2(linklist*head)
//Êä³öÑ­»·Á´±í
{  linklist *p=head->next;
   while(p!=head)
   {  cout<<p->data;
      p=p->next;
   }
   cout<<endl;
}
