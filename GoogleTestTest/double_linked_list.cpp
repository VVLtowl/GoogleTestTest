﻿//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "double_linked_list.h"


//==========  ノード構造体 ==========
/**
* @brief	コンストラクタ　
*/
DoubleLinkedList::Node::Node() :
	pPrev(nullptr),
	pNext(nullptr),
	isDummy(false)
{
}

/**
* @brief	コンストラクタ　スコアデータある場合
*/
DoubleLinkedList::Node::Node(int score, const char* name) :
	pPrev(nullptr),
	pNext(nullptr),
	isDummy(false)
{
	scoreData.score = score;
	strcpy(scoreData.name, name);
}


//==========  コンストイテレータ ==========
/**
* @brief	有効なイテレータであるか
* @detail	リストの参照がある、
*			同じリストであることが必要。
*/
bool DoubleLinkedList::ConstIterator::IsVaild(const DoubleLinkedList* const list)
{
	bool hasReference = (m_pNode != nullptr && m_pList != nullptr);//リストの参照があるか
	bool sameList = (m_pList == list);//同じリストであるか

	return hasReference && sameList;
}

/**
* @brief	リストの先頭に向かって一つ進める（前置デクリメント）
* @detail	リストの参照がない場合失敗になる。
*			直前ノードはダミーの場合失敗になる。
*/
DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator--()
{
	assert(m_pNode && m_pList);// リストの参照があるかの確認
	assert(m_pNode->pPrev->isDummy == false);// 直前ノードはダミーではないかの確認

	m_pNode = m_pNode->pPrev;

	return (*this);
}

/**
* @brief	リストの末尾に向かって一つ進める（前置インクリメント）
* @detail	リストの参照がない場合失敗になる。
*			直後ノードはダミーの場合失敗になる。
*/
DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator++()
{
	assert(m_pNode && m_pList);// リストの参照があるかの確認
	assert(m_pNode->pNext->isDummy == false);// 直後ノードはダミーではないかの確認

	m_pNode = m_pNode->pNext;

	return (*this);
}

/**
* @brief	リストの末尾に向かって一つ進める（後置インクリメント）
* @detail	リストの参照がない場合失敗になる。
*			直後ノードはダミーの場合失敗になる。
*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator--(int i)
{
	assert(m_pNode && m_pList);// リストの参照があるかの確認
	assert(m_pNode->pPrev->isDummy == false);// 直後ノードはダミーではないかの確認

	m_pNode = m_pNode->pPrev;

	return (*this);
}

/**
* @brief	リストの末尾に向かって一つ進める（後置インクリメント）
* @detail	リストの参照がない場合失敗になる。
*			直後ノードはダミーの場合失敗になる。
*/
DoubleLinkedList::ConstIterator DoubleLinkedList::ConstIterator::operator++(int i)
{
	assert(m_pNode && m_pList);// リストの参照があるかの確認
	assert(m_pNode->pNext->isDummy == false);// 直後ノードはダミーではないかの確認

	m_pNode = m_pNode->pNext;

	return (*this);
}


/**
* @brief	イテレータの指す要素を取得する(const版)
* @detail	リストの参照がない場合失敗になる。
* 			ノードはダミーの場合失敗になる。
*/
DoubleLinkedList::Node& DoubleLinkedList::ConstIterator::operator*() const
{
	assert(m_pNode && m_pList);// リストの参照があるかの確認
	assert(m_pNode->isDummy == false);

	return (*m_pNode);
}

/**
* @brief	指す要素へのポインタを取得する(const版)
* @detail	リストの参照がない場合失敗になる。
*/
DoubleLinkedList::Node* DoubleLinkedList::ConstIterator::operator&() const
{
	assert(m_pNode && m_pList);// リストの参照があるかの確認

	return m_pNode;
}

/**
* @brief	コピーを行う（コピーコンストラクタ）
* @detail	宣言時、引数、戻り値の3つの動作でコピーがとられた時に実行される。
*/
DoubleLinkedList::ConstIterator::ConstIterator(const ConstIterator& constIter)
{
	m_pNode = constIter.m_pNode;
	m_pList = constIter.m_pList;
}

/**
* @brief	代入を行う
*/
DoubleLinkedList::ConstIterator& DoubleLinkedList::ConstIterator::operator=(const ConstIterator& constIter)
{
	m_pNode = constIter.m_pNode;
	m_pList = constIter.m_pList;

	return *this;
}

/**
* @brief	同一か比較する
*/
bool DoubleLinkedList::ConstIterator::operator==(const ConstIterator& iter)
{
	return m_pNode == iter.m_pNode;
}

/**
* @brief	異なるか比較する
*/
bool DoubleLinkedList::ConstIterator::operator!=(const ConstIterator& iter)
{
	return m_pNode != iter.m_pNode;
}

//==========  イテレータ ==========
/**
* @brief	イテレータの指す要素を取得する(非const版)
* @detail	リストの参照がない場合失敗になる。
* 			ノードはダミーの場合失敗になる。
*/
DoubleLinkedList::Node& DoubleLinkedList::Iterator::operator*()
{
	assert(m_pNode && m_pList);// リストの参照があるかの確認
	assert(m_pNode->isDummy == false);

	return *m_pNode;
}

/**
* @brief	指す要素へのポインタを取得する(非const版)
* @detail	リストの参照がない場合失敗になる。
*/
DoubleLinkedList::Node* DoubleLinkedList::Iterator::operator&()
{
	assert(m_pNode && m_pList);// リストの参照があるかの確認

	return m_pNode;
}

//==========  双方向リスト ==========
/**
* @brief	データを末尾後に追加
* @detail	先頭ノードポインタの指すところが空の場合、新しいノードへ指す。
*			指すところ対象ががある場合、末尾ノードと新ノードを双方向リンクを設定し、
*			末尾ノードポンタを新ノートへ指す。
* @return	追加成功の場合trueを返す
*			追加失敗の場合falseを返す
*/
bool DoubleLinkedList::PushBack(DoubleLinkedList::Node* newNode)
{
	return Insert(CEnd(), newNode);
}
bool DoubleLinkedList::PushBack(int score, const char* name)
{
	return false;
}


/**
* @brief	データ数を取得する
* @detail	ループで加算して、データ数を計算する。
*			constメソッドである。
* @return	データ数を返す
*/
int DoubleLinkedList::Count() const
{
	//要素がない場合、0を返す
	if (HeadNode() == nullptr)
		return 0;

	//データ数計算
	int count = 0;
	Node* node = HeadNode();
	while (node != m_pDummy)
	{
		count++;
		node = node->pNext;
	}
	return count;
}

 /**
 * @brief	データの挿入
 * @detail	リストが空の場合末尾へ挿入、
 *			空ではない場合イテレータが有効であるかを確認、
 *			有効ではない場合、挿入失敗。
 * @return	挿入成功の場合trueを返す
 *			挿入失敗の場合falseを返す
 */
bool DoubleLinkedList::Insert(ConstIterator& positionIter, Node* newNode)
{
	//要素がない場合、挿入失敗
	if (newNode == nullptr)
		return false;

	//if (newNode->pPrev != nullptr ||
	//	newNode->pNext != nullptr)
	//	return false;

	//リストが空の場合末尾へ挿入
	if (Count()==0)
	{
		m_pDummy->pNext = newNode;
		newNode->pPrev = m_pDummy;
		newNode->pNext = m_pDummy;
		m_pDummy->pPrev = newNode;

		return true;
	}

	//イテレータ有効であるかの確認
	if (positionIter.IsVaild(this)==false)
		return false;

	//挿入を行う
	Node* prev = (*positionIter).pPrev;
	Node* next = &positionIter;

	prev->pNext = newNode;
	newNode->pPrev = prev;
	newNode->pNext = next;
	next->pPrev = newNode;
	
	return true;
}

/**
* @brief	データの削除
* @detail	リストが空ではないかの確認、
*			空ではない場合イテレータが有効であるかの確認、
*			有効の場合ダミーではないかの確認。
* @return	削除成功の場合trueを返す
*			削除失敗の場合falseを返す
*/
bool DoubleLinkedList::Remove(ConstIterator& positionIter)
{
	//リストが空の場合、削除失敗
	if (Count() == 0)
		return false;

	//イテレータ有効ではない場合、削除失デクリメント敗インクリメント
	if (positionIter.IsVaild(this)==false)
		return false;

	//ダミーノードを指す場合、削除失敗
	if ((*positionIter).isDummy==true)
		return false;

	//削除を行う
	Node* prev = (*positionIter).pPrev;
	Node* next = (*positionIter).pNext;

	prev->pNext = next;
	next->pPrev = prev;

	return true;
}


/**
* @brief	先頭イテレータ取得する
* @detail	リストが空である場合、ダミーノードを指すイテレータを返す、
*			空ではない場合、先頭ノードを指すイテレータを返す。
* @return
*/
DoubleLinkedList::Iterator DoubleLinkedList::Begin()
{
	//リストが空である場合
	if(Count()==0)
		return Iterator(m_pDummy, this);

	return Iterator(m_pDummy->pNext, this);
}

/**
* @brief	先頭コンストイテレータ取得する
* @detail	リストが空である場合、ダミーノードを指すコンストイテレータを返す
*			空ではない場合、先頭ノードを指すコンストイテレータを返す。
* @return
*/
DoubleLinkedList::ConstIterator DoubleLinkedList::CBegin() const
{
	//リストが空である場合
	if (Count() == 0)
		return ConstIterator(m_pDummy, this);

	return ConstIterator(HeadNode(), this);
}

/**
* @brief	末尾イテレータ取得する
* @detail	ダミーノードを指すイテレータを返す。
* @return
*/
DoubleLinkedList::Iterator DoubleLinkedList::End()
{
	return Iterator(m_pDummy, this);
}

/**
* @brief	末尾イテレータ取得する
* @detail	ダミーノードを指すコンストイテレータを返す。
* @return
*/
DoubleLinkedList::ConstIterator DoubleLinkedList::CEnd() const
{
	return ConstIterator(m_pDummy, this);
}