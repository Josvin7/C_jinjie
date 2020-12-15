#include "contact.h"

static int IsFull(contact_t *ct) {
	assert(ct);
	return ct->size == ct->cap;
}

static int IsExist(contact_t *ct, const char *tel) {
	assert(tel);

	person_t *end = ct->persons + ct->size;
	int index = 0;
	for (person_t *p = ct->persons; p < end; p++,index++) {
		if (0 == strcmp(p->tel,tel)) {
			return index;

		}
	}
	return -1;

}
static void SearchPersonTelHelper(contact_t *ct) {
	assert(ct);

	char  search_key[SIZE/4];
	printf("��������Ҫ���ҵĵ绰����# ");
	scanf("%s",search_key);
	int index = IsExist(ct, search_key);
	if (-1 == index) {
		printf("��Ҫ���ҵ��ˡ�%s�������ڣ�\n",search_key);

		return;
	}
	else {
		//����˵���Ѿ����ҵ��ˡ����ص�index�������������˵��±�
		ShowContact(ct,index);
	}
}

static int CompPerson(const void *x, const  void *y) {
	person_t *x_p = (person_t *)x;
	person_t *y_p = (person_t *)y;

	return strcmp(x_p->name,y_p->name);

}


void AddPerson(contact_t *ct) {
	assert(ct);
	// ���1����ͨѶ¼���˵�ʱ�򣬽����ʧ��
	if (IsFull(ct)) {
		printf("contact is Full!\n");
		return;

	}
	person_t *p = ct->persons + ct->size;
	printf("����# ");
	scanf("	%s",p->name);
	printf("�绰# ");
	scanf("	%s", p->tel);

	// ���2��ͨ���绰�������Ҫ��������Ƿ����
	if (IsExist(ct,p->tel) >= 0) {// ��������ڵĻ����ص������ı꣬�������򷵻�-1
		printf("%s is exist!\n",p->name);
		return;
	}
	//��������˾�ֱ�ӷ����Ƴ�����������������û����������Ϣ
	printf("�Ա�# ");
	scanf("	%c", &(p->sex));
	printf("���# ");
	scanf("	%d", &(p->age));
	printf("��ַ# ");
	scanf("	%s", p->address);
	ct->size += 1;
	printf("... add success!\n");
	
}



void DeletePerson(contact_t *ct) {
	assert(ct);

	char  del_key[SIZE/4];//������ͨ���绰�Ų�ѯ
	printf("������Ҫɾ���˵ĵ绰����# ");
	scanf("%s",del_key);//�����������ַ
	// ������Ҫ���в��ҿ��Ƿ���ڣ������ſ��Խ���ɾ��
	int index = 0;
	if ((index = IsExist(ct,del_key)) >= 0) {//ע�����ķ���ֵ����Ҳ��ΪʲĪ������ֵ����Ϊ�±��ԭ��
		// ɾ������
		ct->persons[index] = ct->persons[ct->size - 1];//����ֱ�ӽ�persons�����һ���˵���Ϣ���ǵ�indexλ�õ�
		ct->size -= 1;//�ڽ���size--

	}
	else {
		//˵�������ڣ�ֱ�ӷ��ؼ���
		printf("��Ҫɾ�����û� ��%s�����ǲ����ڵģ�\n",del_key);
	}
}


void SearchPerson(contact_t *ct) {
	assert(ct);

	printf("#######################################\n");
	printf("##   1.����������ѯ  2.���յ绰��ѯ  ##\n");
	printf("#######################################\n");
	printf("select:> ");
	int select = 0;
	scanf("%d",&select);
	switch (select) {
	case 1:
		//
		break;
	case 2:
		SearchPersonTelHelper(ct);
		break;
	}
}


void ModPerson(contact_t *ct) {
	assert(ct);
	//
	printf("#######################################\n");
	printf("##   1.�޸�����          2.�޸��Ա�  ##\n");
	printf("##   3.�޸ĵ绰          4.�޸�����  ##\n");
	printf("##   5.�޸ĵ�ַ                      ##\n");
	printf("#######################################\n");
	printf("select:> ");
	int select = 0;
	scanf("%d",&select);
	switch (select){
	case 1:
		//�޸�����
		//ModPersonName(ct);
		break;
	case 2:
		//�޸��Ա�
		break;
	case 3:
		//�޸ĵ绰
		break;
	case 4:
		//�޸�����
		break;
	case 5:
		//�޸ĵ�ַ
		break;
	default:
		break;
	}

}
void ClsPerson(contact_t *ct) {
	assert(ct);
	// ������ɾ��ֻ��Ҫ��size��Ϊ0
	ct->size = 0;
}
void SortPerson(contact_t *ct) {
	assert(ct);
	qsort(ct->persons,ct->size,sizeof(person_t),CompPerson);
}



void ShowContact(contact_t *ct, int index) {
	// index = -1������У�index >=0 ������� 
	assert(ct);
	if (-1 == index) {
		person_t *end = ct->persons + ct->size;
		//����  �Ա�  ����  �绰  ��ַ
		printf("ͳ�ƣ�%d/%d\n",ct->size,ct->cap);
		printf("-------------------------------------------------------\n");
		for (person_t *p = ct->persons; p < end; p++) {
			printf("|%-8s|%-2c|%-3d|%-11s|%-10s|\n",p->name,p->sex,p->age,p->tel,p->address);

		}
		printf("-------------------------------------------------------\n");

	}
	else {
		person_t *p = ct->persons + index;
		printf("|%-8s|%-2c|%-3d|%-11s|%-10s|\n", p->name, p->sex, p->age, p->tel, p->address);
	}


}