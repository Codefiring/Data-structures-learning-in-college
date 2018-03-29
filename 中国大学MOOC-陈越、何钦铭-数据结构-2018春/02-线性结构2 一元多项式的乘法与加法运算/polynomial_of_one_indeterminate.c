#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct PolyNode* Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
}PolyNode;

void InitPoly(Polynomial poly)
{
	poly->coef = 0;
	poly->expon = 0;
	poly->link = NULL;
}
 
void PolyCreateAdd(Polynomial poly, int coef, int expon)
{
	Polynomial s;
	s = (Polynomial*)malloc(sizeof(PolyNode));

	while (poly->link!=NULL)	poly = poly->link;		
	s->coef = coef;
	s->expon = expon;
	s->link = NULL;
	poly->link = s;
}

Polynomial PolyAdd(Polynomial poly1, Polynomial poly2)
{
	Polynomial polyAdd,temp;
	polyAdd = (Polynomial*)malloc(sizeof(PolyNode));
	temp = (Polynomial*)malloc(sizeof(PolyNode));
		poly1 = poly1->link;
		poly2 = poly2->link;

	while ((poly1->link != NULL) && (poly2->link != NULL))
	{
		if (poly1->expon > poly2->expon)
		{
			temp->coef = poly1->coef;
			temp->expon = poly1->expon;
			temp->link = polyAdd->link;
			polyAdd->link = temp;
			poly1 = poly1->link;
		}
		else if (poly1->expon = poly2->expon) 
		{
			temp->coef = poly1->coef + poly2->coef;
			temp->expon = poly1->expon;
			temp->link = polyAdd->link;
			polyAdd->link = temp;
			poly1 = poly1->link;
			poly2 = poly2->link;
		}
		else if (poly1->expon < poly2->expon)
		{
			temp->coef = poly2->coef;
			temp->expon = poly2->expon;
			temp->link = polyAdd->link;
			polyAdd->link = temp;
			poly2 = poly2->link;
		}
		polyAdd = polyAdd->link;
	}
	return polyAdd;
}


int main()
{
	Polynomial poly1, poly2;
	Polynomial polyAdd, polyMulti;

	poly1 = (Polynomial*)malloc(sizeof(PolyNode));
	poly2 = (Polynomial*)malloc(sizeof(PolyNode));
	polyAdd = (Polynomial*)malloc(sizeof(PolyNode));
	polyMulti = (Polynomial*)malloc(sizeof(PolyNode));

	int poly1Num, poly2Num;
	InitPoly(poly1);
	InitPoly(poly2);
	int coef;
	int expon;
	
	scanf("%d", &poly1Num);
	for (int i = 0; i < poly1Num; i++)
	{
		scanf("%d %d", &coef,&expon);		
		PolyCreateAdd(poly1, coef, expon);
	}

	scanf("%d", &poly2Num);
	for (int i = 0; i < poly2Num; i++)
	{
		scanf("%d %d", &coef, &expon);
		PolyCreateAdd(poly2, coef, expon);
	}

	polyAdd = PolyAdd(poly1, poly2);


	return 0;

}