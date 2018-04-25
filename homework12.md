# Homework of *Data structure*

**Student ID : 15020310015**
[Code transport](https://github.com/Codefiring/Data-structures-learning-in-college) 

## 1.8
(1). n-1
(2). n-1
(6). n
(7). sqrt(n)

## 2.10
```c
Status DeleteK(SqList &a,int i,int k){
    if(i<1||k<0||i+k-1>a.length) return INFEASIBLE;
    for(count=1;i+count-1<=a.length-k;count++) 
        a.elem[i+count-1]=a.elem[i+count+k-1];
    a.length-=k;
    return OK;
}//DeleteK 
```
## 2.11
```c
Status Insert_SqList(SqList &va,int x)
{
    if(va.length+1>va.listsize) return ERROR;
        va.length++;
    for(i=va.length-1;va.elem[i]>x&&i>=0;i--)
        va.elem[i+1]=va.elem[i];
    va.elem[i+1]=x;
    return OK;
}//Insert_SqList
```

## 2.13
```c
LNode* Locate(LinkList L,int x)
{
    for(p=l->next;p&&p->data!=x;p=p->next);
    return p;
}//Locate
```

## 2.14
```c
int Length(LinkList L)
{
    for(k=0,p=L;p->next;p=p->next,k++);
    return k;
}//Length
```

## 2.15
```c
void ListConcat(LinkList ha,LinkList hb,LinkList &hc)
{
    hc=ha;p=ha;
    while(p->next) p=p->next;
    p->next=hb;
}//ListConcat
```

## 2.17
```c
Status Insert(LinkList &L,int i,int b){
    p=L;
    q=(LinkList*)malloc(sizeof(LNode));
    q.data=b;
    if(i==1){
        q.next=p;L=q; 
    }
    else{
        while(--i>1) p=p->next;
        q->next=p->next;
        p->next=q; 
    }
}//Insert
```

##2.19
```c
Status Delete_Between(Linklist &L,int mink,int maxk){
    p=L;
    while(p->next->data<=mink) p=p->next; 
    if(p->next) {
        q=p->next;
        while(q->data<maxk) q=q->next; 
        p->next=q;
    }
}//Delete_Between
```
## 2.20
```c
Status Delete_Equal(Linklist &L){
    p=L->next;
    q=p->next; 
    while(p->next){
        if(p->data!=q->data){
            p=p->next;q=p->next; 
        }
        else{
            while(q->data==p->data){
                free(q);
                q=q->next;
            }
            p->next=q;
            p=q;
            q=p->next;
        }
    }
}//Delete_Equal
```

## 2.24
```c
void reverse_merge(LinkList &A,LinkList &B,LinkList &C){
    pa=A->next;
    pb=B->next;
    pre=NULL;
    while(pa||pb){
        if(pa->data<pb->data||!pb){
            pc=pa;
            q=pa->next;
            pa->next=pre;pa=q; 
        }
        else{
            pc=pb;
            q=pb->next;
            pb->next=pre;
            pb=q; 
        }
    pre=pc;
    }
    C=A;
    A->next=pc; 
}//reverse_merge
```

## 2.26  
```c
void LinkList_Intersect(LinkList A,LinkList B,LinkList &C){
    p=A->next;
    q=B->next;
    pc=(LNode*)malloc(sizeof(LNode));
    C=pc;
    while(p&&q){
        if(p->data<q->data) p=p->next;
        else if(p->data>q->data) q=q->next;
        else{
            s=(LNode*)malloc(sizeof(LNode));
            s->data=p->data;
            pc->next=s;pc=s;
            p=p->next;q=q->next;
        }
    }
}//LinkList_Intersect
```