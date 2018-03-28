//Ë³Ðò±íÄæÖÃ.H
void invert(sequenlist*L)
{
    datatype temp[L->last];
    for(int i = 0;i<L->last;i++)
    {
        temp[i] = L->data[L->last -1 -i];
    }
    for(int i = 0;i<L->last;i++)
    {
        L->data[i] = temp[i];
    }
}
