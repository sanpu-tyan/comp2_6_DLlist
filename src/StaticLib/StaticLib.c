#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
	p->pNext = l->header;
	p->pPrev = NULL;
	if (l->header) 
		l->header->pPrev = p;
	else
		l->footer = p;

	l->header = p;
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	p->pPrev = l->footer;
	p->pNext=NULL;
	if (l->footer)
		l->footer->pNext = p;
	else
		l->header = p;
	l->footer = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (p->pPrev) {
		p->pPrev->pNext = p->pNext;
	}
	else
		l->header=p->pNext;

	if (p->pNext)
		p->pNext->pPrev = p->pPrev;
	else
		l->footer = p->pPrev;

	p->pPrev = NULL;
	p->pNext = NULL;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (!p || !p->pNext) return;

	node* n = p->pNext;
	p->pNext = n->pNext;
	if (n->pNext) {
		n->pNext->pPrev = p;
	}
	else
		l->footer = p;

	n->pNext = NULL;
	n->pPrev = NULL;
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (!p || !p->pPrev) return;
	node* n = p->pPrev;
	p->pPrev = n->pPrev;
	if (n->pPrev) {
	     n->pPrev->pNext=p;		
	}
	else
		l->header = p;

	n->pPrev = NULL;
	n->pNext = NULL;
}


// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
	if (!p) return NULL;
	return p->pPrev;

	return NULL;
}
