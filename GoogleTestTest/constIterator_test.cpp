#include "pch.h"
#include "double_linked_list.h"

//�C�e���[�^�̒P�̃e�X�g
#define GT_TEST_ITERATOR


#if defined GT_TEST_ITERATOR
//========== �C�e���[�^�P�̃e�X�g�̃e�X�g ==========
namespace iterator_auto_test
{
	//========== �C�e���[�^�̎w���v�f���擾����e�X�g ==========
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
			DoubleLinkedList::Iterator iter(&node, nullptr);//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^���쐬
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
			list.PushBack(&node);

			//�����l���擾
			int initScore = node.scoreData.score;
			char initName[WORD_SIZE];
			strcpy(initName, node.scoreData.name);

			//�ύX�O�͏����l�Ɠ���
			EXPECT_EQ(initScore, node.scoreData.score);
			EXPECT_EQ(0, strcmp(initName, node.scoreData.name));

			//Iterator����擾�����v�f�ɑ΂��āA�l����
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
		*				�R���p�C���G���[�ɂȂ邱�Ƃ��`�F�b�N���܂��B(�蓮�e�X�g)
		*/
		//TEST(IteratorGetNodeTest, WhenEmptyList_GetFromBegin)
		//{
		//	DoubleLinkedList list;
		//	DoubleLinkedList::Node node;
		//	list.PushBack(&node);
		//
		//	//Iterator����擾�����v�f�ɒl����
		//	DoubleLinkedList::Iterator iter = list.Begin();
		//	(*iter).scoreData.score = 10;
		//
		//	//ConstIterator����擾�����v�f�ɒl����
		//	DoubleLinkedList::ConstIterator constIter = list.Begin();
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
			EXPECT_EQ(0, list.Count());//���X�g����ł��邩���`�F�b�N
			DoubleLinkedList::Iterator iter = list.Begin();
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
	//========== �C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g ==========
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
			DoubleLinkedList list;//�󃊃X�g���쐬
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
			//��ȏ�̗v�f�����郊�X�g���쐬
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
			while (1)
			{
				/**
				* ���̗v�f�ւ̃|�C���^���Ɏ擾�A
				* �C�e���[�^�������������Ĉ�i�߂���w�����v�f�Ɣ�r����
				*/
				DoubleLinkedList::Node* next = (&(*iter))->pNext;
				++iter;
				if (iter == list.CEnd())break;
				else EXPECT_EQ(next, &(*iter));
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
			//��ȏ�̗v�f�����郊�X�g���쐬
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Iterator iter = list.Begin();

			/**
			* ���̗v�f�ւ̃|�C���^���Ɏ擾���A
			* �C�e���[�^�������������Ĉ�i�߂���w�����v�f�Ɣ�r����
			*/
			DoubleLinkedList::Node* next = (&(*iter))->pNext;
			++iter;
			EXPECT_EQ(next, (&(*iter)));
		}

		/**
		* @brief		��u�C���N�������g���s�����ۂ̋���
		* @detail		ID:1-10
		* 				��u�C���N�������g���s�����ۂɁA
		*				���̗v�f���w���̂����m�F���܂��B
		*/
		TEST(IteratorIncrementTest, PostIncrement)
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Iterator iter = list.Begin();

			/**
			* ���̗v�f�ւ̃|�C���^���Ɏ擾�A
			* �C�e���[�^�������������Ĉ�i�߂���w�����v�f�Ɣ�r����
			*/
			DoubleLinkedList::Node* next = (&(*iter))->pNext;
			++iter;
			EXPECT_EQ(next, (&(*iter)));
		}
	}
	//========== �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g ==========
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
		TEST(IteratorDecrementTest, WhenEmptyList_DecrementEnd)
		{
			DoubleLinkedList list;//��ł��郊�X�g���쐬
			DoubleLinkedList::Iterator iter = list.End();
			EXPECT_DEATH((--iter), "");
		}

		/**
		* @brief		�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
		* @detail		ID:1-13
		* 				�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
		*				assert�������邩���m�F���܂��B
		*/
		TEST(IteratorDecrementTest, DecrementBegin)
		{
			//�v�f�̂��郊�X�g���쐬
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			//�_�~�[�ł͂Ȃ��擪�C�e���[�^���擾
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
			//��ȏ�̗v�f�����郊�X�g���쐬
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
			--iter;//�_�~�[�m�[�h�łȂ��A�Ō�̃m�[�h����
			while (1)
			{
				/**
				* �O�̗v�f�ւ̃|�C���^���Ɏ擾�A
				* �C�e���[�^���擪�������Ĉ�i�߂���w�����v�f�Ɣ�r����
				*/
				DoubleLinkedList::Node* prev = (&(*iter))->pPrev;
				--iter;
				EXPECT_EQ(prev, (&(*iter)));

				//�w�����v�f���擪�ł���ꍇ�A���ׂĊm�F����
				if (iter == list.Begin())
				{
					break;
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
			//��ȏ�̗v�f�����郊�X�g���쐬
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Iterator iter = list.End();
			--iter;//�_�~�[�m�[�h�łȂ��A�Ō�̃m�[�h����
			/**
			* �O�̗v�f�ւ̃|�C���^���Ɏ擾�A
			* �C�e���[�^���擪�������Ĉ�i�߂���w�����v�f�Ɣ�r����
			*/
			DoubleLinkedList::Node* prev = (&(*iter))->pPrev;
			--iter;
			EXPECT_EQ(prev, (&(*iter)));
		}

		/**
		* @brief		��u�C���N�������g���s�����ۂ̋���
		* @detail		ID:1-10
		* 				��u�C���N�������g���s�����ۂɁA
		*				�O�̗v�f���w���̂����m�F���܂��B
		*/
		TEST(IteratorDecrementTest, PostDecrement)
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			DoubleLinkedList::Iterator iter = list.End();
			iter--;//�_�~�[�m�[�h�łȂ��A�Ō�̃m�[�h����
			/**
			* �O�̗v�f�ւ̃|�C���^���Ɏ擾�A
			* �C�e���[�^���擪�������Ĉ�i�߂���w�����v�f�Ɣ�r����
			*/
			DoubleLinkedList::Node* prev = (&(*iter))->pPrev;
			iter--;
			EXPECT_EQ(prev, (&(*iter)));
		}
	}
	//========== �C�e���[�^�̃R�s�[���s���e�X�g ==========
	namespace iterator_copy_test
	{
		/**
		* @brief		ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
		* @detail		ID:1-17
		* 				ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N���܂��B
		*				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F���܂��B(�蓮�e�X�g)
		*/
		//TEST(IteratorCopyTest, ConstIteratorCopyIterator)
		//{
		//	DoubleLinkedList::Iterator iter();
		//	DoubleLinkedList::ConstIterator constIter = iter;//ConstIterator����AIterator�̃R�s�[���쐬
		//}

		/**
		* @brief		�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
		* @detail		ID:1-18
		* 				�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N���܂��B
		*/
		TEST(IteratorCopyTest, AfterCopy_CheckDataEqual)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node(15,"Test1-18");	//�����l�ł͂Ȃ��v�f���쐬
			list.PushBack(&node);
			DoubleLinkedList::Iterator iter1(&node, &list);//�R�s�[�����쐬

			//�R�s�[�R���X�g���N�g����A�C�e���[�^���쐬
			DoubleLinkedList::Iterator iter2(iter1);

			//�R�s�[�ƃR�s�[���̒l���r
			EXPECT_EQ(
				(*iter1).scoreData.score,
				(*iter2).scoreData.score);
			int cmp = strcmp(
				(*iter1).scoreData.name,
				(*iter2).scoreData.name);
			EXPECT_EQ(0, cmp);
		}
	}
	//========== �C�e���[�^�̑�����s���e�X�g ==========
	namespace iterator_assign_test
	{
		/**
		* @brief		Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
		* @detail		ID:1-19
		* 				Iterator��ConstIterator�����ł��Ȃ������`�F�b�N���܂��B
		*				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F���܂��B(�蓮�e�X�g)
		*/
		//TEST(IteratorAssignTest, AssginConstIteratorToIterator)
		//{
		//	DoubleLinkedList::ConstIterator constIter;
		//	DoubleLinkedList::Iterator iter;
		//	constIter = iter;
		//	iter = constIter;
		//}

		/**
		* @brief		�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
		* @detail		ID:1-20
		* 				�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N���܂��B
		*/
		TEST(IteratorAssignTest, AfterAssign_CheckDataEqual)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node(15, "Test1-20");//�����l�ł͂Ȃ��v�f���쐬
			list.PushBack(&node);
			DoubleLinkedList::Iterator iter1(&node, &list);//�R�s�[�����쐬

			//����ŁA�C�e���[�^���R�s�[
			DoubleLinkedList::Iterator iter2;
			iter2 = iter1;

			//�R�s�[�ƃR�s�[���̒l���r
			EXPECT_EQ(
				(*iter1).scoreData.score,
				(*iter2).scoreData.score);
			int cmp = strcmp(
				(*iter1).scoreData.name,
				(*iter2).scoreData.name);
			EXPECT_EQ(0, cmp);
		}
	}
	//========== ��̃C�e���[�^������̂��̂ł��邩�A��r���s���e�X�g ==========
	namespace iterator_equal_test
	{
		/**
		* @brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
		* @detail		ID:1-21
		* 				���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂɁA
		*				true���Ԃ�ꍇ�����ł��B
		*/
		TEST(IteratorEqualTest, WhenEmptyList_CheckBeginAndEnd)
		{
			DoubleLinkedList list;

			//���X�g����̏�ԂŁA�擪���������_�~�[�ł���
			DoubleLinkedList::Iterator begin = list.Begin();
			DoubleLinkedList::Iterator end = list.End();

			EXPECT_TRUE(begin == end);
		}

		/**
		* @brief		����̃C�e���[�^���r�����ۂ̋���
		* @detail		ID:1-22
		* 				����̃C�e���[�^���r�����ۂɁA
		*				true���Ԃ�ꍇ�����ł��B
		*/
		TEST(IteratorEqualTest, WhenEmptyList_CheckSame)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			//�����v�f���w����̃C�e���[�^���쐬
			DoubleLinkedList::Iterator iter1(&node, &list);
			DoubleLinkedList::Iterator iter2(&node, &list);

			EXPECT_TRUE(iter1 == iter2);
		}

		/**
		* @brief		�قȂ�C�e���[�^���r�����ۂ̋���
		* @detail		ID:1-23
		* 				�قȂ�C�e���[�^���r�����ۂɁA
		*				false���Ԃ�ꍇ�����ł��B
		*/
		TEST(IteratorEqualTest, WhenEmptyList_CheckDifferent)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1,node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			//�قȂ�v�f���w����̃C�e���[�^���쐬
			DoubleLinkedList::Iterator iter1(&node1, &list);
			DoubleLinkedList::Iterator iter2(&node2, &list);

			EXPECT_FALSE(iter1 == iter2);
		}
	}
	//========== ��̃C�e���[�^���قȂ���̂ł��邩�A��r���s���e�X�g ==========
	namespace iterator_notEqual_test
	{
		/**
		* @brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
		* @detail		ID:1-24
		* 				���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂɁA
		*				true���Ԃ�ꍇ�����ł��B
		*/
		TEST(IteratorNotEqualTest, WhenEmptyList_CheckBeginAndEnd)
		{
			DoubleLinkedList list;

			//���X�g����̏�ԂŁA�擪���������_�~�[�ł���
			DoubleLinkedList::Iterator begin = list.Begin();
			DoubleLinkedList::Iterator end = list.End();

			EXPECT_FALSE(begin != end);
		}

		/**
		* @brief		����̃C�e���[�^���r�����ۂ̋���
		* @detail		ID:1-25
		* 				����̃C�e���[�^���r�����ۂɁA
		*				true���Ԃ�ꍇ�����ł��B
		*/
		TEST(IteratorNotEqualTest, WhenEmptyList_CheckSame)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node;
			list.PushBack(&node);

			//�����v�f���w����̃C�e���[�^���쐬
			DoubleLinkedList::Iterator iter1(&node, &list);
			DoubleLinkedList::Iterator iter2(&node, &list);

			EXPECT_FALSE(iter1 != iter2);
		}

		/**
		* @brief		�قȂ�C�e���[�^���r�����ۂ̋���
		* @detail		ID:1-26
		* 				�قȂ�C�e���[�^���r�����ۂɁA
		*				false���Ԃ�ꍇ�����ł��B
		*/
		TEST(IteratorNotEqualTest, WhenEmptyList_CheckDifferent)
		{
			DoubleLinkedList list;
			DoubleLinkedList::Node node1, node2;
			list.PushBack(&node1);
			list.PushBack(&node2);

			//�قȂ�v�f���w����̃C�e���[�^���쐬
			DoubleLinkedList::Iterator iter1(&node1, &list);
			DoubleLinkedList::Iterator iter2(&node2, &list);

			EXPECT_TRUE(iter1 != iter2);
		}
	}
}
#endif