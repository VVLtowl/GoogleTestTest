#include "pch.h"
#include "double_linked_list.h"

/**�C�e���[�^�̒P�̃e�X�g*/
#define GT_TEST_ITERATOR

//=================================== �C�e���[�^�P�̃e�X�g�̎����e�X�g ===================================
namespace iterator_test
{
#if defined GT_TEST_ITERATOR
	//=================================== �C�e���[�^�̎w���v�f���擾����e�X�g ===================================
	namespace iterator_getNode_test
	{
		/**
		* @brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
		* @detail		ID:1-0
		* 				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂɁA
		*				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorGetNodeTest, WhenNoReference)
		{
			DoubleLinkedList::Node node;
			DoubleLinkedList::Iterator iter(&node, nullptr);
			EXPECT_DEATH((*iter), "");
		}

		/**
		* @brief		Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
		* @detail		ID:1-1
		*				Iterator����擾�����v�f�ɑ΂��āA
		*				�l�̑�����s���邩���`�F�b�N���܂��B
		*/
		TEST(IteratorGetNodeTest, AfterAssignNodeData)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			int initScore = node.scoreData.score;
			char initName[WORD_SIZE];
			strcpy(initName, node.scoreData.name);
			list.PushBack(&node);
			//�ύX�O�͏������̒l�Ɠ���
			EXPECT_EQ(initScore, node.scoreData.score);
			EXPECT_EQ(0, strcmp(initName, node.scoreData.name));

			DoubleLinkedList::Iterator iter = list.Begin();
			(*iter).scoreData.score = 10;
			strcpy((*iter).scoreData.name, "Test1-1");
			//�ύX��͏����l�ƈقȂ�
			EXPECT_NE(initScore, node.scoreData.score);
			EXPECT_NE(0, strcmp(initName, node.scoreData.name));
		}

		/**
		* @brief		ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N
		* @detail		ID:1-2
		*				ConstIterator����擾�����v�f�ɑ΂��āA
		*				�l�̑�����s���Ȃ������`�F�b�N���܂��B
		*				�R���p�C���G���[�ɂȂ邱�Ƃ��`�F�b�N���܂��B
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
		* @brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		* @detail		ID:1-3
		*				���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
		* 				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorGetNodeTest, WhenEmptyList_GetFromBegin)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.Begin();
			EXPECT_EQ(0, list.Count());
			EXPECT_DEATH((*iter), "");
		}

		/**
		* @brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		* @detail		ID:1-4
		*				�����C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
		* 				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorGetNodeTest, GetFromEnd)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.End();
			EXPECT_DEATH((*iter), "");
		}
	}
	//=================================== �C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g ===================================
	namespace iterator__increment_test
	{
		/**
		* @brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
		* @detail		ID:1-5
		* 				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂɁA
		*				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorIncrementTest, WhenNoReference)
		{
			DoubleLinkedList::Node node;
			DoubleLinkedList::Iterator iter(&node, nullptr);
			EXPECT_DEATH((++iter), "");
		}

		/**
		* @brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		* @detail		ID:1-6
		* 				���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
		*				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorIncrementTest, WhenEmptyList_IncrementBegin)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.Begin();
			EXPECT_DEATH((++iter), "");
		}

		/**
		* @brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		* @detail		ID:1-7
		* 				�����C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
		*				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorIncrementTest, IncrementEnd)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.End();
			EXPECT_DEATH((++iter), "");
		}

		/**
		* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
		* @detail		ID:1-8
		* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂɁA
		*				���̗v�f���w���̂����m�F���܂��B
		*/
		TEST(IteratorIncrementTest, WhenManyElements)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);

			/**
			* ���X�g�̐擪���疖���܂ŌĂяo�����s���A
			* ���҂���Ă���v�f���i�[����Ă��邩���m�F
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
		* @brief		�O�u�C���N�������g���s�����ۂ̋���
		* @detail		ID:1-9
		* 				�O�u�C���N�������g���s�����ۂɁA
		*				���̗v�f���w���̂����m�F���܂��B
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
		* @brief		��u�C���N�������g���s�����ۂ̋���
		* @detail		ID:1-10
		* 				��u�C���N�������g���s�����ۂɁA
		*				���̗v�f���w���̂����m�F���܂��B
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
	//=================================== �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g ===================================
	namespace iterator_decrement_test
	{
		/**
		* @brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
		* @detail		ID:1-11
		* 				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂɁA
		*				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorDecrementTest, WhenNoReference)
		{
			DoubleLinkedList::Node node;
			DoubleLinkedList::Iterator iter(&node, nullptr);
			EXPECT_DEATH((--iter), "");
		}

		/**
		* @brief		���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		* @detail		ID:1-12
		* 				���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
		*				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorDecrementTest, WhenEmptyList_DecrementBegin)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.End();
			EXPECT_DEATH((--iter), "");
		}

		/**
		* @brief		�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		* @detail		ID:1-13
		* 				�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
		*				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorDecrementTest, DecrementEnd)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.Begin();
			EXPECT_DEATH((--iter), "");
		}

		/**
		* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
		* @detail		ID:1-14
		* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂɁA
		*				�O�̗v�f���w���̂����m�F���܂��B
		*/
		TEST(IteratorDecrementTest, WhenManyElements)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2, node3;
			list.PushBack(&node1);
			list.PushBack(&node2);
			list.PushBack(&node3);

			/**
			* ���X�g�̖�������擪�܂ŌĂяo�����s���A
			* ���҂���Ă���v�f���i�[����Ă��邩���m�F
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
		* @brief		�O�u�C���N�������g���s�����ۂ̋���
		* @detail		ID:1-15
		* 				�O�u�C���N�������g���s�����ۂɁA
		*				�O�̗v�f���w���̂����m�F���܂��B
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
		* @brief		��u�C���N�������g���s�����ۂ̋���
		* @detail		ID:1-10
		* 				��u�C���N�������g���s�����ۂɁA
		*				�O�̗v�f���w���̂����m�F���܂��B
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
	//=================================== �C�e���[�^�̃R�s�[���s���e�X�g ===================================
	namespace iterator_copy_test
	{

	}
	//=================================== �C�e���[�^�̑�����s���e�X�g ===================================
	namespace iterator_assign_test
	{

	}
	//=================================== ��̃C�e���[�^������̂��̂ł��邩�A��r���s���e�X�g ===================================
	namespace iterator_equal_test
	{

	}
	//=================================== ��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���e�X�g ===================================
	namespace iterator_notEqual_test
	{

	}
#endif
}