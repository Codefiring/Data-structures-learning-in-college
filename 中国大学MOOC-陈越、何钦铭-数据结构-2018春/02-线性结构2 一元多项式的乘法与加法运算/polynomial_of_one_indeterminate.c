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
	s = (Polynomial)malloc(sizeof(PolyNode));
	InitPoly(s);

	while (poly->link!=NULL)	poly = poly->link;		
	s->coef = coef;
	s->expon = expon;
	s->link = NULL;
	poly->link = s;
}

int PolyShow(Polynomial poly)
{
	if (poly->link == NULL)return 0;
	else poly = poly->link;

	while (poly->link != NULL)
	{
		printf("%d %d ", poly->coef, poly->expon);
		poly = poly->link;
	}
	printf("%d %d\n", poly->coef, poly->expon);
	return 0;
}

//static void swap_ids(Polynomial a, Polynomial b)
//{
//	const int a_id = a->id;
//
//	a->id = b->id;
//	b->id = a_id;
//}

int PolySort(Polynomial poly)
{
	if (poly == NULL)return 0;
	poly = poly->link;
	int flag = 1;
	Polynomial r;	
	r = (Polynomial)malloc(sizeof(PolyNode));
	//int cur_count = 0, max_count = 0;
	r = poly;
	while (flag)
	{
		poly = r;
		int count = 0, num_count = 0;
		while (poly->link != NULL)
		{
			num_count++;
			flag = 1;
			if (poly->expon == poly->link->expon)
			{
				poly->coef = poly->coef + poly->link->coef;
				poly->link = poly->link->link;
				poly = poly->link;
				flag = 0;
			}
			else if (poly->expon < poly->link->expon)
			{
				int expon_temp, coef_temp;
				expon_temp = poly->expon;
				poly->expon = poly->link->expon;
				poly->link->expon = expon_temp;

				coef_temp = poly->coef;
				poly->coef = poly->link->coef;
				poly->link->coef = coef_temp;
				flag = 0;

				poly = poly->link;
			}
			else
			{
				poly = poly->link;
				count++;
				
			}
		}
		if (count == num_count) break;
		

	}
	poly = r;
	return 0;
}

void PolyAdd(Polynomial p1, Polynomial p2, Polynomial polyAdd)
{
	Polynomial poly1,poly2;
	poly1 = (Polynomial)malloc(sizeof(PolyNode));
	poly2 = (Polynomial)malloc(sizeof(PolyNode));
	InitPoly(poly1);
	InitPoly(poly2);

	poly1 = p1->link;
	poly2 = p2->link;

	if(poly1!=NULL&&poly1!=NULL)
	{

		while ((poly1 != NULL) && (poly2 != NULL))
		{
			while (polyAdd->link != NULL)polyAdd = polyAdd->link;
			if (poly1->expon > poly2->expon)
			{
				polyAdd->link = poly1;
				poly1 = poly1->link;
				polyAdd->link->link = NULL;
			}
			else if (poly1->expon == poly2->expon) 
			{
				polyAdd->link = poly1;
				polyAdd->link->coef = poly1->coef + poly2->coef;
				poly1 = poly1->link;
				polyAdd->link->link = NULL;
				poly2 = poly2->link;
			}
			else if (poly1->expon < poly2->expon)
			{
				polyAdd->link = poly2;
				poly2 = poly2->link;
				polyAdd->link->link = NULL;
			}
		}
		if (poly1 == NULL) polyAdd->link->link = poly2;
		else polyAdd->link->link = poly1;
	}
	else if (poly1 == NULL) polyAdd = poly2;
	else polyAdd = poly1;
}

void PolyMulti(Polynomial poly1, Polynomial poly2, Polynomial polyMulti)
{
	poly1 = poly1->link;
	poly2 = poly2->link;
	Polynomial temp,r;
	r = (Polynomial)malloc(sizeof(PolyNode));
	InitPoly(r);
	r = poly2;

	if (poly1 != NULL&&poly2 != NULL)
	{
		while(poly1 != NULL)
		{
			poly2 = r;
			while (poly2 != NULL)
			{
				while (polyMulti->link != NULL)polyMulti = polyMulti->link;
				temp = (Polynomial)malloc(sizeof(PolyNode));
				InitPoly(temp);
				temp->coef = poly1->coef * poly2->coef;
				temp->expon = poly1->expon + poly2->expon;
				temp->link = NULL;
				polyMulti->link = temp;
				polyMulti->link->link = NULL;
				poly2 = poly2->link;
			}
			poly1 = poly1->link;
			
		}
	}
	else InitPoly(polyMulti) ;
}

void PolyCheck(Polynomial poly)
{
	poly = poly->link;
	while (poly->link != NULL)
	{
		if (poly->link->coef == 0)
		{
			poly->link = poly->link->link;
		}
		poly = poly->link;
	}

}

int main()
{
	Polynomial poly1, poly2;
	Polynomial polyAdd, polyMulti;

	poly1 = (Polynomial)malloc(sizeof(PolyNode));
	poly2 = (Polynomial)malloc(sizeof(PolyNode));
	polyAdd = (Polynomial)malloc(sizeof(PolyNode));
	polyMulti = (Polynomial)malloc(sizeof(PolyNode));

	InitPoly(poly1);
	InitPoly(poly2);
	InitPoly(polyAdd);
	InitPoly(polyMulti);
	int poly1Num, poly2Num;
	int coef;
	int expon;
	
	scanf("%d", &poly1Num);
	if (poly1Num) 
	{
		for (int i = 0; i < poly1Num; i++)
		{
			scanf("%d %d", &coef,&expon);		
			PolyCreateAdd(poly1, coef, expon);
		}
	}

	scanf("%d", &poly2Num);
	if (poly2Num) 
	{
		for (int i = 0; i < poly2Num; i++)
		{
			scanf("%d %d", &coef, &expon);
			PolyCreateAdd(poly2, coef, expon);
		}
	}

	if (poly1 == NULL || poly2 == NULL) 
	{
		printf("%d %d\n", 0, 0);
	}
	else
	{
		PolyMulti(poly1, poly2, polyMulti);
		PolySort(polyMulti);
		PolyCheck(polyMulti);
		PolyShow(polyMulti);
	}

	if (poly1 != NULL&&poly2 != NULL) 
	{
		PolyAdd(poly1, poly2, polyAdd);
		PolyCheck(polyAdd);
		PolyShow(polyAdd);
	}
	else if (poly1 == NULL&&poly2 == NULL)
		printf("%d %d\n", 0, 0);
	else if (poly1 == NULL)
		PolyShow(poly2);
	else if(poly2 == NULL)
		PolyShow(poly1);

	return 0;

}