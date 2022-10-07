#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "double_linked_list.h"
using namespace std;


/**main関数*/
int main(void)
{
	/**データを格納ためのリストを用意*/
	DoubleLinkedList list;

	/**ファイルを読み込み、データを格納 */
	{
		FILE* fp;
		char fileName[] = "Scores.txt";

		int score;					/**<スコアデータを一時格納用*/
		char name[WORD_SIZE];		/**<名前データを一時格納用*/

		/**ファイルを開く、失敗するとNULLを返す*/
		fp = fopen(fileName, "r");
		if (fp == NULL) {
			cout << fileName << "file open error!" << endl;
			return -1;
		}
		else {
			cout << fileName << "file opened!" << endl;
		}

		/**
		* ループで1行ずつ読み取った内容をデータに格納、
		* 内容が取らない場合ループ終了
		*/
		while (fscanf(fp, "%d\t%s", &score, name) != EOF) {

			/**1行ずつ読み取った内容を確認*/
#if 0
			cout << name << ":" << score << endl;//test
#endif

		/**スコアデータを生成して、コピーでデータを格納*/
			DoubleLinkedList::Node* newNode =
				new DoubleLinkedList::Node;
			strcpy(newNode->scoreData.name, name);
			newNode->scoreData.score = score;

			list.PushBack(newNode);
		}

		fclose(fp);
	}

	/**イテレートして「格納した順で」標準出力に表示*/
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

