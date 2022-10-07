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
		* 				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ�
		*				�f�[�^���̎擾�֐��̖߂�l���m�F���܂��B
		*				�߂�l��0�̏ꍇ�����ł��B
		*/
		TEST(IteratorGetNodeTest, WhenNoReference)
		{
			DoubleLinkedList::Node node;
			DoubleLinkedList::Iterator iter(&node, nullptr);
			EXPECT_DEATH((&iter), "");
			EXPECT_DEATH((*iter), "");
		}

		/**
		* @brief		Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
		* @detail		ID:1-1
		*				Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N���܂��B
		* 				�����ɍēx�Ăяo���A�l���ύX����Ă��邱�Ƃ��m�F���܂��B
		*				
		*				
		*/
		TEST(IteratorGetNodeTest, AfterAssignNodeData)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			int initScore = node.scoreData.score;
			char initName[WORD_SIZE];
			strcpy(initName, node.scoreData.name);
			list.PushBack(&node);
			EXPECT_EQ(initScore, node.scoreData.score);
			EXPECT_EQ(0, strcmp(initName, node.scoreData.name));

			DoubleLinkedList::Iterator iter = list.Begin();
			(*iter).scoreData.score = 10;
			strcpy((*iter).scoreData.name, "Test1-1");
			EXPECT_NE(initScore, node.scoreData.score);
			EXPECT_NE(0, strcmp(initName, node.scoreData.name));
		}

		//1-2

		//1-3
		TEST(IteratorGetNodeTest, WhenEmptyList_GetFromBegin)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Iterator iter = list.Begin();
			EXPECT_EQ(0, list.Count());
			EXPECT_DEATH((*iter), "");
		}

		//1-4
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
	}
	//=================================== �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g ===================================
	namespace iterator_decrement_test
	{

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