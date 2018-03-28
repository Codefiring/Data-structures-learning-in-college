#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct PolyNode* Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};

void InitPoly(Polynomial poly)
{
	poly->coef = 0;
	poly->expon = 0;
	poly->link = NULL;
}
 
void Polyadd(Polynomial poly, int coef, int expon)
{
	Polynomial s ;
	s = malloc(sizeof(Polynomial));
	s->coef = coef;
	s->expon = expon;
	s->link = NULL;
	poly->link = s;
}

int main()
{
	Polynomial poly1, poly2;
	Polynomial *p1, *p2;
	p1 = &poly1;
	p2 = &poly2;
	poly1 = malloc(sizeof(Polynomial));
	poly2 = malloc(sizeof(Polynomial));
	int poly1Num, poly2Num;
	InitPoly(poly1);
	InitPoly(poly2);
	int coef;
	int expon;
	
	scanf("%d", &poly1Num);
	for (int i = 0; i < poly1Num; i++)
	{
		scanf("%d %d", &coef,&expon);
		
		Polyadd(poly1, coef, expon);
	}

	return 0;

}