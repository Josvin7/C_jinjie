#ifndef __CONTACT_H__ 
#define __CONTACT_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>


#define SIZE  128
#define TOTAL  1000
#pragma warning(disable:4996)
// 姓名、性别、年龄、电话、住址
typedef  struct person {
	char name[SIZE/4];
	char sex;//f,m
	int age;
	char tel[SIZE/4];
	char address[SIZE];
}person_t;


typedef struct  contact {
	int size;//当前通讯录人数
	int cap;//通讯录最大存储人数
	person_t persons[TOTAL];
}contact_t;

void AddPerson(contact_t *ct);
void DeletePerson(contact_t *ct);
void SearchPerson(contact_t *ct);
void ShowContact(contact_t *ct, int index);// index = -1输出所有；index >=0 单独输出
void ModPerson(contact_t *ct);
void ClsPerson(contact_t *ct);
void SortPerson(contact_t *ct);


#endif