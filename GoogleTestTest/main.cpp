#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "double_linked_list.h"
using namespace std;


/**main�֐�*/
int main(void)
{
	/**�f�[�^���i�[���߂̃��X�g��p��*/
	DoubleLinkedList list;

	/**�t�@�C����ǂݍ��݁A�f�[�^���i�[ */
	{
		FILE* fp;
		char fileName[] = "Scores.txt";

		int score;					/**<�X�R�A�f�[�^���ꎞ�i�[�p*/
		char name[WORD_SIZE];		/**<���O�f�[�^���ꎞ�i�[�p*/

		/**�t�@�C�����J���A���s�����NULL��Ԃ�*/
		fp = fopen(fileName, "r");
		if (fp == NULL) {
			cout << fileName << "file open error!" << endl;
			return -1;
		}
		else {
			cout << fileName << "file opened!" << endl;
		}

		/**
		* ���[�v��1�s���ǂݎ�������e���f�[�^�Ɋi�[�A
		* ���e�����Ȃ��ꍇ���[�v�I��
		*/
		while (fscanf(fp, "%d\t%s", &score, name) != EOF) {

			/**1�s���ǂݎ�������e���m�F*/
#if 0
			cout << name << ":" << score << endl;//test
#endif

		/**�X�R�A�f�[�^�𐶐����āA�R�s�[�Ńf�[�^���i�[*/
			DoubleLinkedList::Node* newNode =
				new DoubleLinkedList::Node;
			strcpy(newNode->scoreData.name, name);
			newNode->scoreData.score = score;

			list.PushBack(newNode);
		}

		fclose(fp);
	}

	/**�C�e���[�g���āu�i�[�������Łv�W���o�͂ɕ\��*/
	{
		//test
#if 0
		DoubleLinkedList::Node* node = list.GetHead();
		if (node == nullptr)return -2;
		do {
			cout << node->scoreData.name
				<< (node->scoreData.name.size() < 8 ? "\t\t:" : "\t:")
				<< node->scoreData.score << endl;
		} while ((node = node->next) != nullptr);

#endif // DEBUG

		
#if 1
		DoubleLinkedList::Iterator it = list.Head();
		DoubleLinkedList::Iterator tail = list.Tail();
		//DoubleLinkedList::ConstIterator it = list.ConstHead();
		//DoubleLinkedList::ConstIterator tail= list.ConstTail();
		DoubleLinkedList::Node* node = nullptr;
		while (1)
		{
			if ((node = it.GetNode()) != nullptr)
			{
				cout << node->scoreData.name
					<< (strlen( node->scoreData.name)< 8 ? "\t\t:" : "\t:")
					<< node->scoreData.score << endl;
			}

			if (it != tail)
			{
				++it;
			}
			else
			{
				break;
			}
		}
#endif
	}

	(void)getchar();
	return 0;
}

