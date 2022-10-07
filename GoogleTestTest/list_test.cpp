#include "pch.h"
#include "double_linked_list.h"

/**双方向リストの単体テスト*/
#define GT_TEST_DOUBLE_LINKED_LIST

//=================================== 双方向リスト単体テストの自動テスト ===================================
namespace doubleLinkedList_test
{
#if defined GT_TEST_DOUBLE_LINKED_LIST
	//=================================== データ数の取得のテスト ===================================
	namespace list_count_test
	{
		/**
		* @brief		リストが空である場合の戻り値
		* @detail		ID:0-0
		* 				リストが空である場合、
		*				データ数の取得関数の戻り値を確認します。
		*				戻り値が0の場合成功です。
		*/
		TEST(ListCountTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_EQ(0, list.Count());
		}

		/**
		* @brief		リスト末尾への挿入を行った際の戻り値
		* @detail		ID:0-1
		* 				リスト末尾への挿入を行った際に、
		*				データ数の取得関数の戻り値を確認します。
		*				戻り値が1の場合成功です。
		*/
		TEST(ListCountTest, WhenPushBackSucceed)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			EXPECT_TRUE(list.PushBack(&node));
			EXPECT_EQ(1, list.Count());
		}

		/**
		* @brief		リスト末尾への挿入が失敗した際の戻り値
		* @detail		ID:0-2
		* 				リスト末尾への挿入が失敗した際に、
		*				データ数の取得関数の戻り値を確認します。
		*				戻り値が0の場合成功です。
		*/
		TEST(ListCountTest, WhenPushBackFailed)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node* node = nullptr;
			EXPECT_FALSE(list.PushBack(node));
			EXPECT_EQ(0, list.Count());
		}

		/**
		* @brief		データの挿入を行った際の戻り値
		* @detail		ID:0-3
		* 				データの挿入を行った際に、
		*				データ数の取得関数の戻り値を確認します。
		*				戻り値が1の場合成功です。
		*/
		TEST(ListCountTest, WhenInsertSucceed)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node node;
			EXPECT_TRUE(list.Insert(head, &node));
			EXPECT_EQ(1, list.Count());
		}

		/**
		* @brief		データの挿入に失敗した際の戻り値
		* @detail		ID:0-4
		* 				データの挿入に失敗した際に、
		*				データ数の取得関数の戻り値を確認します。
		*				戻り値が0の場合成功です。
		*/
		TEST(ListCountTest, WhenInsertFailed)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node* node = nullptr;
			EXPECT_FALSE(list.Insert(head, node));
			EXPECT_EQ(0, list.Count());
		}

		/**
		* @brief		データの削除を行った際の戻り値
		* @detail		ID:0-5
		* 				データの削除を行った際に、
		*				データ数の取得関数の戻り値を確認します。
		*				戻り値が0の場合成功です。
		*/
		TEST(ListCountTest, WhenRemoveSucceed)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			DoubleLinkedList::Iterator head = list.Begin();
			EXPECT_TRUE(list.Remove(head));
			EXPECT_EQ(0, list.Count());
		}

		/**
		* @brief		データの削除が失敗した際の戻り値
		* @detail		ID:0-6
		* 				データを挿入した後、削除した場合、削除が失敗した際に、
		*				データ数の取得取得関数の戻り値を確認します。
		*				戻り値が1の場合成功です。
		*/
		TEST(ListCountTest, WhenRemoveFailed)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			DoubleLinkedList::Iterator wrong(nullptr, nullptr); //削除の失敗を起こすための、リストに存在しない要素を
			EXPECT_FALSE(list.Remove(wrong));
			EXPECT_EQ(1, list.Count());
		}

		/**
		* @brief		リストが空である場合に、データの削除を行った際の戻り値
		* @detail		ID:0-7
		*				マイナスにならないかを確認するため、
		* 				リストが空である場合に、データの削除を行った際に、
		*				データ数の取得関数の戻り値を確認します。
		*				戻り値が0の場合成功です。
		*/
		TEST(ListCountTest, WhenEmptyListAndRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter=list.End();
			EXPECT_FALSE(list.Remove(iter));
			EXPECT_EQ(0, list.Count());
		}
	}
	//=================================== データの挿入のテスト ===================================
	namespace list_insert_test
	{
		/**
		* @brief		リストが空である場合に、挿入した際の挙動
		* @detail		ID:0-9
		* 				リストが空である場合に、新要素をイテレータの指す位置に挿入します。
		*				先頭イテレータ、末尾イテレータを引数で渡した場合について、個別に挙動をチェックします。
		*				データの挿入関数の戻り値を確認します。
		*				戻り値がtrueの場合成功です。
		*/
		TEST(ListInsertTest, WhenEmptyList)
		{
		
			DoubleLinkedList list1;
			DoubleLinkedList::Iterator head = list1.Begin();
			DoubleLinkedList::Node node1;
			EXPECT_TRUE(list1.Insert(head, &node1));

			DoubleLinkedList list2;
			DoubleLinkedList::Iterator tail = list2.End();
			DoubleLinkedList::Node node2;
			EXPECT_TRUE(list2.Insert(tail, &node2));
		}

		/**
		* @brief		リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動
		* @detail		ID:0-10
		* 				リストに複数の要素がある場合に、先頭イテレータを渡して、挿入します。
		*				先頭に要素が挿入され、元々先頭だった要素が２番目になります。
		*				データの挿入関数の戻り値を確認します。
		*				戻り値がtrueの場合成功です。
		*/
		TEST(ListInsertTest, WhenNotEmptyList_InsertToHead)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1;
			list.PushBack(&node1);

			DoubleLinkedList::Node newNode;
			DoubleLinkedList::Iterator head = list.Begin();
			EXPECT_TRUE(list.Insert(head, &newNode));

			DoubleLinkedList::Iterator iter = list.Begin();
			EXPECT_TRUE((&(++iter)) == &node1);//元々先頭だった要素が２番目になってるか
		}

		/**
		* @brief		リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動
		* @detail		ID:0-11
		* 				リストに複数の要素がある場合に、末尾イテレータを渡して、挿入します。
		*				イテレータの指す位置に要素が挿入されます。
		*				データの挿入関数の戻り値を確認します。
		*				戻り値がtrueの場合成功です。
		*/
		TEST(ListInsertTest, WhenNotEmptyList_InsertToTail)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1;
			list.PushBack(&node1);

			DoubleLinkedList::Node newNode;
			DoubleLinkedList::Iterator tail = list.End();
			EXPECT_TRUE(list.Insert(tail, &newNode));
		}

		/**
		* @brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動
		* @detail		ID:0-12
		* 				リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して、挿入します。
		*				イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれます。
		*				データの挿入関数の戻り値を確認します。
		*				戻り値がtrueの場合成功です。
		*/
		TEST(ListInsertTest, WhenNotEmptyList_InsertToMiddle)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Node newNode;
			DoubleLinkedList::Iterator middle(&node2, &list);
			EXPECT_TRUE(list.Insert(middle, &newNode));
		}

		/**
		* @brief		ConstIteratorを指定して挿入を行った際の挙動
		* @detail		ID:0-13
		* 				ConstIteratorを指定して、挿入します。
		*				イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれます。
		*				データの挿入関数の戻り値を確認します。
		*				戻り値がtrueの場合成功です。
		* 
		*				格納済みの要素に影響がないか、期待される位置に要素が格納されているか。
		*				要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。
		*/
		TEST(ListInsertTest, WhenNotEmptyList_InsertByConstIterator)
		{
			DoubleLinkedList listA;
			DoubleLinkedList::Node node1, node2;
			listA.PushBack(&node1);
			listA.PushBack(&node2);

			DoubleLinkedList::ConstIterator  constHead = listA.CBegin();
			DoubleLinkedList::Node newNode1;
			EXPECT_TRUE(listA.Insert(constHead, &newNode1));

			DoubleLinkedList::ConstIterator  constMiddle(&node2, &listA);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(listA.Insert(constMiddle, &newNode2));

			DoubleLinkedList::ConstIterator  constTail = listA.CEnd();
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(listA.Insert(constTail, &newNode3));

		}

		/**
		* @brief		不正なイテレータを渡して、挿入した場合の挙動
		* @detail		ID:0-14
		* 				リストの参照がないイテレータ、別リストの要素を指すイテレータを渡した際の挙動などを確認します。
		*				リストの参照がないイテレータを指定したり、
		*				別リストの要素を指すイテレータを渡したりして、挿入します。
		*				イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれます。
		*				データの挿入関数の戻り値を確認します。
		*				戻り値がtrueの場合成功です。
		*
		*/
		TEST(ListInsertTest, WhenNotEmptyList_InsertWrongIterator)
		{
			DoubleLinkedList listA;
			DoubleLinkedList::Node node1, node2;
			listA.PushBack(&node1);
			listA.PushBack(&node2);

			DoubleLinkedList listB;				//別リスト
			DoubleLinkedList::Node node3;		//別リストの要素
			EXPECT_TRUE(listB.PushBack(&node3));

			DoubleLinkedList::Iterator noReference(nullptr, nullptr);//リストの参照がないイテレータ
			DoubleLinkedList::Node newNode1;
			EXPECT_FALSE(listA.Insert(noReference, &newNode1));

			DoubleLinkedList::Iterator wrongList(&node3,&listB);//別リストの要素を指すイテレータ
			DoubleLinkedList::Node newNode2;
			EXPECT_FALSE(listA.Insert(wrongList, &newNode2));
		}
	}
	//=================================== データの削除のテスト ===================================
	namespace list_remove_test 
	{
		/**
		* @brief		リストが空である場合に、削除した際の挙動
		* @detail		ID:0-16
		* 				リストが空である場合に、新要素をイテレータの指す位置に挿入します。
		*				イテレータの指す位置に要素が挿入されその位置にあった要素が後ろにずれる。
		*				データの削除関数の戻り値を確認します。
		*				戻り値がfalseの場合成功です。
		*/
		TEST(ListRemoveTest, WhenEmptyList)
		{
			DoubleLinkedList list1;
			DoubleLinkedList::Iterator head = list1.Begin();
			EXPECT_FALSE(list1.Remove(head));

			DoubleLinkedList list2;
			DoubleLinkedList::Iterator tail = list2.End();
			EXPECT_FALSE(list2.Remove(tail));
		}

		/**
		* @brief		先頭要素の削除の挙動
		* @detail		ID:0-17
		* 				リストに複数の要素がある場合に、先頭イテレータを渡して、削除します。
		*				先頭要素が削除されたかを確認します。
		*				データの削除関数の戻り値を確認します。
		*				戻り値がtrueの場合成功です。
		*/
		TEST(ListRemoveTest, WhenNotEmptyList_RemoveHead)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			DoubleLinkedList::Iterator head = list.Begin();
			EXPECT_TRUE(list.Remove(head));
		}

		/**
		* @brief		末尾要素を削除した際の挙動
		* @detail		ID:0-18
		* 				リストに複数の要素がある場合に、末尾イテレータを渡して、削除します。
		*				末尾はダミーノードなので、削除は失敗するはずです。
		*				データの削除関数の戻り値を確認します。
		*				戻り値がfalseの場合成功です。
		*/
		TEST(ListRemoveTest, WhenNotEmptyList_RemoveDumy)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			DoubleLinkedList::Iterator tail = list.End();
			EXPECT_FALSE(list.Remove(tail));
		}

		/**
		* @brief		中間要素を削除した際の挙動
		* @detail		ID:0-19
		* 				リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際に、
		*				イテレータに指された要素が削除されたかを確認します。
		*				データの削除関数の戻り値を確認します。
		*				戻り値がtrueの場合成功です。
		*/
		TEST(ListRemoveTest, WhenNotEmptyList_RemoveMiddle)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Iterator middle(&node2, &list);
			EXPECT_TRUE(list.Remove(middle));
		}

		/**
		* @brief		ConstIteratorを指定して削除を行った際の挙動
		* @detail		ID:0-20
		* 				リストに複数の要素がある場合に、ConstIteratorを指定してした際に、
		*				ConstIteratorに指された要素が削除されたかを確認します。
		*				データの削除関数の戻り値を確認します。
		*				戻り値がtrueの場合成功です。
		*/
		TEST(ListRemoveTest, WhenNotEmptyList_RemoveByConstIterator)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::ConstIterator constMiddle(&node2, &list);
			EXPECT_TRUE(list.Remove(constMiddle));
		}

		/**
		* @brief		不正なイテレータを渡して、削除した場合の挙動
		* @detail		ID:0-21
		* 				リストの参照がないイテレータ、別リストの要素を指すイテレータなど
		*				不正なイテレータを渡した際に、
		*				データの削除関数の戻り値を確認します。
		*				戻り値がfalseの場合成功です。
		*/
		TEST(ListRemoveTest, WhenNotEmptyList_RemoveByWrongIterator)
		{
			DoubleLinkedList listA;
			DoubleLinkedList::Node node1, node2;
			listA.PushBack(&node1);
			listA.PushBack(&node2);

			DoubleLinkedList listB;			//別リスト
			DoubleLinkedList::Node node3;	//別リストの要素
			listB.PushBack(&node3);

			DoubleLinkedList::Iterator noReference(nullptr, nullptr);//リストの参照がないイテレータ
			EXPECT_FALSE(listA.Remove(noReference));

			DoubleLinkedList::Iterator wrongList(&node3, &listB);//別リストの要素を指すイテレータ
			EXPECT_FALSE(listA.Remove(wrongList));
		}
	}
	//=================================== 先頭イテレータの取得のテスト ===================================
	namespace list_begin_test 
	{
		/**
		* @brief		リストが空である場合に、呼び出した際の挙動
		* @detail		ID:0-23
		* 				リストが空である場合に、呼び出した際に、
		*				戻り値はダミーノードを指すイテレータの場合成功です。
		*/
		TEST(ListBeginTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_TRUE((&list.Begin())->isDummy);
		}

		/**
		* @brief		リストに要素が一つある場合に、呼び出した際の挙動
		* @detail		ID:0-24
		* 				リストに要素が一つある場合に、呼び出した際に、
		*				先頭要素を指すイテレータが返る場合成功です。
		*/
		TEST(ListBeginTest, WhenOneElementList)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			EXPECT_EQ(1, list.Count());
			EXPECT_TRUE((&node) == (&list.Begin()));
		}

		/**
		* @brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
		* @detail		ID:0-25
		* 				リストに二つ以上の要素がある場合に、呼び出した際に、
		*				先頭要素を指すイテレータが返る場合成功です。
		*/
		TEST(ListBeginTest, WhenManyElementsList)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1,node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			EXPECT_LE(2, list.Count());
			EXPECT_TRUE((&node1) == (&list.Begin()));
		}

		/**
		* @brief		データの挿入を行った後に、呼び出した際の挙動
		* @detail		ID:0-26
		* 				データの挿入を行った後に、呼び出した際に、
		*				先頭要素を指すイテレータが返る場合成功です。
		*				要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。
		*/
		TEST(ListBeginTest, AfterInsert)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			/**先頭に挿入*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node headNode;
			EXPECT_TRUE(list.Insert(head, &headNode));
			EXPECT_TRUE((&headNode) == (&list.Begin()));

			/**中央に挿入*/
			DoubleLinkedList::Iterator middle(&node2,&list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Insert(middle, &newNode2));
			EXPECT_TRUE((&headNode) == (&list.Begin()));

			/**末尾に挿入*/
			DoubleLinkedList::Iterator tail = list.End();
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Insert(tail, &newNode3));
			EXPECT_TRUE((&headNode) == (&list.Begin()));
		}

		/**
		* @brief		データの削除を行った後に、呼び出した際の挙動
		* @detail		ID:0-27
		* 				データの削除を行った後に、呼び出した際に、
		*				先頭要素を指すイテレータが返る場合成功です。
		*				要素列の先頭、中央、末尾に削除を行った場合の各ケースについてチェックします。
		*/
		TEST(ListBeginTest, AfterRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3, node4;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);
			list.PushBack(&node4);

			/**末尾要素を削除*/
			DoubleLinkedList::Iterator last = list.End();/**ダミーノード*/
			--last;/**末尾ノード*/
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Remove(last));
			EXPECT_TRUE((&node1) == (&list.Begin()));

			/**中央を削除*/
			DoubleLinkedList::Iterator middle(&node3, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Remove(middle));
			EXPECT_TRUE((&node1) == (&list.Begin()));

			/**先頭を削除*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			EXPECT_TRUE(list.Remove(head));
			EXPECT_TRUE((&node2) == (&list.Begin()));
		}

		/**
		* @brief		constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
		* @detail		ID:0-28
		* 				constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
		*				手動テスト
		*/
		/*TEST(ListBeginTest, NotConst)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);
			const DoubleLinkedList constList = list;
		}*/
	}
	//=================================== 先頭コンストイテレータの取得のテスト ===================================
	namespace list_constBegin_test
	{
		/**
		* @brief		リストが空である場合に、呼び出した際の挙動
		* @detail		ID:0-29
		* 				リストが空である場合に、呼び出した際に、
		*				戻り値はダミーノードを指すイテレータの場合成功です。
		*/
		TEST(ListCBeginTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_TRUE((&list.CBegin())->isDummy);
		}

		/**
		* @brief		リストに要素が一つある場合に、呼び出した際の挙動
		* @detail		ID:0-30
		* 				リストに要素が一つある場合に、呼び出した際に、
		*				先頭要素を指すイテレータが返る場合成功です。
		*/
		TEST(ListCBeginTest, WhenOneElementList)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			EXPECT_EQ(1, list.Count());
			EXPECT_TRUE((&node) == (&list.CBegin()));
		}

		/**
		* @brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
		* @detail		ID:0-31
		* 				リストに二つ以上の要素がある場合に、呼び出した際に、
		*				先頭要素を指すイテレータが返る場合成功です。
		*/
		TEST(ListCBeginTest, WhenManyElementsList)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			EXPECT_LE(2, list.Count());
			EXPECT_TRUE((&node1) == (&list.CBegin()));
		}

		/**
		* @brief		データの挿入を行った後に、呼び出した際の挙動
		* @detail		ID:0-32
		* 				データの挿入を行った後に、呼び出した際に、
		*				先頭要素を指すイテレータが返る場合成功です。
		*				要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。
		*/
		TEST(ListCBeginTest, AfterInsert)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			/**先頭に挿入*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node headNode;
			EXPECT_TRUE(list.Insert(head, &headNode));
			EXPECT_TRUE((&headNode) == (&list.CBegin()));

			/**中央に挿入*/
			DoubleLinkedList::Iterator middle(&node2, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Insert(middle, &newNode2));
			EXPECT_TRUE((&headNode) == (&list.CBegin()));

			/**末尾に挿入*/
			DoubleLinkedList::Iterator tail = list.End();
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Insert(tail, &newNode3));
			EXPECT_TRUE((&headNode) == (&list.CBegin()));
		}

		/**
		* @brief		データの削除を行った後に、呼び出した際の挙動
		* @detail		ID:0-33
		* 				データの削除を行った後に、呼び出した際に、
		*				先頭要素を指すイテレータが返る場合成功です。
		*				要素列の先頭、中央、末尾に削除を行った場合の各ケースについてチェックします。
		*/
		TEST(ListCBeginTest, AfterRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3, node4;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);
			list.PushBack(&node4);

			/**末尾要素を削除*/
			DoubleLinkedList::Iterator last = list.End();/**ダミーノード*/
			--last;/**末尾ノード*/
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Remove(last));
			EXPECT_TRUE((&node1) == (&list.CBegin()));

			/**中央を削除*/
			DoubleLinkedList::Iterator middle(&node3, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Remove(middle));
			EXPECT_TRUE((&node1) == (&list.CBegin()));

			/**先頭を削除*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			list.Remove(head);
			EXPECT_TRUE((&node2) == (&list.CBegin()));

		}
		/**
		* @brief		constのリストから呼び出して、コンパイルエラーとならないかをチェック
		* @detail		ID:0-34
		* 				constのリストから呼び出して、コンパイルエラーとならないかをチェック
		*				手動テスト
		*/
		//TEST(ListCBeginTest, IsConst)
		//{
		//	DoubleLinkedList list;
		//	DoubleLinkedList::Node node;
		//	list.PushBack(&node);
		//	const DoubleLinkedList constList = list;

		//	//constList.CBegin();/**コンパイルエラーにならない*/
		//}
	}
	//=================================== 末尾イテレータの取得のテスト ===================================
	namespace list_end_test
	{
		/**
		* @brief		リストが空である場合に、呼び出した際の挙動
		* @detail		ID:0-35
		* 				リストが空である場合に、呼び出した際に、
		*				戻り値はダミーノードを指すイテレータの場合成功です。
		*/
		TEST(ListEndTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_TRUE((&list.End())->isDummy);
		}

		/**
		* @brief		リストに要素が一つある場合に、呼び出した際の挙動
		* @detail		ID:0-36
		* 				リストに要素が一つある場合に、呼び出した際に、
		*				ミーノードを指すイテレータが返る場合成功です。
		*/
		TEST(ListEndTest, WhenOneElementList)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			EXPECT_EQ(1, list.Count());
			EXPECT_TRUE((*list.End()).isDummy);
		}

		/**
		* @brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
		* @detail		ID:0-37
		* 				リストに二つ以上の要素がある場合に、呼び出した際に、
		*				ミーノードを指すイテレータが返る場合成功です。
		*/
		TEST(ListEndTest, WhenManyElementsList)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			EXPECT_LE(2, list.Count());
			EXPECT_TRUE((*list.End()).isDummy);
		}

		/**
		* @brief		データの挿入を行った後に、呼び出した際の挙動
		* @detail		ID:0-38
		* 				データの挿入を行った後に、呼び出した際に、
		*				ミーノードを指すイテレータが返る場合成功です。
		*				要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。
		*/
		TEST(ListEndTest, AfterInsert)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			/**先頭に挿入*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			EXPECT_TRUE(list.Insert(head, &newNode1));
			EXPECT_TRUE((*list.End()).isDummy);

			/**中央に挿入*/
			DoubleLinkedList::Iterator middle(&node2, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Insert(middle, &newNode2));
			EXPECT_TRUE((*list.End()).isDummy);

			/**末尾に挿入*/
			DoubleLinkedList::Iterator tail = list.End();
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Insert(tail, &newNode3));
			EXPECT_TRUE((*list.End()).isDummy);
		}

		/**
		* @brief		データの削除を行った後に、呼び出した際の挙動
		* @detail		ID:0-39
		* 				データの削除を行った後に、呼び出した際に、
		*				ミーノードを指すイテレータが返る場合成功です。
		*				要素列の先頭、中央、末尾に削除を行った場合の各ケースについてチェックします。
		*/
		TEST(ListEndTest, AfterRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3, node4;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);
			list.PushBack(&node4);

			/**末尾要素を削除*/
			DoubleLinkedList::Iterator last = list.End();/**ダミーノード*/
			--last;/**末尾ノード*/
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Remove(last));
			EXPECT_TRUE((*list.End()).isDummy);

			/**中央を削除*/
			DoubleLinkedList::Iterator middle(&node3, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Remove(middle));
			EXPECT_TRUE((*list.End()).isDummy);

			/**先頭を削除*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			EXPECT_TRUE(list.Remove(head));
			EXPECT_TRUE((*list.End()).isDummy);
		}

		///**
		//* @brief		constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
		//* @detail		ID	:0-40
		//* 				constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
		//*					手動テスト
		//*/
		//TEST(ListEndTest, NotConst)
		//{
		//	DoubleLinkedList list;
		//	DoubleLinkedList::Node node;
		//	list.PushBack(&node);
		//	const DoubleLinkedList constList = list;

		//	//constList.End();/**コンパイルエラー*/
		//	SUCCEED();
		//}
	}
	//=================================== 末尾コンストイテレータの取得のテスト ===================================
	namespace list_constEnd_test
	{
		/**
		* @brief		リストが空である場合に、呼び出した際の挙動
		* @detail		ID:0-41
		* 				リストが空である場合に、呼び出した際に、
		*				戻り値はダミーノードを指すイテレータの場合成功です。
		*/
		TEST(ListCEndTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_TRUE((&list.CEnd())->isDummy);
		}

		/**
		* @brief		リストに要素が一つある場合に、呼び出した際の挙動
		* @detail		ID:0-42
		* 				リストに要素が一つある場合に、呼び出した際に、
		*				ミーノードを指すイテレータが返る場合成功です。
		*/
		TEST(ListCEndTest, WhenOneElementList)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			EXPECT_EQ(1, list.Count());
			EXPECT_TRUE((*list.CEnd()).isDummy);
		}

		/**
		* @brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動
		* @detail		ID:0-43
		* 				リストに二つ以上の要素がある場合に、呼び出した際に、
		*				ミーノードを指すイテレータが返る場合成功です。
		*/
		TEST(ListCEndTest, WhenManyElementsList)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			EXPECT_LE(2, list.Count());
			EXPECT_TRUE((*list.CEnd()).isDummy);
		}

		/**
		* @brief		データの挿入を行った後に、呼び出した際の挙動
		* @detail		ID:0-44
		* 				データの挿入を行った後に、呼び出した際に、
		*				ミーノードを指すイテレータが返る場合成功です。
		*				要素列の先頭、中央、末尾に挿入を行った場合の各ケースについてチェックします。
		*/
		TEST(ListCEndTest, AfterInsert)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			/**先頭に挿入*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			EXPECT_TRUE(list.Insert(head, &newNode1));
			EXPECT_TRUE((*list.CEnd()).isDummy);

			/**中央に挿入*/
			DoubleLinkedList::Iterator middle(&node2, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Insert(middle, &newNode2));
			EXPECT_TRUE((*list.CEnd()).isDummy);

			/**末尾に挿入*/
			DoubleLinkedList::Iterator tail = list.End();
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Insert(tail, &newNode3));
			EXPECT_TRUE((*list.CEnd()).isDummy);
		}

		/**
		* @brief		データの削除を行った後に、呼び出した際の挙動
		* @detail		ID:0-45
		* 				データの削除を行った後に、呼び出した際に、
		*				ミーノードを指すイテレータが返る場合成功です。
		*				要素列の先頭、中央、末尾に削除を行った場合の各ケースについてチェックします。
		*/
		TEST(ListCEndTest, AfterRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3, node4;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);
			list.PushBack(&node4);

			/**末尾要素を削除*/
			DoubleLinkedList::Iterator last = list.End();/**ダミーノード*/
			--last;/**末尾ノード*/
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Remove(last));
			EXPECT_TRUE((*list.CEnd()).isDummy);

			/**中央を削除*/
			DoubleLinkedList::Iterator middle(&node3, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Remove(middle));
			EXPECT_TRUE((*list.CEnd()).isDummy);

			/**先頭を削除*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			list.Remove(head);
			EXPECT_TRUE((*list.CEnd()).isDummy);

		}

		/**
		* @brief		constのリストから呼び出して、コンパイルエラーとならないかをチェック
		* @detail		ID:0-46
		* 				constのリストから呼び出して、コンパイルエラーとならないかをチェック
		*				手動テスト
		*/
		//TEST(ListCEndTest, IsConst)
		//{
		//	DoubleLinkedList list;
		//	DoubleLinkedList::Node node;
		//	list.PushBack(&node);
		//	const DoubleLinkedList constList = list;

		//	//constList.CEnd();/**コンパイルエラーにならない*/
		//}
	}
#endif
}