#include "contact.h"

// �����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��


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
			ShowContact(&ct, -1);//�����ﷵ��-1����������ʾ�����б���ֻ�ǵ�����ʾһ����Ϣ
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