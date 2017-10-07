#include<iostream>
#include<Windows.h>
#include"Bank.h"

using namespace std;

void bank(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num)
{
	bool Do_bank = true;
	while (Do_bank) {
		cout << "���� ���α׷��� ���� �Ͻðڽ��ϱ�?" << endl;
		cout << " ���� : Y     ���� : N" << endl;
		char select;

		cin >> select;

		if (select == 'Y' || select == 'y' || select =='��') {
			system("cls");
			Do_bank = menu(Acc_arr, ref_Acc_arr_num);
		}
		else if (select == 'N' || select == 'n' || select =='��' ){
			Do_bank = false;
		}
		else {
			cout << " �߸��� �Է��Դϴ�" << endl;
		}
	}
}

	// ��ü �Լ� ����
bool menu(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num)								// ��� : �Ŵ�
{
	int select = 0;

	cout << "���Ͻô� ����� ���� �� �ּ��� " << endl;
	cout << "���� ����	: 1 " << endl;
	cout << "��     ��	: 2 " << endl;
	cout << "��     ��	: 3" << endl;
	cout << "��ü ���� ��ȸ	: 4 " << endl;
	cout << "���α׷� ���� : 5" << endl;

	cin >> select;

	system("cls");

	if (select == 1) {
		make_acc(Acc_arr, ref_Acc_arr_num);
	}
	else if (select == 2){
		deposit(Acc_arr, ref_Acc_arr_num);
	}
	else if (select == 3) {
		withdraw(Acc_arr, ref_Acc_arr_num);

	}
	else if (select == 4) {
		search_all_acc(Acc_arr, ref_Acc_arr_num);
	}
	else if (select == 5){
		return false;
	}

	else {
		cout << "�߸��� �Է��Դϴ�. " << endl;
	}

	return true;
}

//�߰� ��� : ���� ���� ���
void print_acc(acc Acc) {
	cout << endl;
	cout << "�̸� : " << Acc.name << endl;
	cout << "���� ��ȣ : " << Acc.acc_num << endl;
	cout << "�ܾ� : " << Acc.blance << endl;
	cout << endl;

}  
 
//�߰� ��� : ���� ���� �˻� , * return ������ ���� �迭 ��ġ ��ȯ, 100�Ͻ� �ش� ���� ���� x // ���� ���� �ʿ�
int search_acc(acc Acc[ACCLIMITNUM], const int Acc_arr_num){

	int Search_acc_num;
	int Finded_acc_arr_num;

	cout << "ã���� ������ ��ȣ�� �Է��� �ּ���" << endl;
	cin >> Search_acc_num;

	
	for (Finded_acc_arr_num = 0; Finded_acc_arr_num < Acc_arr_num; Finded_acc_arr_num++){
		if (Acc[Finded_acc_arr_num].acc_num == Search_acc_num) {
			break;
		}
	}

	if (Finded_acc_arr_num == ACCLIMITNUM){
		cout << "�ش� �� ���� ��ȣ�� �����ϴ�" << endl;

	}

	return Finded_acc_arr_num;

}
void make_acc(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num)
{

	if (ref_Acc_arr_num < ACCLIMITNUM){
		cout << "�̸� �Է� " << endl;
		cin >> Acc_arr[ref_Acc_arr_num].name;

		cout << "���� ��ȣ �Է� " << endl;
		cin >> Acc_arr[ref_Acc_arr_num].acc_num;

		cout << "���� �ܾ� �Է� " << endl;
		cin >> Acc_arr[ref_Acc_arr_num].blance;

		ref_Acc_arr_num++;

		cout << "���°� ���� �Ǿ����ϴ�" << endl;
	}
	else{
		cout << "���¸� ���� �� �� �����ϴ�" << endl;
	}
	cout << endl;


}// �⺻ ��� : ���� ����
void deposit(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num)
{
	int search_num = ACCLIMITNUM;
	char q_con = 'y';
	while (search_num == ACCLIMITNUM){
		cout << "���� ��ȣ�� ��ȸ �Ͻðڽ��ϱ�?" << endl;
		cout << "���� : Y     ���� : N" << endl;
		cin >> q_con;

		if (q_con == 'Y' || q_con == 'y' || q_con == '��') {
			search_num = search_acc(Acc_arr, Acc_arr_num);

			if (search_num != ACCLIMITNUM) {
				cout << search_num << endl;
				cout << "�Ա��� �ݾ��� �Է��� �ּ��� " << endl;
				int deposit_money;
				cin >> deposit_money;

				Acc_arr[search_num].blance += deposit_money;
				cout << "�Ա��� �Ϸ�Ǿ����ϴ�." << endl;
			}
			else {
				cout << endl;
			}
		}
		else if (q_con == 'N' || q_con == 'n' || q_con == '��') {
			q_con = ACCLIMITNUM-1;
		}
		else {cout << " �߸��� �Է��Դϴ�" << endl;}
	}

}
;		// �⺻ ��� : �Ա�
void withdraw(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num)
{
	int search_num = ACCLIMITNUM;
	char q_con = 'y';
	while (search_num == ACCLIMITNUM) {
		cout << "���� ��ȣ�� ��ȸ �Ͻðڽ��ϱ�?" << endl;
		cout << "���� : Y     ���� : N" << endl;
		cin >> q_con;

		if (q_con == 'Y' || q_con == 'y' || q_con == '��') {
			search_num = search_acc(Acc_arr, Acc_arr_num);

			if (search_num != ACCLIMITNUM) {
				cout << search_num << endl;
				cout << "����� �ݾ��� �Է��� �ּ��� " << endl;
				int withdraw_money;
				cin >> withdraw_money;

				Acc_arr[search_num].blance -= withdraw_money;
				cout << "����� �Ϸ�Ǿ����ϴ�." << endl;
			}
			else {
				cout << endl;
			}
		}
		else if (q_con == 'N' || q_con == 'n' || q_con == '��') {
			q_con = ACCLIMITNUM - 1;
		}
		else { cout << " �߸��� �Է��Դϴ�" << endl; }
	}

}// �⺻ ��� : ���, ���̳ʽ� ���� ����
void search_all_acc(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num)
{
	for (int i = 0; i < Acc_arr_num; i++)
		print_acc(Acc_arr[i]);
}// �⺻ ��� : ��� ���� ���� ���