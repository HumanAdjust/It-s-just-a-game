#include<stdio.h>//standard input output
#include <stdlib.h>//standard library 여기에 rand함수가 들어가 있다.
#include<string.h>
#include<windows.h>//화면 클리어가 들어있다 printf("cls");
int main(void)
{
	int cho, hp, damage, per, today = 1, i, j, pati = 0, map, weapon, defense, mhp, work, mdamage, temp, iper;//patigue 피로 choice 선택 percent 퍼센트 chracter 캐릭터 mhp 몬스터hp
	char YN;
	char item[100], monster[10], job[10];
	//아이템을 얻을 때 rand함수를 0부터 100까지 하고 어디부터 어디까지는 어떤 아이템을 얻을 수 있도록 한다! 
	//예를 들어 1~10까지 1번 아이템을 얻는다고 했을 때 100이 최대니깐 얻을 확률은 10%이다. 
	while (1)//직업 선택
	{
	resurrection:

		printf("캐릭터를 선택하십시오.\n1. 전사  2. 궁수  3.  마법사\n>>");
		scanf_s("%d", &cho);
		system("cls");
		if (cho > 3 || 1 > cho)
		{
			printf("3가지 직업만 선택가능합니다.\n\n");
			continue;
		}
		switch (cho)
		{
		case 1:
		{
			printf("전사\n");
			printf("HP: 150\n");
			printf("공격력: 7~9\n");
			printf("방어력: 8\n");
			printf("사용무기: 한손검, 양손검, 방패, 창\n");
			printf("갑옷: 중갑\n\n");

			getchar();
			printf("정말로 선택하시겠습니까? Y/N \n>>");
			scanf("%c", &YN);

			if (YN == 'y' || YN == 'Y')
			{
				system("cls");
				printf("당신의 직업은 전사가 되었습니다.\n\n");
				hp = 150;
				temp = hp;
				strcpy(job, "전사");
				damage = rand() % 3 + 7;
				defense = 8;
			}
			else if (YN == 'n' || YN == 'N')
			{
				system("cls");
				printf("선택되지 않았습니다.\n\n");
				continue;
			}
			else
			{
				system("cls");
				printf("Y/N로 선택해주세요.\n\n");
				continue;
			}
			break;
		}
		case 2:
		{
			printf("궁수\n");
			printf("HP: 120\n");
			printf("공격력: 11~13\n");
			printf("사용무기: 활, 석궁, 쇠뇌\n");
			printf("장비: 경갑\n\n");

			getchar();
			printf("정말로 선택하시겠습니까? Y/N \n>>");
			scanf("%c", &YN);

			if (YN == 'y' || YN == 'Y')
			{
				system("cls");
				printf("당신의 직업은 궁수가 되었습니다.\n\n");
				hp = 120;
				temp = hp;
				strcpy(job, "궁수");
				damage = damage = rand() % 3 + 11;
			}
			else if (YN == 'n' || YN == 'N')
			{
				system("cls");
				printf("선택되지 않았습니다.\n\n");
				continue;
			}
			else
			{
				system("cls");
				printf("Y/N로 선택해주세요.\n\n");
				continue;
			}
			break;
		}
		case 3:
		{
			system("cls");
			printf("업데이트 중입니다.\n\n");
			continue;
		}
		}
		break;
	}
	while (1)
	{
	back:
		printf("%d번째 날\n", today);
		printf("무엇을 하시겠습니까?(1:사냥터로 이동, 2: 아이템을 바꾼다, 3: 집으로)\n>>");
		scanf_s("%d", &cho);
		if (cho > 3 || cho < 1)
		{
			system("cls");
			printf("선택지는 3개만 선택가능합니다.\n\n");
			continue;
		}

		printf("\n");
		switch (cho)
		{
		case 1:
		{
			system("cls");
			printf("맵을 선택하세요.(1. 숲 2. )\n");
			scanf_s("%d", &map);
			if (map == 1)
			{
				system("cls");
				printf("숲으로 갔다.\n\n");

				per = rand() % 101 + 1;//몬스터 출현
				if (1 <= per && per <= 5)//5%
				{
					system("cls");
					printf("아무것도 출현하지 않았다.\n");
				}
				if (6 <= per && per <= 100)//20%
				{
					system("cls");
					printf("슬라임이 출현하였다.\n\n");
					strcpy(monster, "슬라임");
				}
			}
			break;
		}
		case 2:
		{
			system("cls");
			printf("나의 아이템 목록\n\n");

			for (i = 0; item[i] != '\0'; i++)
			{
				if (item[i] == '\0') {
					printf("아이템이 존재하지 않습니다!");
					Sleep(500);
					system("cls");
					goto back;
				}
				else {
				printf("%s", item[i]);
				/*if (1 <= i && i <= 50)
				{
					printf("아이템을 교체하시겠습니까? Y/N\n>>");
					getchar();
					scanf("%c", &YN);
					printf("\n");
					if (YN == 'y' || YN == 'Y')
					{
						system("cls");
						printf("%d번째 아이템 %s\n", i, item[i]);
					}
					else if (YN == 'n' || YN == 'N')
					{
						system("cls");
						printf("선택되지 않았습니다.\n\n");
						continue;
					}
					else
					{
						system("cls");
						printf("Y/N로 선택해주세요.\n\n");
						continue;
					}
				}
				if (i == -1)
				{
					system("cls");
					continue;
				}
				else
				{
					system("cls");
					printf("1~50사이만 선택가능합니다.\n");
					continue;
				}*/
				}
			}
			break;
		}
		case 3:
		{
			system("cls");
			pati = 0;
			today++;
			hp = temp;
			printf("집에서 쉬어 체력이 회복되었다.\n");
			printf("하루가 지났다.\n\n");
			break;
		}
		}

		if (per >= 5)//몬스터 출현
		{
			if (strcmp(monster, "슬라임") == 0)
			{
				mhp = 50;
				printf("%s의 hp: %d\n", monster, mhp);//몬스터 판단

				while (1)
				{
					mdamage = rand() % 5 + 1;
					printf("%s의 공격력: 1~5\n", monster);
					printf("어떻게 할까?(1. 싸운다 2. 도망친다.)\n>>");
					scanf("%d", &work);
					system("cls");
					if (work == 1)
					{
						system("cls");
						mhp = mhp - damage;
						hp = hp - mdamage;
						printf("%s의 hp가 %d달았다.\n", monster, damage);
						printf("%s의 hp: %d\n", monster, mhp);
						printf("나의 hp가 %d달았다.\n", mdamage);
						printf("나의 hp: %d\n\n", hp);
						if (mhp <= 0)//아이템을 획득
						{
							system("cls");
							printf("%s이/가 죽었다.\n\n", monster);
							iper = rand() % 101 + 1;
							if (1 <= iper && iper <= 100)
							{
								printf("아이템 1을 얻었다.");
								strcpy(item, "아이템 1");
								Sleep(1000);
								system("cls");
								today++;
								goto back;
							}
						}
						if (hp <= 0)
						{
							system("cls");
							printf("10억을 받았습니다.\n\n");

							printf("다시 도전하시겠습니까? Y/N\n>>");
							scanf("%c", &YN);
							if (YN == 'y' || YN == 'Y')
							{
								system("cls");
								printf("부활하셨습니다.\n\n");

								goto resurrection;
							}
							if (YN == 'n' || YN == 'N')
							{
								system("cls");
								printf("END\n\n");
								return 0;
							}
						}
						
					}
					if (work == 2)
					{
						system("cls");
						printf("무사히 도망쳤다.\n\n");
						goto back;
					}
				}
			}
		}

	}
	//rand()에 (void)가 이미 있기때문에 넣을 필요가 없다.
	//rnad() % 4 + 10은 랜덤함수에 4로 나누게 된다면 나머지는 0~3사이 그리고 10을 더하니 10~13이 되게 된다.
	return 0;
}
