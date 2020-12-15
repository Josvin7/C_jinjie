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
	printf("请输入你要查找的电话号码# ");
	scanf("%s",search_key);
	int index = IsExist(ct, search_key);
	if (-1 == index) {
		printf("你要查找的人【%s】不存在！\n",search_key);

		return;
	}
	else {
		//这里说明已经查找到了。返回的index就是你所查找人的下标
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
	// 情况1：当通讯录满了的时候，将添加失败
	if (IsFull(ct)) {
		printf("contact is Full!\n");
		return;

	}
	person_t *p = ct->persons + ct->size;
	printf("姓名# ");
	scanf("	%s",p->name);
	printf("电话# ");
	scanf("	%s", p->tel);

	// 情况2：通过电话号码查找要插入的人是否存在
	if (IsExist(ct,p->tel) >= 0) {// 在这里存在的话返回的是他的标，不存在则返回-1
		printf("%s is exist!\n",p->name);
		return;
	}
	//如果存在了就直接返回推出，不存在则继续让用户输入相关信息
	printf("性别# ");
	scanf("	%c", &(p->sex));
	printf("年纪# ");
	scanf("	%d", &(p->age));
	printf("地址# ");
	scanf("	%s", p->address);
	ct->size += 1;
	printf("... add success!\n");
	
}



void DeletePerson(contact_t *ct) {
	assert(ct);

	char  del_key[SIZE/4];//在这里通过电话号查询
	printf("请输入要删除人的电话号码# ");
	scanf("%s",del_key);//数组名代表地址
	// 在这里要进行查找看是否存在，这样才可以进行删除
	int index = 0;
	if ((index = IsExist(ct,del_key)) >= 0) {//注意他的返回值，这也是为什莫将返回值设置为下标的原因
		// 删除操作
		ct->persons[index] = ct->persons[ct->size - 1];//在这直接将persons中最后一个人的信息覆盖掉index位置的
		ct->size -= 1;//在进行size--

	}
	else {
		//说明不存在，直接返回即可
		printf("你要删除的用户 【%s】，是不存在的！\n",del_key);
	}
}


void SearchPerson(contact_t *ct) {
	assert(ct);

	printf("#######################################\n");
	printf("##   1.按照姓名查询  2.按照电话查询  ##\n");
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
	printf("##   1.修改姓名          2.修改性别  ##\n");
	printf("##   3.修改电话          4.修改年龄  ##\n");
	printf("##   5.修改地址                      ##\n");
	printf("#######################################\n");
	printf("select:> ");
	int select = 0;
	scanf("%d",&select);
	switch (select){
	case 1:
		//修改姓名
		//ModPersonName(ct);
		break;
	case 2:
		//修改性别
		break;
	case 3:
		//修改电话
		break;
	case 4:
		//修改年龄
		break;
	case 5:
		//修改地址
		break;
	default:
		break;
	}

}
void ClsPerson(contact_t *ct) {
	assert(ct);
	// 在这里删除只需要将size置为0
	ct->size = 0;
}
void SortPerson(contact_t *ct) {
	assert(ct);
	qsort(ct->persons,ct->size,sizeof(person_t),CompPerson);
}



void ShowContact(contact_t *ct, int index) {
	// index = -1输出所有；index >=0 单独输出 
	assert(ct);
	if (-1 == index) {
		person_t *end = ct->persons + ct->size;
		//姓名  性别  年龄  电话  地址
		printf("统计：%d/%d\n",ct->size,ct->cap);
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