#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct ListNode {
	int data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insertNode(ListNode **phead, ListNode *p, ListNode *new_node) //집합에 원소 삽입
{
	if (*phead == NULL)
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL)
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

void removeNode(ListNode **phead, ListNode *p, ListNode *removed) //집합에 원소 삭제
{
	if (p == NULL)
	{
		*phead = (*phead)->link;
	}
	else
	{
		p->link = removed->link;
	}

	free(removed);
}

ListNode* unionNode(ListNode *head1, ListNode *head2) //합집합
{
	int flag = 0;
	ListNode *p = head1, *q = head2, *r = NULL;
	
	while (p->link != NULL)
	{
		p = p->link;
	}
	while (q != NULL)
	{
		r = head1;
		while (r != NULL)
		{
			if (r->data == q->data) //값이 같으면 나가기
			{
				flag = 1;
				break;
			}
			r = r->link;
		}
		if (flag == 1)
		{
			q = q->link;
			flag = 0;
		}
		else
		{
			p->link = q;
			p = p->link;
			q = q->link;
			p->link = NULL;
		}
	}
	return head1;
}

ListNode* intersectionNode(ListNode *head1, ListNode *head2) //교집합
{
	int flag = 0;
	ListNode *head = NULL;
	ListNode *p = head1, *q = head2, *r = NULL, *temp = NULL;

	while (q != NULL)
	{
		p = head1;
		while (p != NULL)
		{
			if (p->data == q->data)
			{
				flag = 1;
				break;
			}
			p = p->link;
		}
		if (flag == 1)
		{
			temp = (ListNode*)malloc(sizeof(ListNode));
			temp->data = q->data;
			temp->link = NULL;
			if (head == NULL)
			{
				head = temp;
			}
			else
			{
				r = head;
				while (r->link != NULL)
				{
					r = r->link;
				}
				r->link = temp;
			}
			q = q->link;
			flag = 0;
		}
		else
		{
			q = q->link;
		}
	}
	return head;
}

ListNode *diffSetNode(ListNode *head1, ListNode *head2) //차집합
{
	int flag = 0, cnt = 0;
	ListNode *p = head1, *q = head2, *r = NULL, *save = NULL, *temp = NULL;

	save = (ListNode*)malloc(sizeof(ListNode));

	while (p->link != NULL)
	{
		p = p->link;
	}
	while (q != NULL)
	{
		r = head1;
		cnt = 0;
		while (r != NULL)
		{
			cnt++;
			if (r->data == q->data)
			{
				if (cnt == 1)
				{
					save = r;
					break;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			save = r;
			r = r->link;
		}

		if (cnt == 1)
		{
			//첫번째 예외처리
		}

		if (flag == 1) //같을때 p에 해당하는 리스트를 삭제해야함.
		{
			
			
			flag = 0;
		}
		else
		{

		}
	}
}
void subsetNode(); //부분집합

void display(ListNode *head, char* description) //출력
{
	ListNode *p = head;
	printf("%s", description);
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

ListNode *create_node(int data, ListNode *link) //노드 생성
{
	ListNode *new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) error("메모리 할당 에러");
	new_node->data = data;
	new_node->link = link;

	return(new_node);
}

main()
{
	ListNode *list1 = NULL, *list2 = NULL; //집합1, 집합2
	ListNode *unionSet = NULL, *intersectionSet = NULL;

	insertNode(&list1, NULL, create_node(27, NULL)); //집합1의 원소들
	insertNode(&list1, NULL, create_node(51, NULL));
	insertNode(&list1, NULL, create_node(32, NULL));
	insertNode(&list1, NULL, create_node(39, NULL));
	display(list1, "집합1의 원소들 : ");

	insertNode(&list2, NULL, create_node(51, NULL)); //집합2의 원소들
	insertNode(&list2, NULL, create_node(39, NULL));
	insertNode(&list2, NULL, create_node(77, NULL));
	insertNode(&list2, NULL, create_node(6, NULL));
	display(list2, "집합2의 원소들 :");

	removeNode(&list2, NULL, list2); //원소 삭제
	display(list2, "집합2에서 원소 삭제 : ");

	//unionSet = unionNode(list1, list2);
	//display(unionSet,"합집합 : ");
	
	//intersectionSet = intersectionNode(list1, list2);
	//display(intersectionSet, "교집합 : ");

	system("pause");
}