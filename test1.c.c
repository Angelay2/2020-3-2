#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <windows.h>

#pragma warning(disable:4996)
//1.һ��������ֻ������1���������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�

//return value: 0:success, other:failed
//args: a:�������飬num: Ԫ�صĸ����� xp(yp):����Ͳ����� ͨ����ָ�룬��ö�Ӧ�����ֵ
int FindTowData(int a[], int num, int *xp, int *yp)
{
	assert(a);
	assert(num >= 2);
	assert(xp);
	assert(yp);
	*xp = 0;
	*yp = 0;

	//A
	int result = a[0];
	int i = 1;
	for (; i < num; i++){
		result ^= a[i];
	}
	if (result == 0){
		return 1;
	}

	//B
	i = 0;
	int flag = 1;//0000 0001
	while (i < 8 * sizeof(int)){
		//�����飺flag<<=i;
		if (result & (flag<<i)){ // flag<<i �᲻��Ӱ��flag��ֵ�أ����ᣡ�� x+=10
			break;
		}
		i++;
	}
	//C
	flag <<= i; //һ���ӣ���
	//flag �ͱ�ʶ�˲���ͬ���Ǹ�����λ��
	for (i = 0; i < num; i++){
		if (a[i] & flag){ //A
			*xp ^= a[i];
		}
		else{ //B
			*yp ^= a[i];
		}
	}
	return 0;
}

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Ժȶ�����ˮ��
//���ʵ�֡�
//return : total drink
//money : Ǯ��
int DrinkWater(int money)
{
	int total = money;
	int empty = money;

	while (empty > 1){	
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("empty: %d\n", empty);//0?
	return total;
	//return total + 1; //�������ϰ��һ����ƿ�ӣ������꣬�ٻ�������
}

void Reverse(char *start, char *end)
{
	assert(start);
	assert(end);
	while (start < end){
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		start++, end--;
	}
}
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
void LeftMove(char *str, int len, int n)
{
	assert(str);
	assert(len > 0);
	assert(n > 0);

	int step = n % len;
	if (step == 0){
		return;
	}

	//1
	//int i = 0;
	//for (; i < step; i++){
	//	char c = str[0];
	//	int j = 1;
	//	for (; j < len; j++){
	//		str[j - 1] = str[j];
	//	}
	//	str[j - 1] = c;
	//}
	//2:�Ƽ�
	//Reverse(str, str + step - 1);
	//Reverse(str + step, str + len - 1);
	//Reverse(str, str + len - 1);
	//3
	char *mem = (char*)malloc(2 * len + 1);
	if (!mem){
		return;
	}
	strcpy(mem, str);
	strcat(mem, str);
	strncpy(str, mem+step, len);

	free(mem);
}

int main()
{
	char str[] = "1234abcd";
	LeftMove(str, strlen(str), 4000);
	printf("%s\n", str);


	//int money = 20;
	//int total = DrinkWater(money);
	//printf("total: %d\n", total);
	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1, 13, 45 };
	////int a[] = { 1, 2, 2, 1, 13, 45 };
	//int num = sizeof(a) / sizeof(a[0]);
	//int x, y;
	//if (FindTowData(a, num, &x,&y) == 0){ //success
	//	printf("find success : %d, %d\n", x, y);
	//}
	system("pause");
	return 0;
}