# HOTEL_MANAGEMENT_DATABASE
#include<stdio.h>
#include<conio.h>
#include<string.h>
int totalrooms=30;/*Total rooms in hotel is 10*/
typedef struct 
{
int rooms[30];/*for global variables  default value is 0*/
int bill[30];
char customername[30][25];
int rentdays[30];
char bookingdate[30][10];
char leavingdate[30][10];
char str1[30][30];
char proofidtype[30][30];
char proofidnumber[30][30];
}hotel;/*hotel data type is created by using typedef */
hotel h1;/*h1 is a variable of hotel data type*/
int cost = 2500;/*cost of a room is 2500 and same for all rooms */
void booking(void);
void vacantrooms(void);
void vacate(void);
void billing(void);
void pay(int amount,int room);
int checkrooms(int no);
int due(int room);
void display(int);
void main()
{
    int choice,num;
    printf("\nWELCOME TO JAZZ 5STAR HOTEL DATABASE\n");/*name of the hotel is JAZZ*/
    while(1)
    {
        printf("\n1.Room Booking\n2.Room Vacating\n3.Bill pay\n4.Vacant rooms\n5.Room details");
        printf("\nEnter your option: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: booking();
                    break;
            case 2: vacate();
                    break;
            case 3: billing();
                    break;
            case 4: vacantrooms();
                    break;
            case 5: display(num);
                    break;        
            default: printf("\nPlease select the option from 1 to 4 only");
                     break;
        }
    }
}
void vacantrooms()
{
    int i;
    printf("\nThe Vacant rooms: \t");
    for(i=1;i<=totalrooms;i++)
    {
        if(h1.rooms[i]==0)
        {
            printf("  %d",i);
        }
    }
}
int checkrooms(int no)
{
    if(h1.rooms[no]==0)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
void pay(int amount,int room)
{
    h1.bill[room] =h1.bill[room] + amount;
    printf("\nYOur payment %d for the Room %d is successful!!",amount,room);
}
int due(int room)
{
    int balance;
    balance = cost - h1.bill[room];
    return balance;
}

void booking(void)
{
    int no;
    vacantrooms();/*to display all the available rooms*/
    printf("\nSelect the room from the above available rooms : ");
    scanf("%d",&no);
    if(checkrooms(no))/*checking if the room is vacant or not*/
    {
        h1.rooms[no]=1;
        printf("\nEnter the coustomer name: ");
        fflush(stdin);
        gets(h1.customername[no]);
        strupr(h1.customername[no]);
        printf("\nEnter identification proof type : ");
        fflush(stdin);
        gets(h1.proofidtype[no]);
        printf("\nEnter %s id code: ",h1.proofidtype[no]);
        fflush(stdin);
        gets(h1.proofidnumber[no]);
        printf("\nWhat type of room you want: ");
        fflush(stdin);
        gets(h1.str1[no]);
        strupr(h1.str1[no]);
        printf("\nEnter number of days for rent: ");
        scanf("%d",&h1.rentdays[no]);
        printf("\nEnter Booking date: ");
        fflush(stdin);
        gets(h1.bookingdate[no]);
        printf("\nEnter Leaving date: ");
        gets(h1.leavingdate[no]);
        printf("\nYour Room is booked Sucessfully !!");
        printf("\nYour Room is:%d\n",no);
    }
    else/*if not vacant*/
    {
        printf("\nThe room %d is Not Vacant!!\n",no);
    }
}
void vacate()
{
    int no;
    int bal;
    printf("\nEnter the room no: ");
    scanf("%d",&no);
    if(checkrooms(no))
    {
        printf("\nThe room is already Vacant!! ");
    }
    else
    {
        bal = due(no);/*To check for any pending payments*/
        if(bal<=0)
        {
            h1.rooms[no]=0;
            printf("\nYou have beeen vacated from the Room:%d ",no);
        }
        else
        {
            printf("\nSorry your Due is pending ");
            printf("\nYour have to pay %d to vacate! ",bal);
            
        }
        
    }
}
void billing(void)
{
    int choice;
    int amt;
    int roomno;
    int bal;
    printf("\n1.Pay Fee\n2.check Dues");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("\nEnter the room Number: ");
                scanf("%d",&roomno);
                printf("\nEnter the amount: ");
               scanf("%d",&amt);
               pay(amt,roomno);
               break;
        case 2:printf("\n Enter the room Number: ");
                scanf("%d",&roomno);
                bal = due(roomno);
                printf("\nyour Dues for the Room:%d is: %d",roomno,bal);
                break;
        default:printf("\nChoose the correct Option ");
                break;

    }
}

void display(int num)
{
    int dues;
    printf("\nEnter the room number to get the details ");
    scanf("%d",&num);
    if(h1.rooms[num]==0)
    printf("\nThe room %d is vacant ",num);
    else
    {
        printf("\nRoom %d details :",num);
        printf("\nCoustomer Name is ");
        puts(h1.customername[num]);
        printf("\nRoom type is :");
        puts(h1.str1[num]);
        printf("\nRoom Booking Date: ");
        puts(h1.bookingdate[num]);
        printf("\nRoom Leaving Date: ");
        puts(h1.leavingdate[num]);
        printf("Number of days of rent is %d",h1.rentdays[num]);
        dues=due(num);
        printf("\nBill Due of room %d is %drupees \n",num,dues);
        
    }

}

