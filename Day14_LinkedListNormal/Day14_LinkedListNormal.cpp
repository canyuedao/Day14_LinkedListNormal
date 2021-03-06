// Day14_LinkedListNormal.cpp : 定义控制台应用程序的入口点。

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
	//Student *pHeaderOld=pHeader;
	//Student *pTmp;//指示位置的临时指针
	Student *pNext=NULL;//保存每次循环初始时的pHeader指针
	Student *pPre=NULL;//保存每次循环的上一次pHeader指针
	while(pHeader!=NULL){
		pNext=pHeader;//保存每次循环初始时的pHeader指针
		pHeader=pHeader->next;//每次循环将头节点向后移
		pNext->next=pPre;//将本次循环初始时的pHeader的next指向前，即上一次的pHeader指针
		pPre=pNext;//保存每次循环的上一次pHeader指针
	}
	pHeader=pNext;
	//第二次优化掉的代码
	//for(Student *pH=pHeaderOld;pH->next!=NULL;pH=pH->next){
	//	if(pH->next->next==NULL){
	//		pHeader=pH->next;
	//		pHeader->next=pH;
	//		pH->next=NULL;
	//		pTmp=pH;//修改
	//		break;
	//	}
	//}
	//while(pHeaderOld->next!=NULL){
	//	for(Student *pHO=pHeaderOld;pHO->next!=NULL;pHO=pHO->next){
	//		if(pHO->next==pTmp){
	//			pTmp->next=pHO;
	//			pTmp=pHO;
	//			pHO->next=NULL;
	//			break;
	//		}
	//	}
		//第一次优化掉的代码
		/*Student *pHO=pHeaderOld;
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
		}*/
		//第一次优化结束
	//}
	//第二次优化结束
	return pHeader;

}
int _tmain(int argc, _TCHAR* argv[])
{
	char cOperate=0;
	int iNum;
	char cName[20];
	//反转测试
	insert(1,"小红");
	insert(2,"小明");
	insert(3,"小张");
	insert(4,"小陈");
	for(Student *p=pHeader;p!=NULL;p=p->next){
		printf("%d %s\n",p->num,p->name);
	}
	reverse();
	printf("反转后的节点信息为：\n");
	for(Student *p=pHeader;p!=NULL;p=p->next){
		printf("%d %s\n",p->num,p->name);
	}
	//测试结束
	//添加删除节点
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

