#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *get_date(char *);

int leap_year(int);

int days_since_ad(int *);

int calendar(int);

int main(int argc, char **argv){
    char *date_str = argv[1];
    int *year_month_day = get_date(date_str);
    int days = days_since_ad(year_month_day);
    // for(int yr = 1880; yr<2025; yr+=4){
    //     printf("year %d is rn: %d\n",yr, leap_year(yr));
    // }
    printf("%d\n",calendar(days));
    return 0;
}

int *get_date(char *date_str){
    int *year_month_day = (int*)malloc(3*sizeof(int));
    char *seg = "-";
    char *substr = strtok(date_str,seg);
    int i = 0;
    while(substr){
        // printf("substr, %s\n", substr);
        *(year_month_day+i) = atoi(substr);
        i++;
        substr = strtok(NULL,seg);
    }
    return year_month_day;
}

// what's the exact rule of leap year
int leap_year(int year){
    if((year%400==0)||(year%4==0&&year%100!=0)){
        return 1;
    }else{
        return 0;
    }
}

int days_since_ad(int *year_month_day){
    int _days_since_ad = -1; // begin at 0001-01-01
    int year = year_month_day[0];
    int month = year_month_day[1];
    int day = year_month_day[2];

    // days in complete years
    for(int yr=1;yr<year;yr++){
        int days_1yr = 0;
        days_1yr = (leap_year(yr))?366:365;
        _days_since_ad += days_1yr;
    }
    // days in complete months
    for(int m=1;m<month;m++){
        int days_1m = 0;
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
            days_1m = 31;
        }else if(m==4||m==6||m==9||m==11){
            days_1m = 30;
        }else{
            days_1m = (leap_year(year))?29:28;
        }
        _days_since_ad += days_1m;
    }
    // days in current year and month
    _days_since_ad += day;
    
    return _days_since_ad;
}

int calendar(int days){
    // // compare with 0001-01-01, which is 7
    // if(days_since_ad%7==0){
    //     return 7;
    // }else{
    //     return days_since_ad%7;
    // }

    // compare with 2000-11-12, which is 7
    
    // int origin[3] = {2000,11,12}; 
    int origin[3] = {1921,1,2}; 
    // int origin[3] = {0001,01,01};

    int diff = days - days_since_ad(origin);

    if(diff%7==0){
        return 7;
    }else{
        return diff%7;
    }
}