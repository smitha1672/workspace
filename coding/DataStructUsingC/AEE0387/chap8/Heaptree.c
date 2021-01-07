/* File name: Heaptree.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <conio.h>
#define MAX 100  /* 設定上限 */

void insertFunction(void);  /* 插入函數 */
void deleteFunction(void);  /* 刪除函數 */
void displayFunction(void); /* 輸出函數 */
void create(int);     /* 建立資料於堆積樹 */
void removes(int);    /* 從堆積樹中刪除資料 */
void show(char);      /* 印出資料於螢幕 */
void adjustU(int [], int);      /* 從下而上調整資料 */
void adjustD(int [], int, int); /* 從上而下調整資料 */
void exchange(int *, int *);     /* 交換資料 */
int search(int);                 /* 搜尋資料 */
int heapTree[MAX];   /* 堆積樹陣列 */
int lastIndex = 0;   /* 最後一筆資料的INDEX */

int main()
{
	char option;
	do{
		printf("\n ***************************\n");
		printf("         <1> login\n");
		printf("         <2> logout\n");
		printf("         <3> show\n");
		printf("         <4> quit\n");
		printf(" ***************************\n");
		printf(" Please enter your choice: ");
		option = getchar();
		while (getchar()!='\n') continue;
		printf("\n");
		switch(option){
			case '1':
				insertFunction();
				break;
			case '2':
				deleteFunction();
				break;
			case '3':
				displayFunction();
				break;
			case '4':
				return 0;
				break;
			default :
				printf("\n Option error!!\n");
		} 
	} while(option != '4');
	printf("\n");
	return 0;
}

void insertFunction(void)
{
	int idTemp;
	if(lastIndex >= MAX){ /* 資料數超過上限，顯示錯誤訊息 */
		printf("\n Login members are more than %d!!\n", MAX);
		printf(" Please wait for a minute!!\n");
	}
	else{
		printf("\n Please enter login ID number: ");
		scanf("%d", &idTemp);
		while (getchar()!='\n') continue;
		create(idTemp);  /* 建立堆積 */
		printf(" Login successfully!!\n");
	}
}

void deleteFunction(void)
{
	int idTemp, delIndex;
	if(lastIndex < 1){  /* 無資料存在，顯示錯誤訊息 */
		printf("\n No member to logout!!\n");
		printf(" Please check again!!\n");
	}
	else{
		printf("\n Please enter logout ID number: ");
		scanf("%d", &idTemp);
		while (getchar()!='\n') continue;
		delIndex = search(idTemp);  /* 尋找欲刪除資料 */
		if(delIndex == 0)  /* 沒找到資料，顯示錯誤訊息 */
			printf(" ID number not found!!\n");
		else{
			removes(delIndex);  /* 刪除資料，並調整堆積 */
			printf(" ID number %d logout!!\n", idTemp);
		}
	}
}

void displayFunction(void)
{
	char option;
	if(lastIndex < 1)  /* 無資料存在，顯示錯誤訊息 */
		printf("\n No member to show!!\n");
	else{
		printf("\n ***************************\n");
		printf("        <1> increase\n");  /* 選擇第一項為由小到大排列 */
		printf("        <2> decrease\n");  /* 選擇第二項為由大到小排列 */
		printf(" ***************************\n");
		do{
			printf(" Please enter your option: ");
			option = getchar();
			while (getchar()!='\n') continue;
			printf("\n");
		} while(option != '1' && option != '2');
		show(option);
	}
}

void create(int idTemp)  /* IDTEMP為新增資料 */
{
	heapTree[++lastIndex] = idTemp;  /* 將資料新增於最後 */
	adjustU(heapTree, lastIndex);    /* 調整新增資料 */
}

void removes(int indexTemp)  /* INDEXTEMP為欲刪除資料之INDEX */
{	/* 以最後一筆資料代替刪除資料 */
	heapTree[indexTemp] = heapTree[lastIndex];
	heapTree[lastIndex--] = 0;
	if(lastIndex > 1){  /* 當資料筆數大於1筆，則做調整 */
	/* 當替代資料大於其PARENT NODE，則往上調整 */
		if(heapTree[indexTemp] > heapTree[indexTemp / 2] && indexTemp > 1)
			adjustU(heapTree, indexTemp);
		else /* 替代資料小於其CHILDEN NODE，則往下調整 */
			adjustD(heapTree, indexTemp, lastIndex-1);
	}
}

void show(char op)
{
	int heapTemp[MAX+1];
	int cIndex;
	/* 將堆積樹資料複製到另一個陣列作排序工作 */
	for(cIndex = 1; cIndex <= lastIndex; cIndex++)
		heapTemp[cIndex] = heapTree[cIndex];
	/* 將陣列調整為由小到大排列 */
	for(cIndex = lastIndex-1; cIndex > 0; cIndex--){
		exchange(&heapTemp[1], &heapTemp[cIndex+1]);
		adjustD(heapTemp, 1, cIndex);
	}
	printf("\n       ID number\n");
	printf(" =====================\n");
	/* 選擇第一種方式輸出，以遞增方式輸出--使用堆疊
	   選擇第二種方式輸出，以遞減方式輸出--使用佇列 */
	switch(op){
		case '1':
			for(cIndex = 1; cIndex <= lastIndex; cIndex++)
				printf("%14d\n", heapTemp[cIndex]);
			break;
		case '2':
			for(cIndex = lastIndex; cIndex > 0; cIndex--)
				printf("%14d\n", heapTemp[cIndex]);
			break;
	}
	printf(" =====================\n");
	printf(" Total member: %d\n", lastIndex);
}

void adjustU(int temp[], int index)  /* INDEX為目前資料在陣列之INDEX */
{
	while(index > 1){ /* 將資料往上調整至根為止 */
		if(temp[index] <= temp[index/2])  /* 資料調整完畢就跳出，否則交換資料 */
			break;
		else
			exchange(&temp[index], &temp[index/2]);
		index /= 2;
	}
}

/* INDEX1為目前資料在陣列之INDEX，INDEX2為最後一筆資料在陣列之INDEX */
void adjustD(int temp[], int index1, int index2)
{	/* IDTEMP記錄目前資料，INDEXTEMP則是目前資料之CHILDEN NODE的INDEX */
	int idTemp, indexTemp;
	idTemp = temp[index1];
	indexTemp = index1 * 2;
	/* 當比較資料之INDEX不大於最後一筆資料之INDEX，則繼續比較 */
	while(indexTemp <= index2){
		if((indexTemp < index2) && (temp[indexTemp] < 										temp[indexTemp+1]))
			indexTemp++;  /* INDEXTEMP記錄目前資料之CHILDEN NODE中較大者 */
		if(idTemp >= temp[indexTemp])  /* 比較完畢則跳出，否則交換資料	*/
			break;
		else{
			temp[indexTemp/2] = temp[indexTemp];
			indexTemp *= 2;
		}
	}
	temp[indexTemp/2] = idTemp;
}

void exchange(int *id1, int *id2)  /* 交換傳來之ID1及ID2儲存之資料 */
{
	int idTemp;
	idTemp = *id1;
	*id1 = *id2;
	*id2 = idTemp;
}

int search(int idTemp)  /* 尋找陣列中IDTEMP所在 */
{
	int cIndex;
	for(cIndex = 1; cIndex <= MAX; cIndex++)
		if(idTemp == heapTree[cIndex])
			return cIndex;  /* 找到則回傳資料在陣列中之INDEX */
	return 0;  /* 沒找到則回傳0 */
}