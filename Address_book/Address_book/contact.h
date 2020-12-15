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
// �������Ա����䡢�绰��סַ
typedef  struct person {
	char name[SIZE/4];
	char sex;//f,m
	int age;
	char tel[SIZE/4];
	char address[SIZE];
}person_t;


typedef struct  contact {
	int size;//��ǰͨѶ¼����
	int cap;//ͨѶ¼���洢����
	person_t persons[TOTAL];
}contact_t;

void AddPerson(contact_t *ct);
void DeletePerson(contact_t *ct);
void SearchPerson(contact_t *ct);
void ShowContact(contact_t *ct, int index);// index = -1������У�index >=0 �������
void ModPerson(contact_t *ct);
void ClsPerson(contact_t *ct);
void SortPerson(contact_t *ct);


#endif