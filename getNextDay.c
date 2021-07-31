// 2021.07.31 created by taeyoung 
// 기능 : 날짜를 입력받아 입력받아 다음 날짜 출력해준다
// ex) 20210228 -> 20210301

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

enum Month {
    JAN=1, FEB, MAR, APR, MAY, JUN,
    JUL, AUG, SEP, OCT, NOV, DEC=12
};

int isLeafYear(int nYear) {
    return ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0);
}

int getDaysOfMonth(int nYear, int nMonth) {
    if (nMonth == 2)
        return (isLeafYear(nYear)) ? 29 : 28;
    else if (nMonth == 4 || nMonth == 6 || nMonth == 9 || nMonth == 11)
        return 30;
    return 31;
}

int main(int argc, char* argv[]) {
#ifdef _DEBUG_
    printf("argument 0 = %s\n", argv[0]);
    printf("argument 1 = %s\n", argv[1]);
#endif

    if (1 == argc) {
        return -1;
    }

    if (strlen(argv[1]) == 8 ) {
        for(int idx = 0; idx < 8; idx++) {
            if (isdigit(argv[1][idx]) == 0) {
                return -1;
            }
        }
        
        int n_Argv = atoi(argv[1]);

#if 0
        int n_Year  = atoi(argv[1][0])*1000 +
                      atoi(argv[1][1])*100 +
                      atoi(argv[1][2])*10 +
                      atoi(argv[1][3]);
        int n_Month = atoi(argv[1][4])*10 + atoi(argv[1][5]);
        int n_Day   = atoi(argv[1][6])*10 + atoi(argv[1][7]);
#endif

        int n_Year  = n_Argv / 10000;
        int n_Month = (n_Argv / 100) % 100;
        int n_Day   = n_Argv % 100; 


        int n_LastDay = getDaysOfMonth(n_Year, n_Month);

	    char s_Ret[10];

#ifdef _DEBUG_
        printf("year: %d\nmonth: %d\nday: %d\n", n_Year, n_Month, n_Day);
#endif

        //각 달의 마지막 날이 아니면 +1 해서 리턴 
        if (n_Day != n_LastDay) {
            sprintf(s_Ret, "%4d%02d%02d", n_Year, n_Month, n_Day+1);
            printf("%s", s_Ret);
	    return 0;
        }

        switch (n_Month) {
        case JAN:
        case FEB:
        case MAR:
        case APR:
        case MAY:
        case JUN:
        case JUL:
        case AUG:
        case SEP:
        case OCT:
        case NOV:
            sprintf(s_Ret, "%4d%02d%02d", n_Year, n_Month+1, 01);
	        printf("%s", s_Ret);
	        return 0;
	    case DEC:
            sprintf(s_Ret, "%4d%02d%02d", n_Year+1, JAN, 01);
	        printf("%s", s_Ret);
	        return 0;
        default:
            return -1;
        }
    }
}
