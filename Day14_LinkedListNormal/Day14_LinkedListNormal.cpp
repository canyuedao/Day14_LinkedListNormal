// Day14_LinkedListNormal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

struct Student{
	char num;
	char name[20];
	Student *next;
};
Student *pHeader=NULL;
//Student *pHeader2=NULL;
Student* insert(char num,char *name){
	Student *pStu=new Student;
	pStu->num=num;
	strcpy(pStu->name,name);
	pStu->next=NULL;
	if(!pHeader){
		pHeader=pStu;
		//pHeader2=pHeader;		
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
		/*pHeader2->next=pStu;
		pHeader2=pStu;		*/
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
int _tmain(int argc, _TCHAR* argv[])
{
	/*insert(1,"小红");
	insert(3,"小张");
	insert(2,"小明");
	insert(15,"小陈");
	insert(10,"陈新");*/
	char cOperate=0;
	int iNum;
	char cName[20];
	while(1){
		printf("添加节点请按A，删除节点请按D\n");
		scanf(" %c",&cOperate);		
		if(cOperate=='A'||cOperate=='a'){
			printf("请输入学号、学生姓名，以空格分隔\n");
			scanf("%d %s",&iNum,cName);
			insert(iNum,cName);
			printf("\n");
			for(Student* p=pHeader;p!=NULL;p=p->next){
				printf("%d %s\n",p->num,p->name);
			}
		}		
		//printf("\n");
		//remove(3);
		else if(cOperate=='D'||cOperate=='d'){
			printf("请输入要删除的学生学号\n");
			scanf("%d",&iNum);
			remove(iNum);
			printf("\n");
			if(pHeader==NULL){
				printf("无节点信息！\n");
			}
			for(Student* p=pHeader;p!=NULL;p=p->next){
				printf("%d %s\n",p->num,p->name);
			}	
		}
		else{
			printf("请输入正确的操作命令\n");
		}
	}
	
	return 0;
}

