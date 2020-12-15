#include "contact.h"

// 添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人


static void Menu() {
	printf("#######################################\n");
	printf("##    1.Add                2.Del     ##\n");
	printf("##    3.Search             4.Mod     ##\n");
	printf("##    5.Show               6.Cls     ##\n");
	printf("##    7.Sort               0.Quit    ##\n");
	printf("#######################################\n");
	printf("Please Select:>  ");
	

}

int main() {
	contact_t ct;
	memset(&ct,0,sizeof(ct));
	ct.cap = TOTAL;

	int quit = 0;
	int select = 0;
	while (!quit) {
		Menu();
		scanf("%d",&select);
		switch (select) {
		case 1://add
			AddPerson(&ct);
			break;
		case 2://del
			DeletePerson(&ct);
			break;
		case 3://search
			SearchPerson(&ct);
			break;
		case 4://mod
			ModPerson(&ct);
			break;
		case 5://show
			ShowContact(&ct, -1);//在这里返回-1是区分是显示所有列表还是只是单独显示一条信息
			break;
		case 6://cls
			ClsPerson(&ct);
			break;
		case 7://sort
			SortPerson(&ct);
			break;
		default://quit
			quit = 1;
			break;
		
		}
	}


	system("pause");
	return 0;
}