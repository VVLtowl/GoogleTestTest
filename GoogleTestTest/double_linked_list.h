#pragma once
#include "ScoreData.h"

//========== �o�������X�g ==========
class DoubleLinkedList
{
public:
	//========== �m�[�h�\���� ==========
	struct Node
	{
		Node* pPrev = nullptr;			//�ڂ̃m�[�h�ւ̃|�C���^
		Node* pNext = nullptr;			//���̃m�[�h�ւ̃|�C���^
		ScoreData scoreData;			//���уf�[�^
		bool isDummy;					//�_�~�[�m�[�h���f�p

		Node();								//�R���X�g���N�^�@�_�~�[�m�[�h�Ƃ��ČĂяo������
		Node(int score, const char* name);	//�R���X�g���N�^�@�v�f�m�[�h�Ƃ��ČĂяo������
	};

	//==========  �R���X�g�C�e���[�^ ==========
	class ConstIterator
	{
	protected:
		Node* m_pNode;												// Node�v�f�ւ̃|�C���^
		const DoubleLinkedList* m_pList;							//���X�g�ւ̃|�C���^
	
	protected:
		bool IsVaild(const DoubleLinkedList* const list);			//�L���ȃC�e���[�^�ł��邩

	public:
		ConstIterator() :
			ConstIterator(nullptr, nullptr) {};
		ConstIterator(Node* node,const DoubleLinkedList* list) :
			m_pNode(node), m_pList(list) { };						//�R���X�g���N�^�ŎQ�Ƃ�ݒ�
	
		ConstIterator& operator--();								//���X�g�̐擪�Ɍ������Ĉ�i�߂�
		ConstIterator& operator++();								//���X�g�̖����Ɍ������Ĉ�i�߂�
		ConstIterator operator--(int i);							//���X�g�̐擪�Ɍ������Ĉ�i�߂�
		ConstIterator operator++(int i);							//���X�g�̖����Ɍ������Ĉ�i�߂�
		const Node& operator*()const;								//�C�e���[�^�̎w���v�f���擾����(const��)
		const Node* operator&()const;								//�w���v�f�ւ̃|�C���^���擾����(const��)
		ConstIterator(const ConstIterator& constIter);				//�R�s�[���s���i�R�s�[�R���X�g���N�^�j
		ConstIterator& operator=(const ConstIterator& constIter);	//������s��
		bool operator==(const ConstIterator& constIter);			//���ꂩ��r����
		bool operator!=(const ConstIterator& constIter);			//�قȂ邩��r����


		friend DoubleLinkedList;									//DoubleLinkedList�̊֐����ŁA�L���C�e���[�^�m�F���s���邽��
	};

	//========== �C�e���[�^ ==========
	class Iterator :public ConstIterator
	{
	public:
		Iterator() :
			Iterator(nullptr, nullptr) {};
		Iterator(Node* node,const DoubleLinkedList* list) :
			ConstIterator(node, list) {};						//�R���X�g���N�^�ŎQ�Ƃ�ݒ�

		Node& operator*();										//�C�e���[�^�̂����v�f���擾����(��const��)
		Node* operator&();										//�w���v�f�ւ̃|�C���^���擾����(��const��)
	};

private:
	Node* m_pDummy;										//�m�[�h�ւ̃|�C���^ 
	Node* HeadNode() const { return m_pDummy->pNext; };	//�擪�m�[�h�ւ̃|�C���^���擾

public:
	~DoubleLinkedList(){								//�f�X�g���N�^��`
		delete m_pDummy;
	}
	DoubleLinkedList(){									//�R���X�g���N�^��`
		m_pDummy = new Node();							
		m_pDummy->isDummy = true;
	}

	int Count()const;									//�f�[�^�����擾����
	bool PushBack(Node* newNode);						//�f�[�^�𖖔���ɒǉ�
	bool PushBack(int score,const char* name);			//�f�[�^�𖖔���ɒǉ�
	bool Insert(ConstIterator& position, Node* newNode);//�f�[�^�̑}��
	bool Remove(ConstIterator& position);				//�f�[�^�̍폜
	Iterator Begin();									//�擪�C�e���[�^�擾����
	ConstIterator CBegin()const;						//�擪�R���X�g�C�e���[�^�擾
	Iterator End();										//�����C�e���[�^�擾����
	ConstIterator CEnd()const;							//�����R���X�g�C�e���[�^�擾
};

