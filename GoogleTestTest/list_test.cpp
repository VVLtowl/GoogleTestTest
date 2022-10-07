#include "pch.h"
#include "double_linked_list.h"

/**�o�������X�g�̒P�̃e�X�g*/
#define GT_TEST_DOUBLE_LINKED_LIST

//=================================== �o�������X�g�P�̃e�X�g�̎����e�X�g ===================================
namespace doubleLinkedList_test
{
#if defined GT_TEST_DOUBLE_LINKED_LIST
	//=================================== �f�[�^���̎擾�̃e�X�g ===================================
	namespace list_count_test
	{
		/**
		* @brief		���X�g����ł���ꍇ�̖߂�l
		* @detail		ID:0-0
		* 				���X�g����ł���ꍇ�A
		*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
		*				�߂�l��0�̏ꍇ�����ł��B
		*/
		TEST(ListCountTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_EQ(0, list.Count());
		}

		/**
		* @brief		���X�g�����ւ̑}�����s�����ۂ̖߂�l
		* @detail		ID:0-1
		* 				���X�g�����ւ̑}�����s�����ۂɁA
		*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
		*				�߂�l��1�̏ꍇ�����ł��B
		*/
		TEST(ListCountTest, WhenPushBackSucceed)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			EXPECT_TRUE(list.PushBack(&node));
			EXPECT_EQ(1, list.Count());
		}

		/**
		* @brief		���X�g�����ւ̑}�������s�����ۂ̖߂�l
		* @detail		ID:0-2
		* 				���X�g�����ւ̑}�������s�����ۂɁA
		*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
		*				�߂�l��0�̏ꍇ�����ł��B
		*/
		TEST(ListCountTest, WhenPushBackFailed)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node* node = nullptr;
			EXPECT_FALSE(list.PushBack(node));
			EXPECT_EQ(0, list.Count());
		}

		/**
		* @brief		�f�[�^�̑}�����s�����ۂ̖߂�l
		* @detail		ID:0-3
		* 				�f�[�^�̑}�����s�����ۂɁA
		*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
		*				�߂�l��1�̏ꍇ�����ł��B
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
		* @brief		�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l
		* @detail		ID:0-4
		* 				�f�[�^�̑}���Ɏ��s�����ۂɁA
		*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
		*				�߂�l��0�̏ꍇ�����ł��B
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
		* @brief		�f�[�^�̍폜���s�����ۂ̖߂�l
		* @detail		ID:0-5
		* 				�f�[�^�̍폜���s�����ۂɁA
		*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
		*				�߂�l��0�̏ꍇ�����ł��B
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
		* @brief		�f�[�^�̍폜�����s�����ۂ̖߂�l
		* @detail		ID:0-6
		* 				�f�[�^��}��������A�폜�����ꍇ�A�폜�����s�����ۂɁA
		*				�f�[�^���̎擾�擾�֐��̖߂�l���m�F���܂��B
		*				�߂�l��1�̏ꍇ�����ł��B
		*/
		TEST(ListCountTest, WhenRemoveFailed)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			DoubleLinkedList::Iterator wrong(nullptr, nullptr); //�폜�̎��s���N�������߂́A���X�g�ɑ��݂��Ȃ��v�f��
			EXPECT_FALSE(list.Remove(wrong));
			EXPECT_EQ(1, list.Count());
		}

		/**
		* @brief		���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
		* @detail		ID:0-7
		*				�}�C�i�X�ɂȂ�Ȃ������m�F���邽�߁A
		* 				���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂɁA
		*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
		*				�߂�l��0�̏ꍇ�����ł��B
		*/
		TEST(ListCountTest, WhenEmptyListAndRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter=list.End();
			EXPECT_FALSE(list.Remove(iter));
			EXPECT_EQ(0, list.Count());
		}
	}
	//=================================== �f�[�^�̑}���̃e�X�g ===================================
	namespace list_insert_test
	{
		/**
		* @brief		���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
		* @detail		ID:0-9
		* 				���X�g����ł���ꍇ�ɁA�V�v�f���C�e���[�^�̎w���ʒu�ɑ}�����܂��B
		*				�擪�C�e���[�^�A�����C�e���[�^�������œn�����ꍇ�ɂ��āA�ʂɋ������`�F�b�N���܂��B
		*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
		*				�߂�l��true�̏ꍇ�����ł��B
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
		* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
		* @detail		ID:0-10
		* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�����܂��B
		*				�擪�ɗv�f���}������A���X�擪�������v�f���Q�ԖڂɂȂ�܂��B
		*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
		*				�߂�l��true�̏ꍇ�����ł��B
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
			EXPECT_TRUE((&(++iter)) == &node1);//���X�擪�������v�f���Q�ԖڂɂȂ��Ă邩
		}

		/**
		* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋���
		* @detail		ID:0-11
		* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�����܂��B
		*				�C�e���[�^�̎w���ʒu�ɗv�f���}������܂��B
		*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
		*				�߂�l��true�̏ꍇ�����ł��B
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
		* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
		* @detail		ID:0-12
		* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���āA�}�����܂��B
		*				�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ���܂��B
		*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
		*				�߂�l��true�̏ꍇ�����ł��B
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
		* @brief		ConstIterator���w�肵�đ}�����s�����ۂ̋���
		* @detail		ID:0-13
		* 				ConstIterator���w�肵�āA�}�����܂��B
		*				�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ���܂��B
		*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
		*				�߂�l��true�̏ꍇ�����ł��B
		* 
		*				�i�[�ς݂̗v�f�ɉe�����Ȃ����A���҂����ʒu�ɗv�f���i�[����Ă��邩�B
		*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
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
		* @brief		�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
		* @detail		ID:0-14
		* 				���X�g�̎Q�Ƃ��Ȃ��C�e���[�^�A�ʃ��X�g�̗v�f���w���C�e���[�^��n�����ۂ̋����Ȃǂ��m�F���܂��B
		*				���X�g�̎Q�Ƃ��Ȃ��C�e���[�^���w�肵����A
		*				�ʃ��X�g�̗v�f���w���C�e���[�^��n�����肵�āA�}�����܂��B
		*				�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ���܂��B
		*				�f�[�^�̑}���֐��̖߂�l���m�F���܂��B
		*				�߂�l��true�̏ꍇ�����ł��B
		*
		*/
		TEST(ListInsertTest, WhenNotEmptyList_InsertWrongIterator)
		{
			DoubleLinkedList listA;
			DoubleLinkedList::Node node1, node2;
			listA.PushBack(&node1);
			listA.PushBack(&node2);

			DoubleLinkedList listB;				//�ʃ��X�g
			DoubleLinkedList::Node node3;		//�ʃ��X�g�̗v�f
			EXPECT_TRUE(listB.PushBack(&node3));

			DoubleLinkedList::Iterator noReference(nullptr, nullptr);//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^
			DoubleLinkedList::Node newNode1;
			EXPECT_FALSE(listA.Insert(noReference, &newNode1));

			DoubleLinkedList::Iterator wrongList(&node3,&listB);//�ʃ��X�g�̗v�f���w���C�e���[�^
			DoubleLinkedList::Node newNode2;
			EXPECT_FALSE(listA.Insert(wrongList, &newNode2));
		}
	}
	//=================================== �f�[�^�̍폜�̃e�X�g ===================================
	namespace list_remove_test 
	{
		/**
		* @brief		���X�g����ł���ꍇ�ɁA�폜�����ۂ̋���
		* @detail		ID:0-16
		* 				���X�g����ł���ꍇ�ɁA�V�v�f���C�e���[�^�̎w���ʒu�ɑ}�����܂��B
		*				�C�e���[�^�̎w���ʒu�ɗv�f���}�����ꂻ�̈ʒu�ɂ������v�f�����ɂ����B
		*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
		*				�߂�l��false�̏ꍇ�����ł��B
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
		* @brief		�擪�v�f�̍폜�̋���
		* @detail		ID:0-17
		* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜���܂��B
		*				�擪�v�f���폜���ꂽ�����m�F���܂��B
		*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
		*				�߂�l��true�̏ꍇ�����ł��B
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
		* @brief		�����v�f���폜�����ۂ̋���
		* @detail		ID:0-18
		* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜���܂��B
		*				�����̓_�~�[�m�[�h�Ȃ̂ŁA�폜�͎��s����͂��ł��B
		*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
		*				�߂�l��false�̏ꍇ�����ł��B
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
		* @brief		���ԗv�f���폜�����ۂ̋���
		* @detail		ID:0-19
		* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂɁA
		*				�C�e���[�^�Ɏw���ꂽ�v�f���폜���ꂽ�����m�F���܂��B
		*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
		*				�߂�l��true�̏ꍇ�����ł��B
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
		* @brief		ConstIterator���w�肵�č폜���s�����ۂ̋���
		* @detail		ID:0-20
		* 				���X�g�ɕ����̗v�f������ꍇ�ɁAConstIterator���w�肵�Ă����ۂɁA
		*				ConstIterator�Ɏw���ꂽ�v�f���폜���ꂽ�����m�F���܂��B
		*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
		*				�߂�l��true�̏ꍇ�����ł��B
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
		* @brief		�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
		* @detail		ID:0-21
		* 				���X�g�̎Q�Ƃ��Ȃ��C�e���[�^�A�ʃ��X�g�̗v�f���w���C�e���[�^�Ȃ�
		*				�s���ȃC�e���[�^��n�����ۂɁA
		*				�f�[�^�̍폜�֐��̖߂�l���m�F���܂��B
		*				�߂�l��false�̏ꍇ�����ł��B
		*/
		TEST(ListRemoveTest, WhenNotEmptyList_RemoveByWrongIterator)
		{
			DoubleLinkedList listA;
			DoubleLinkedList::Node node1, node2;
			listA.PushBack(&node1);
			listA.PushBack(&node2);

			DoubleLinkedList listB;			//�ʃ��X�g
			DoubleLinkedList::Node node3;	//�ʃ��X�g�̗v�f
			listB.PushBack(&node3);

			DoubleLinkedList::Iterator noReference(nullptr, nullptr);//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^
			EXPECT_FALSE(listA.Remove(noReference));

			DoubleLinkedList::Iterator wrongList(&node3, &listB);//�ʃ��X�g�̗v�f���w���C�e���[�^
			EXPECT_FALSE(listA.Remove(wrongList));
		}
	}
	//=================================== �擪�C�e���[�^�̎擾�̃e�X�g ===================================
	namespace list_begin_test 
	{
		/**
		* @brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-23
		* 				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂɁA
		*				�߂�l�̓_�~�[�m�[�h���w���C�e���[�^�̏ꍇ�����ł��B
		*/
		TEST(ListBeginTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_TRUE((&list.Begin())->isDummy);
		}

		/**
		* @brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-24
		* 				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂɁA
		*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
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
		* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-25
		* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂɁA
		*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
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
		* @brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-26
		* 				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂɁA
		*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
		*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
		*/
		TEST(ListBeginTest, AfterInsert)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			/**�擪�ɑ}��*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node headNode;
			EXPECT_TRUE(list.Insert(head, &headNode));
			EXPECT_TRUE((&headNode) == (&list.Begin()));

			/**�����ɑ}��*/
			DoubleLinkedList::Iterator middle(&node2,&list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Insert(middle, &newNode2));
			EXPECT_TRUE((&headNode) == (&list.Begin()));

			/**�����ɑ}��*/
			DoubleLinkedList::Iterator tail = list.End();
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Insert(tail, &newNode3));
			EXPECT_TRUE((&headNode) == (&list.Begin()));
		}

		/**
		* @brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-27
		* 				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂɁA
		*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
		*				�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
		*/
		TEST(ListBeginTest, AfterRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3, node4;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);
			list.PushBack(&node4);

			/**�����v�f���폜*/
			DoubleLinkedList::Iterator last = list.End();/**�_�~�[�m�[�h*/
			--last;/**�����m�[�h*/
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Remove(last));
			EXPECT_TRUE((&node1) == (&list.Begin()));

			/**�������폜*/
			DoubleLinkedList::Iterator middle(&node3, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Remove(middle));
			EXPECT_TRUE((&node1) == (&list.Begin()));

			/**�擪���폜*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			EXPECT_TRUE(list.Remove(head));
			EXPECT_TRUE((&node2) == (&list.Begin()));
		}

		/**
		* @brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
		* @detail		ID:0-28
		* 				const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
		*				�蓮�e�X�g
		*/
		/*TEST(ListBeginTest, NotConst)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);
			const DoubleLinkedList constList = list;
		}*/
	}
	//=================================== �擪�R���X�g�C�e���[�^�̎擾�̃e�X�g ===================================
	namespace list_constBegin_test
	{
		/**
		* @brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-29
		* 				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂɁA
		*				�߂�l�̓_�~�[�m�[�h���w���C�e���[�^�̏ꍇ�����ł��B
		*/
		TEST(ListCBeginTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_TRUE((&list.CBegin())->isDummy);
		}

		/**
		* @brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-30
		* 				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂɁA
		*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
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
		* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-31
		* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂɁA
		*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
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
		* @brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-32
		* 				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂɁA
		*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
		*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
		*/
		TEST(ListCBeginTest, AfterInsert)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			/**�擪�ɑ}��*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node headNode;
			EXPECT_TRUE(list.Insert(head, &headNode));
			EXPECT_TRUE((&headNode) == (&list.CBegin()));

			/**�����ɑ}��*/
			DoubleLinkedList::Iterator middle(&node2, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Insert(middle, &newNode2));
			EXPECT_TRUE((&headNode) == (&list.CBegin()));

			/**�����ɑ}��*/
			DoubleLinkedList::Iterator tail = list.End();
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Insert(tail, &newNode3));
			EXPECT_TRUE((&headNode) == (&list.CBegin()));
		}

		/**
		* @brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-33
		* 				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂɁA
		*				�擪�v�f���w���C�e���[�^���Ԃ�ꍇ�����ł��B
		*				�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
		*/
		TEST(ListCBeginTest, AfterRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3, node4;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);
			list.PushBack(&node4);

			/**�����v�f���폜*/
			DoubleLinkedList::Iterator last = list.End();/**�_�~�[�m�[�h*/
			--last;/**�����m�[�h*/
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Remove(last));
			EXPECT_TRUE((&node1) == (&list.CBegin()));

			/**�������폜*/
			DoubleLinkedList::Iterator middle(&node3, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Remove(middle));
			EXPECT_TRUE((&node1) == (&list.CBegin()));

			/**�擪���폜*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			list.Remove(head);
			EXPECT_TRUE((&node2) == (&list.CBegin()));

		}
		/**
		* @brief		const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N
		* @detail		ID:0-34
		* 				const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N
		*				�蓮�e�X�g
		*/
		//TEST(ListCBeginTest, IsConst)
		//{
		//	DoubleLinkedList list;
		//	DoubleLinkedList::Node node;
		//	list.PushBack(&node);
		//	const DoubleLinkedList constList = list;

		//	//constList.CBegin();/**�R���p�C���G���[�ɂȂ�Ȃ�*/
		//}
	}
	//=================================== �����C�e���[�^�̎擾�̃e�X�g ===================================
	namespace list_end_test
	{
		/**
		* @brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-35
		* 				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂɁA
		*				�߂�l�̓_�~�[�m�[�h���w���C�e���[�^�̏ꍇ�����ł��B
		*/
		TEST(ListEndTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_TRUE((&list.End())->isDummy);
		}

		/**
		* @brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-36
		* 				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂɁA
		*				�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
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
		* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-37
		* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂɁA
		*				�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
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
		* @brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-38
		* 				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂɁA
		*				�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
		*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
		*/
		TEST(ListEndTest, AfterInsert)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			/**�擪�ɑ}��*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			EXPECT_TRUE(list.Insert(head, &newNode1));
			EXPECT_TRUE((*list.End()).isDummy);

			/**�����ɑ}��*/
			DoubleLinkedList::Iterator middle(&node2, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Insert(middle, &newNode2));
			EXPECT_TRUE((*list.End()).isDummy);

			/**�����ɑ}��*/
			DoubleLinkedList::Iterator tail = list.End();
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Insert(tail, &newNode3));
			EXPECT_TRUE((*list.End()).isDummy);
		}

		/**
		* @brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-39
		* 				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂɁA
		*				�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
		*				�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
		*/
		TEST(ListEndTest, AfterRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3, node4;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);
			list.PushBack(&node4);

			/**�����v�f���폜*/
			DoubleLinkedList::Iterator last = list.End();/**�_�~�[�m�[�h*/
			--last;/**�����m�[�h*/
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Remove(last));
			EXPECT_TRUE((*list.End()).isDummy);

			/**�������폜*/
			DoubleLinkedList::Iterator middle(&node3, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Remove(middle));
			EXPECT_TRUE((*list.End()).isDummy);

			/**�擪���폜*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			EXPECT_TRUE(list.Remove(head));
			EXPECT_TRUE((*list.End()).isDummy);
		}

		///**
		//* @brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
		//* @detail		ID	:0-40
		//* 				const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
		//*					�蓮�e�X�g
		//*/
		//TEST(ListEndTest, NotConst)
		//{
		//	DoubleLinkedList list;
		//	DoubleLinkedList::Node node;
		//	list.PushBack(&node);
		//	const DoubleLinkedList constList = list;

		//	//constList.End();/**�R���p�C���G���[*/
		//	SUCCEED();
		//}
	}
	//=================================== �����R���X�g�C�e���[�^�̎擾�̃e�X�g ===================================
	namespace list_constEnd_test
	{
		/**
		* @brief		���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-41
		* 				���X�g����ł���ꍇ�ɁA�Ăяo�����ۂɁA
		*				�߂�l�̓_�~�[�m�[�h���w���C�e���[�^�̏ꍇ�����ł��B
		*/
		TEST(ListCEndTest, WhenEmptyList)
		{
			DoubleLinkedList list;
			EXPECT_TRUE((&list.CEnd())->isDummy);
		}

		/**
		* @brief		���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-42
		* 				���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂɁA
		*				�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
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
		* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-43
		* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂɁA
		*				�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
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
		* @brief		�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-44
		* 				�f�[�^�̑}�����s������ɁA�Ăяo�����ۂɁA
		*				�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
		*				�v�f��̐擪�A�����A�����ɑ}�����s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
		*/
		TEST(ListCEndTest, AfterInsert)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			/**�擪�ɑ}��*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			EXPECT_TRUE(list.Insert(head, &newNode1));
			EXPECT_TRUE((*list.CEnd()).isDummy);

			/**�����ɑ}��*/
			DoubleLinkedList::Iterator middle(&node2, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Insert(middle, &newNode2));
			EXPECT_TRUE((*list.CEnd()).isDummy);

			/**�����ɑ}��*/
			DoubleLinkedList::Iterator tail = list.End();
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Insert(tail, &newNode3));
			EXPECT_TRUE((*list.CEnd()).isDummy);
		}

		/**
		* @brief		�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
		* @detail		ID:0-45
		* 				�f�[�^�̍폜���s������ɁA�Ăяo�����ۂɁA
		*				�~�[�m�[�h���w���C�e���[�^���Ԃ�ꍇ�����ł��B
		*				�v�f��̐擪�A�����A�����ɍ폜���s�����ꍇ�̊e�P�[�X�ɂ��ă`�F�b�N���܂��B
		*/
		TEST(ListCEndTest, AfterRemove)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3, node4;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);
			list.PushBack(&node4);

			/**�����v�f���폜*/
			DoubleLinkedList::Iterator last = list.End();/**�_�~�[�m�[�h*/
			--last;/**�����m�[�h*/
			DoubleLinkedList::Node newNode3;
			EXPECT_TRUE(list.Remove(last));
			EXPECT_TRUE((*list.CEnd()).isDummy);

			/**�������폜*/
			DoubleLinkedList::Iterator middle(&node3, &list);
			DoubleLinkedList::Node newNode2;
			EXPECT_TRUE(list.Remove(middle));
			EXPECT_TRUE((*list.CEnd()).isDummy);

			/**�擪���폜*/
			DoubleLinkedList::Iterator head = list.Begin();
			DoubleLinkedList::Node newNode1;
			list.Remove(head);
			EXPECT_TRUE((*list.CEnd()).isDummy);

		}

		/**
		* @brief		const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N
		* @detail		ID:0-46
		* 				const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N
		*				�蓮�e�X�g
		*/
		//TEST(ListCEndTest, IsConst)
		//{
		//	DoubleLinkedList list;
		//	DoubleLinkedList::Node node;
		//	list.PushBack(&node);
		//	const DoubleLinkedList constList = list;

		//	//constList.CEnd();/**�R���p�C���G���[�ɂȂ�Ȃ�*/
		//}
	}
#endif
}