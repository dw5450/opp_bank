#ifndef __BANK_H__


#define ACCLIMITNUM 100
#define NAMELIMITNUM 50


typedef struct {
	char name[ACCLIMITNUM];
	int acc_num;
	int blance;
}acc;


void bank(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num);	// ��ü �Լ� ����
bool menu(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num);								// ��� : �Ŵ�
void print_acc(acc Acc);					//�߰� ��� : ���� ���� ���
int search_acc(acc Acc, const int ref_Acc_arr_num);					//�߰� ��� : ���� ���� �˻�
void make_acc(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num);		// �⺻ ��� : ���� ����
void deposit(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num);		// �⺻ ��� : �Ա�
void withdraw(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num);	// �⺻ ��� : ���
void search_all_acc(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num);	// �⺻ ��� : ��� ���� ���� ���


#endif // !__BANK_H__
#pragma once
