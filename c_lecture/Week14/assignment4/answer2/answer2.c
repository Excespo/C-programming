#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct _Date_t {
    unsigned year:15;
    unsigned month:4;
    unsigned day:5;
} Date_t;

int leap_year(int year){
    if((year%400==0)||(year%4==0&&year%100!=0)){
        return 1;
    }else{
        return 0;
    }
}

int days_since_ad(Date_t date){
    int _days_since_ad = -1; // begin at 0001-01-01
    int year = date.year;
    int month = date.month;
    int day = date.day;

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

int time_delta(Date_t date1, Date_t date2) {
    int dsa1 = days_since_ad(date1);
    int dsa2 = days_since_ad(date2);
    return (dsa1>dsa2)?(dsa1-dsa2):(dsa2-dsa1);
}

int count_down(Date_t today) {
    Date_t* bjdah = (Date_t*)malloc(sizeof(Date_t));
    bjdah->year = 2022;
    bjdah->month = 2;
    bjdah->day = 4;
    return time_delta(today,*bjdah);
}

int main(void) {
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    Date_t* today = (Date_t*)malloc(sizeof(Date_t));
    today->year = 1900+p->tm_year;
    today->month = 1+p->tm_mon;
    today->day = p->tm_mday;
    printf("today %d %d %d\n", today->year, today->month, today->day);
    printf("count %d\n", count_down(*today));
}