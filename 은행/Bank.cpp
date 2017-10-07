#include<iostream>
#include<Windows.h>
#include"Bank.h"

using namespace std;

void bank(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num)
{
	bool Do_bank = true;
	while (Do_bank) {
		cout << "은행 프로그램을 실행 하시겠습니까?" << endl;
		cout << " 진행 : Y     종료 : N" << endl;
		char select;

		cin >> select;

		if (select == 'Y' || select == 'y' || select =='ㅛ') {
			system("cls");
			Do_bank = menu(Acc_arr, ref_Acc_arr_num);
		}
		else if (select == 'N' || select == 'n' || select =='ㅜ' ){
			Do_bank = false;
		}
		else {
			cout << " 잘못된 입력입니다" << endl;
		}
	}
}

	// 전체 함수 총합
bool menu(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num)								// 기능 : 매뉴
{
	int select = 0;

	cout << "원하시는 기능을 선택 해 주세요 " << endl;
	cout << "계좌 생성	: 1 " << endl;
	cout << "입     금	: 2 " << endl;
	cout << "출     금	: 3" << endl;
	cout << "전체 계좌 조회	: 4 " << endl;
	cout << "프로그램 종료 : 5" << endl;

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
		cout << "잘못된 입력입니다. " << endl;
	}

	return true;
}

//추가 기능 : 계좌 정보 출력
void print_acc(acc Acc) {
	cout << endl;
	cout << "이름 : " << Acc.name << endl;
	cout << "계좌 번호 : " << Acc.acc_num << endl;
	cout << "잔액 : " << Acc.blance << endl;
	cout << endl;

}  
 
//추가 기능 : 계좌 정보 검색 , * return 값으로 계좌 배열 위치 반환, 100일시 해당 계좌 존재 x // 추후 수정 필요
int search_acc(acc Acc[ACCLIMITNUM], const int Acc_arr_num){

	int Search_acc_num;
	int Finded_acc_arr_num;

	cout << "찾으실 계좌의 번호를 입력해 주세요" << endl;
	cin >> Search_acc_num;

	
	for (Finded_acc_arr_num = 0; Finded_acc_arr_num < Acc_arr_num; Finded_acc_arr_num++){
		if (Acc[Finded_acc_arr_num].acc_num == Search_acc_num) {
			break;
		}
	}

	if (Finded_acc_arr_num == ACCLIMITNUM){
		cout << "해당 된 계좌 번호가 없습니다" << endl;

	}

	return Finded_acc_arr_num;

}
void make_acc(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num)
{

	if (ref_Acc_arr_num < ACCLIMITNUM){
		cout << "이름 입력 " << endl;
		cin >> Acc_arr[ref_Acc_arr_num].name;

		cout << "계좌 번호 입력 " << endl;
		cin >> Acc_arr[ref_Acc_arr_num].acc_num;

		cout << "시작 잔액 입력 " << endl;
		cin >> Acc_arr[ref_Acc_arr_num].blance;

		ref_Acc_arr_num++;

		cout << "계좌가 생성 되었습니다" << endl;
	}
	else{
		cout << "계좌를 생성 할 수 없습니다" << endl;
	}
	cout << endl;


}// 기본 기능 : 계좌 생성
void deposit(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num)
{
	int search_num = ACCLIMITNUM;
	char q_con = 'y';
	while (search_num == ACCLIMITNUM){
		cout << "계좌 번호를 조회 하시겠습니까?" << endl;
		cout << "진행 : Y     종료 : N" << endl;
		cin >> q_con;

		if (q_con == 'Y' || q_con == 'y' || q_con == 'ㅛ') {
			search_num = search_acc(Acc_arr, Acc_arr_num);

			if (search_num != ACCLIMITNUM) {
				cout << search_num << endl;
				cout << "입금할 금액을 입력해 주세요 " << endl;
				int deposit_money;
				cin >> deposit_money;

				Acc_arr[search_num].blance += deposit_money;
				cout << "입금이 완료되었습니다." << endl;
			}
			else {
				cout << endl;
			}
		}
		else if (q_con == 'N' || q_con == 'n' || q_con == 'ㅜ') {
			q_con = ACCLIMITNUM-1;
		}
		else {cout << " 잘못된 입력입니다" << endl;}
	}

}
;		// 기본 기능 : 입금
void withdraw(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num)
{
	int search_num = ACCLIMITNUM;
	char q_con = 'y';
	while (search_num == ACCLIMITNUM) {
		cout << "계좌 번호를 조회 하시겠습니까?" << endl;
		cout << "진행 : Y     종료 : N" << endl;
		cin >> q_con;

		if (q_con == 'Y' || q_con == 'y' || q_con == 'ㅛ') {
			search_num = search_acc(Acc_arr, Acc_arr_num);

			if (search_num != ACCLIMITNUM) {
				cout << search_num << endl;
				cout << "출금할 금액을 입력해 주세요 " << endl;
				int withdraw_money;
				cin >> withdraw_money;

				Acc_arr[search_num].blance -= withdraw_money;
				cout << "출금이 완료되었습니다." << endl;
			}
			else {
				cout << endl;
			}
		}
		else if (q_con == 'N' || q_con == 'n' || q_con == 'ㅜ') {
			q_con = ACCLIMITNUM - 1;
		}
		else { cout << " 잘못된 입력입니다" << endl; }
	}

}// 기본 기능 : 출금, 마이너스 통장 가능
void search_all_acc(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num)
{
	for (int i = 0; i < Acc_arr_num; i++)
		print_acc(Acc_arr[i]);
}// 기본 기능 : 모든 계좌 정보 출력