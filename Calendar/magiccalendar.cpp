#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>
#include<windows.h>
#include<conio.h>

using namespace std;


int calcDaysSoFar( int year, int month );
bool isLeapYear( int year);
void printCalendar(int month , int year, int firstDay );

 const int firstYear = 0; 
 const int dayOffset = 0; 
 const int firstLeapYear = 4; 
 
 string dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
 
 string  months[] = { "January", "February", "March", "April", "May", "June", "July", "August", 
        "September", "October", "November", "December"};

 int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31} ; 
 
 int daysPassed[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}; 
 void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main ()

{ 
  SetConsoleTitle("MAGIC CALENDAR v 1.1");
  char x;
    int year, month;
    int days;
    gotoxy(55,22);
    cout<<"CREDIT:";
    gotoxy(55,23);
    cout<<"Irfan Ahmad Khan";
    gotoxy(27,2);
    cout<<"=======================\n";
    gotoxy(27,3);
    cout<<"        CALENDAR";
    gotoxy(27,4);
    cout<<"=======================\n";
    gotoxy(25,6);
    cout<<"Input desired month and year  \n"<<endl;
    gotoxy(26,8);
    cin>>month;
    gotoxy(29,8);
    cout<<"/";
    gotoxy(31,8);
    cin>>year;
    days = calcDaysSoFar(year, month);
    
    
    int firstDayOfWeek = days % 7;
    gotoxy(24,9);

    printCalendar(month, year, firstDayOfWeek);
    getch();
}



int calcDaysSoFar( int year, int month)
{
    int days;

    days = (year - firstYear) * 365;
    days += dayOffset;
    days += daysPassed[month-1];
    for (int count = firstLeapYear; count < year ; count +=4)
    {
        if (isLeapYear(count) )
        {
            days++;
        }
    }
    if( month > 2 && isLeapYear(year) )
    {
        days++;
    }
    return days;

}
bool isLeapYear( int year)
{
    return (!(year%4)&&(year%100))||!(year%400);
}

void printCalendar(int month, int year, int firstDay)
{
    gotoxy(24,7);
    cout << '\n';
    gotoxy(30,11);
    cout<<"--------------------";
    gotoxy(29,12);
    cout <<"   "<< months[month-1] << "    " << year << '\n';
    gotoxy(30,13);
    cout<<"--------------------\n";
    gotoxy(28,14);
    cout << "Sun " << "Mon " << "Tue " << "Wed " << "Thu " << "Fri " << "Sat "<< '\n';

    int count,offset;

    offset= 1 - firstDay;
    
    count = daysInMonth[month-1];
    if(isLeapYear(year) && (month==2) )
    {
        gotoxy(28,15);                
        count++;
    }
     gotoxy(28,15);


    for (int x = offset; x <= count; x +=7)
    {

        for(int column= x; (column < x+7) && (column <= count); column++)
        {
            if (column <=0)
            {
                cout << setw(4) << left << setprecision(7) << "  "; 
            }
            else
            {
                cout << setw(4) << left << setprecision(3)<< setfill(' ') << column;
            }
        }
        
        cout<<"                                                    ";
    }

    cout << endl;

}

