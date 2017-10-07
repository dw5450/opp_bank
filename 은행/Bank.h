#ifndef __BANK_H__


#define ACCLIMITNUM 100
#define NAMELIMITNUM 50


typedef struct {
	char name[ACCLIMITNUM];
	int acc_num;
	int blance;
}acc;


void bank(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num);	// 전체 함수 총합
bool menu(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num);								// 기능 : 매뉴
void print_acc(acc Acc);					//추가 기능 : 계좌 정보 출력
int search_acc(acc Acc, const int ref_Acc_arr_num);					//추가 기능 : 계좌 정보 검색
void make_acc(acc Acc_arr[ACCLIMITNUM], int &ref_Acc_arr_num);		// 기본 기능 : 계좌 생성
void deposit(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num);		// 기본 기능 : 입금
void withdraw(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num);	// 기본 기능 : 출금
void search_all_acc(acc Acc_arr[ACCLIMITNUM], const int Acc_arr_num);	// 기본 기능 : 모든 계좌 정보 출력


#endif // !__BANK_H__
#pragma once
