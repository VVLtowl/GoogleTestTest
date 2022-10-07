#include "pch.h"
#include "double_linked_list.h"

/**イテレータの単体テスト*/
#define GT_TEST_ITERATOR

//=================================== イテレータ単体テストの自動テスト ===================================
namespace iterator_test
{
#if defined GT_TEST_ITERATOR
	//=================================== イテレータの指す要素を取得するテスト ===================================
	namespace iterator_getNode_test
	{
		/**
		* @brief		リストの参照がない状態で呼び出した際の挙動
		* @detail		ID:1-0
		* 				リストの参照がない状態で呼び出した際に、
		*				assert発生するかを確認します。
		*/
		TEST(IteratorGetNodeTest, WhenNoReference)
		{
			DoubleLinkedList::Node node;
			DoubleLinkedList::Iterator iter(&node, nullptr);
			EXPECT_DEATH((*iter), "");
		}

		/**
		* @brief		Iteratorから取得した要素に対して、値の代入が行えるかをチェック
		* @detail		ID:1-1
		*				Iteratorから取得した要素に対して、
		*				値の代入が行えるかをチェックします。
		*/
		TEST(IteratorGetNodeTest, AfterAssignNodeData)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			int initScore = node.scoreData.score;
			char initName[WORD_SIZE];
			strcpy(initName, node.scoreData.name);
			list.PushBack(&node);
			//変更前は初期化の値と同じ
			EXPECT_EQ(initScore, node.scoreData.score);
			EXPECT_EQ(0, strcmp(initName, node.scoreData.name));

			DoubleLinkedList::Iterator iter = list.Begin();
			(*iter).scoreData.score = 10;
			strcpy((*iter).scoreData.name, "Test1-1");
			//変更後は初期値と異なる
			EXPECT_NE(initScore, node.scoreData.score);
			EXPECT_NE(0, strcmp(initName, node.scoreData.name));
		}

		/**
		* @brief		ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック
		* @detail		ID:1-2
		*				ConstIteratorから取得した要素に対して、
		*				値の代入が行えないかをチェックします。
		*				コンパイルエラーになることをチェックします。
		*/
		//TEST(IteratorGetNodeTest, WhenEmptyList_GetFromBegin)
		//{
		//	DoubleLinkedList list;
		//	DoubleLinkedList::Node node;
		//	list.PushBack(&node);
		//	DoubleLinkedList::ConstIterator constIter = list.Begin();
		//	DoubleLinkedList::Iterator iter = list.Begin();
		//	(*iter).scoreData.score = 10;
		//	(*constIter).scoreData.score = 10;
		//}

		/**
		* @brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動
		* @detail		ID:1-3
		*				リストが空の際の、先頭イテレータに対して呼び出した際に、
		* 				assert発生するかを確認します。
		*/
		TEST(IteratorGetNodeTest, WhenEmptyList_GetFromBegin)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.Begin();
			EXPECT_EQ(0, list.Count());
			EXPECT_DEATH((*iter), "");
		}

		/**
		* @brief		末尾イテレータに対して呼び出した際の挙動
		* @detail		ID:1-4
		*				末尾イテレータに対して呼び出した際に、
		* 				assert発生するかを確認します。
		*/
		TEST(IteratorGetNodeTest, GetFromEnd)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.End();
			EXPECT_DEATH((*iter), "");
		}
	}
	//=================================== イテレータをリストの末尾に向かって一つ進めるテスト ===================================
	namespace iterator__increment_test
	{
		/**
		* @brief		リストの参照がない状態で呼び出した際の挙動
		* @detail		ID:1-5
		* 				リストの参照がない状態で呼び出した際に、
		*				assert発生するかを確認します。
		*/
		TEST(IteratorIncrementTest, WhenNoReference)
		{
			DoubleLinkedList::Node node;
			DoubleLinkedList::Iterator iter(&node, nullptr);
			EXPECT_DEATH((++iter), "");
		}

		/**
		* @brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動
		* @detail		ID:1-6
		* 				リストが空の際の、先頭イテレータに対して呼び出した際に、
		*				assert発生するかを確認します。
		*/
		TEST(IteratorIncrementTest, WhenEmptyList_IncrementBegin)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.Begin();
			EXPECT_DEATH((++iter), "");
		}

		/**
		* @brief		末尾イテレータに対して呼び出した際の挙動
		* @detail		ID:1-7
		* 				末尾イテレータに対して呼び出した際に、
		*				assert発生するかを確認します。
		*/
		TEST(IteratorIncrementTest, IncrementEnd)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.End();
			EXPECT_DEATH((++iter), "");
		}

		/**
		* @brief		リストに二つ以上の要素がある場合に呼び出した際の挙動
		* @detail		ID:1-8
		* 				リストに二つ以上の要素がある場合に呼び出した際に、
		*				次の要素を指すのかを確認します。
		*/
		TEST(IteratorIncrementTest, WhenManyElements)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);

			/**
			* リストの先頭から末尾まで呼び出しを行い、
			* 期待されている要素が格納されているかを確認
			*/
			DoubleLinkedList::Iterator iter = list.Begin();
			while (iter != list.CEnd())
			{
				DoubleLinkedList::Node* next = (&iter)->pNext;
				++iter;
				EXPECT_EQ(next, &iter);
			}
		}

		/**
		* @brief		前置インクリメントを行った際の挙動
		* @detail		ID:1-9
		* 				前置インクリメントを行った際に、
		*				次の要素を指すのかを確認します。
		*/
		TEST(IteratorIncrementTest, PreIncrement)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Iterator iter = list.Begin();
			DoubleLinkedList::Node* current = &iter;
			++iter;
			EXPECT_TRUE(current->pNext == &iter);
		}

		/**
		* @brief		後置インクリメントを行った際の挙動
		* @detail		ID:1-10
		* 				後置インクリメントを行った際に、
		*				次の要素を指すのかを確認します。
		*/
		TEST(IteratorIncrementTest, PostIncrement)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Iterator iter = list.Begin();
			DoubleLinkedList::Node* current = &iter;
			iter++;
			EXPECT_TRUE(current->pNext == &iter);
		}
	}
	//=================================== イテレータをリストの先頭に向かって一つ進めるテスト ===================================
	namespace iterator_decrement_test
	{
		/**
		* @brief		リストの参照がない状態で呼び出した際の挙動
		* @detail		ID:1-11
		* 				リストの参照がない状態で呼び出した際に、
		*				assert発生するかを確認します。
		*/
		TEST(IteratorDecrementTest, WhenNoReference)
		{
			DoubleLinkedList::Node node;
			DoubleLinkedList::Iterator iter(&node, nullptr);
			EXPECT_DEATH((--iter), "");
		}

		/**
		* @brief		リストが空の際の、末尾イテレータに対して呼び出した際の挙動
		* @detail		ID:1-12
		* 				リストが空の際の、末尾イテレータに対して呼び出した際に、
		*				assert発生するかを確認します。
		*/
		TEST(IteratorDecrementTest, WhenEmptyList_DecrementBegin)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.End();
			EXPECT_DEATH((--iter), "");
		}

		/**
		* @brief		先頭イテレータに対して呼び出した際の挙動
		* @detail		ID:1-13
		* 				先頭イテレータに対して呼び出した際に、
		*				assert発生するかを確認します。
		*/
		TEST(IteratorDecrementTest, DecrementEnd)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.Begin();
			EXPECT_DEATH((--iter), "");
		}

		/**
		* @brief		リストに二つ以上の要素がある場合に呼び出した際の挙動
		* @detail		ID:1-14
		* 				リストに二つ以上の要素がある場合に呼び出した際に、
		*				前の要素を指すのかを確認します。
		*/
		TEST(IteratorDecrementTest, WhenManyElements)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);

			/**
			* リストの末尾から先頭まで呼び出しを行い、
			* 期待されている要素が格納されているかを確認
			*/
			DoubleLinkedList::Iterator iter = list.End();
			while (1)
			{
				DoubleLinkedList::Node* prev = (&iter)->pPrev;
				--iter;
				EXPECT_EQ(prev, &iter);

				if (iter == list.Begin())
				{
					break;
				}
				else
				{
					--iter;
				}
			}
		}

		/**
		* @brief		前置インクリメントを行った際の挙動
		* @detail		ID:1-15
		* 				前置インクリメントを行った際に、
		*				前の要素を指すのかを確認します。
		*/
		TEST(IteratorDecrementTest, PreDecrement)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Iterator iter = list.End();
			DoubleLinkedList::Node* current = &iter;
			--iter;
			EXPECT_TRUE(current->pPrev == &iter);
		}

		/**
		* @brief		後置インクリメントを行った際の挙動
		* @detail		ID:1-10
		* 				後置インクリメントを行った際に、
		*				前の要素を指すのかを確認します。
		*/
		TEST(IteratorDecrementTest, PostDecrement)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Iterator iter = list.End();
			DoubleLinkedList::Node* current = &iter;
			iter--;
			EXPECT_TRUE(current->pPrev == &iter);
		}
	}
	//=================================== イテレータのコピーを行うテスト ===================================
	namespace iterator_copy_test
	{

	}
	//=================================== イテレータの代入を行うテスト ===================================
	namespace iterator_assign_test
	{

	}
	//=================================== 二つのイテレータが同一のものであるか、比較を行うテスト ===================================
	namespace iterator_equal_test
	{

	}
	//=================================== 二つのイテレータが異なるものであるか、比較を行うテスト ===================================
	namespace iterator_notEqual_test
	{

	}
#endif
}