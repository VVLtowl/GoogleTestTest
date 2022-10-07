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
		* 				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂɁAassert�������܂��B
		*/
		TEST(IteratorIncrementTest, WhenNoReference)
		{
			DoubleLinkedList::Node node;
			DoubleLinkedList::Iterator iter(&node, nullptr);
			EXPECT_DEATH((*iter), "");
		}
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