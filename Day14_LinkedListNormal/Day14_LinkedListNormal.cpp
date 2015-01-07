// Day14_LinkedListNormal.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <string.h>

struct Student{
	char num;
	char name[20];
	Student *next;
};
Student *pHeader=NULL;
Student* insert(char num,char *name){
	Student *pStu=new Student;
	pStu->num=num;
	strcpy(pStu->name,name);
	pStu->next=NULL;
	if(!pHeader){
		pHeader=pStu;	
	}
	else{
		for (Student* p=pHeader;p!=NULL;p=p->next)
		{
			if(p->num==num){
				return pHeader;
			}
			if(pHeader->num>num){
				Student *ph=pHeader;
				pHeader=pStu;
				pHeader->next=ph;
				return pHeader;
			}
			if(p->next==NULL){
				p->next=pStu;
				return pHeader;
			}
			if((p->num<num)&&(p->next->num>num)){
				pStu->next=p->next;
				p->next=pStu;
				return pHeader;
			}			
		}
	}
	return pHeader;
}

Student* remove(char num){
	if(!pHeader){
		return pHeader;
	}
	if(pHeader->next==NULL){
		Student *ph=pHeader;
		delete ph;
		pHeader=NULL;
		return pHeader;
	}
	for(Student* p=pHeader;p->next!=NULL;p=p->next){

		if(pHeader->num==num){
			Student *ph=pHeader;
			pHeader=pHeader->next;
			delete ph;
			return pHeader;
		}
		if(p->next->num==num){

			if(p->next->next==NULL){
				p->next=NULL;
				delete p->next;
			}
			else{
				Student *pNext=p->next;
				p->next=p->next->next;
				delete pNext;
			}
			return pHeader;
		}
	}
	return pHeader;
}

Student* reverse(){
	Student *pHeaderOld=pHeader;
	for(Student *pH=pHeaderOld;pH->next!=NULL;pH=pH->next){
		if(pH->next->next==NULL){
			pHeader=pH->next;
			pHeader->next=pH;
			pH->next=NULL;
			break;
		}
	}
	/*for(Student *pHO=pHeaderOld;pHO->next!=NULL;pHO=pHO->next){
		for(Student *pHN=pHeader;pHN->next!=NULL;pHN=pHN->next){
			if(pHO->next==pHN)
		}
	}*/
	while(pHeaderOld->next!=NULL){
		Student *pHO=pHeaderOld;
		for(;pHO->next!=NULL;pHO=pHO->next){
			if(pHO->next->next==NULL){
				pHO->next=NULL;
				break;
			}
		}
		Student *pHN=pHeader;
		for(;pHN!=NULL;pHN=pHN->next){
			if(pHN->next==NULL){
				pHN->next=pHO;
				break;
			}
		}
	}
	return pHeader;

}
int _tmain(int argc, _TCHAR* argv[])
{
	char cOperate=0;
	int iNum;
	char cName[20];
	//��ת����
	insert(1,"С��");
	insert(2,"С��");
	insert(3,"С��");
	for(Student *p=pHeader;p!=NULL;p=p->next){
		printf("%d %s\n",p->num,p->name);
	}
	reverse();
	printf("��ת��Ľڵ���ϢΪ��\n");
	for(Student *p=pHeader;p!=NULL;p=p->next){
		printf("%d %s\n",p->num,p->name);
	}
	//���Խ���
	//���ɾ���ڵ�
	while(1){
		printf("��ӽڵ��밴A��ɾ���ڵ��밴D\n");
		scanf(" %c",&cOperate);		
		if(cOperate=='A'||cOperate=='a'){
			printf("������ѧ�š�ѧ���������Կո�ָ�\n");
			scanf("%d %s",&iNum,cName);
			insert(iNum,cName);
			printf("\n");
			for(Student* p=pHeader;p!=NULL;p=p->next){
				printf("%d %s\n",p->num,p->name);
			}
		}		
		else if(cOperate=='D'||cOperate=='d'){
			printf("������Ҫɾ����ѧ��ѧ��\n");
			scanf("%d",&iNum);
			remove(iNum);
			printf("\n");
			if(pHeader==NULL){
				printf("�޽ڵ���Ϣ��\n");
			}
			for(Student* p=pHeader;p!=NULL;p=p->next){
				printf("%d %s\n",p->num,p->name);
			}	
		}
		else{
			printf("��������ȷ�Ĳ�������\n");
		}
	}	
	return 0;
}

