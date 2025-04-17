//ATM MACHINE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define  n 50
#define bn 100

typedef struct client{
                    char name[n];
                    int accNum;
                    int pin;
                  }CLIENT;

typedef struct{
                 CLIENT custInfor;
                 float amount;
               }bank;

typedef struct elements{
                     bank  client;
                     struct elements * prev;
                     struct elements * next;

                   }pos;


//global variables 
int accNum=0000,pin = 0000; 
//function declaration
void display(pos * head);
bool cardReader(int userPin,int accNum);
float deposit(int accNum, float amount);
void  printReceipt(int accNum,float amount);
pos * init_ACC();
pos * createACC(pos * head, CLIENT new_client);
CLIENT  input_data();
pos *  displayACC(pos * head, int accNum);
pos* authentication(pos * head,int id, int pin);
void balance(pos * head,int accNum);
pos * admin(pos* head);
pos * updateACC(pos* head, int accNum,char opt);
pos * search(pos* head, int acc);
void write_file(int count, ...);

int main(){
   pos * head = NULL;
   head = admin(head);
   display(head);
   return 0;
}

                                                        /*function definition*/

pos * admin(pos* head){
  int customers,choice,accNumber;

do{
  //function calling
  printf(" To get started we need to add clients in the system\n\n\n");

  printf("|-------------------------------------------------------------------------------------------------|\n");
  printf("|"); printf("                                                                                     |\n");
  printf("|                                          MAIN MENU                                              |\n");
  printf("|-------------------------------------------------------------------------------------------------|\n\n\n");
  printf("|                                         1. CREATE ACCOUNT                                       |\n");
  printf("|-------------------------------------------------------------------------------------------------|\n");
  printf("|                                         2. DEPOSIT                                              |\n");
  printf("|-------------------------------------------------------------------------------------------------|\n");
  printf("|                                         3. SEARCH ACCOUNT                                       |\n");
  printf("|-------------------------------------------------------------------------------------------------|\n");
  printf("|                                         4. DELETE ACCOUNT                                       |\n");
  printf("|-------------------------------------------------------------------------------------------------|\n");
  printf("|                                         0. EXIT                                                 |\n");
  printf("|-------------------------------------------------------------------------------------------------|\n");

  printf(" :::");
  scanf("%i",&choice);
  
  switch (choice)
  {
  case 1:
    /* creating a new acount */
    printf("Enter the number  of clients");
    scanf("%i",&customers);
    for(int i=0 ; i<customers ; i++ ){
          head = createACC(head,input_data());
    }      
  
    break;
    case 2:
    /* depositing calling  */
    head = updateACC(head,accNum,'d');
    break;
    case 3:
    /* search depostion */
    printf("Enter account :::"); scanf("%i",&accNumber);
    head = displayACC(head ,accNumber);
    break;
    case 4:
    /* code */
    break;
    case 0:
    /*  exiting point */
        return head;
    break;

    
  default: printf("⚠️ Error! no  corresponding option , try again");
    break;
  }
}while(true);

     return head;
}

                                                        //intialization
pos * init_ACC(){
    pos * cust =  (pos *)malloc(sizeof(pos));
    if(cust == NULL){
        printf("\n Error space allocation, you have infficient memory!");
        exit(-1);
    }else{
         cust->prev = NULL;
         cust->next = NULL;
    }
    return cust;
}

//creating  bank account a double linked list
pos * createACC(pos * head,CLIENT new_client){
     pos * cli ;//declaration
     cli= init_ACC(); //initializing the account
     cli->client.custInfor = new_client;
     cli->client.amount = 0;

     if(head == NULL){
         head = cli;
     }else{
         cli->next = head;
         cli->prev = head;
         head = cli;
     }
     return head;

}

//registration form  function
CLIENT  input_data(){

         CLIENT  client;
         printf("                                            CREATE ACCOUNT                                \n ");
         printf("______________________________________________________________________________________________\n\n");
         printf("\n Clients Name : "); scanf("%s",client.name);
         printf("\n Clients Acc:"); scanf("%d",&client.accNum);
         printf("\n Clients pin : "); scanf("%d",&client.pin);

         return client;
}

pos * displayACC(pos * head ,int accNumber){
                pos * ptr = NULL;
                ptr = head;
                for(ptr; ptr!=NULL ; ptr=ptr->next){
                  if(ptr->client.custInfor.accNum == accNumber){
                    printf("|-------------------------------------------------------------------------------------------------|\n");
                    printf("|"); printf("                                                                                     |\n");
                    printf("|                                        ACCOUNT DETAILS                                          |\n");
                    printf("|-------------------------------------------------------------------------------------------------|\n\n\n");
                    printf("|   NAME : %s                                                                                     |\n",ptr->client.custInfor.name);
                    printf("|-------------------------------------------------------------------------------------------------|\n");
                    printf("|   ACCOUNT NUMBER : %i                                                                                  |\n",ptr->client.custInfor.accNum);
                    printf("|-------------------------------------------------------------------------------------------------|\n");
                    printf("|   AMOUNT : %.2f                                                                                  |\n",ptr->client.amount);
                    printf("|-------------------------------------------------------------------------------------------------|\n");
                                 
                  }
                }

                return ptr;

}

//display functions
void display(pos * head){
int choice = 5,id,attempt=1;
bool state = false;

// Entry point
 do{
         printf("\n\n\n\n\n                                                WELCOME                                       ");
         printf("\n\n\n\n\n");
         printf("\n                                                          ENTER ID                            \n");
         printf(":::"); scanf("%d",&accNum);
         printf("\n                                                          ENTER PIN                            \n");
         printf(":::"); scanf("%d",&pin);
         head = authentication(head,accNum,pin);
         if (head){
            state = true;
         }
         else{
            printf("Error while authetication, PLEASE VERIFY YOUR DETAILS");
            attempt++;
            if(attempt >3){
             printf("Too many attemps, your card is Block for mini time.\n");
             printf(" Contact your Bank !\n");
            }
         }

 }while(state == false);

do{
       printf("|-------------------------------------------------------------------------------------------------|\n");
       printf("|"); printf("                                                                                     |\n");
       printf("|                                          MAIN MENU                                              |\n");
       printf("|-------------------------------------------------------------------------------------------------|\n\n\n");
       printf("|                                         1. CHECK BALANCE                                        |\n");
       printf("|-------------------------------------------------------------------------------------------------|\n");
       printf("|                                         2. WITHDRAW                                             |\n");
       printf("|-------------------------------------------------------------------------------------------------|\n");
       printf("|                                         3. CHANGE PIN                                           |\n");
       printf("|-------------------------------------------------------------------------------------------------|\n");
       printf("|                                         0. CANCEL                                               |\n");
       printf("|-------------------------------------------------------------------------------------------------|\n");
       printf(" :::");
       scanf("%i",&choice);
       switch(choice){
               case 1:   /*check balance call function*/ balance(head,accNum); break;
               case 2: /*withdraw function call here*/head = updateACC(head,accNum,'w'); break;
               case 3: /*Change pin function here*/ head = updateACC(head,accNum,'p'); break;
               case 0: /*push to authenticate */ display(head); break;
               default: printf("Error , invalide option , try again!");
        }

      }while(choice != 0 && !(choice >3) && !(choice<0));

}

//securing connection
pos*  authentication(pos * head ,int id, int Pin){
        pos * ptr = NULL;
        ptr = head;

        while(ptr){
            if(ptr->client.custInfor.accNum == id && ptr->client.custInfor.pin == Pin ){
                 return head;
             }
             ptr = ptr->next;
        }

        printf("⚠️  Error Authentication !");
        return NULL;
}

//updating count details
pos * updateACC(pos* head, int accNum,char opt){
  pos * ptr = NULL;
  ptr = head;
  float new_balance;

  while(ptr){
    int x = 0,verify=0,y=0;
    if(ptr->client.custInfor.accNum == accNum){
        
    
         switch (opt)
         {
         case 'b': 
                          //updating balance
                          printf("Amount : %.2f",new_balance);  printf("\n ::: ");
                          scanf("%f",&new_balance);
                          printf("Please enter 1 to confirm to add %.2f",new_balance);  printf("\n ::: ");
                          scanf("%i",&verify);
                          if(verify == 1){
                            ptr->client.amount += new_balance;          
                          }
                          break;

          case 'p':
                          //updating pin
                          printf("Enter your Pin\n");  printf("\n ::: ");
                          scanf("%i",&verify);
                          printf("Confirm pin");  printf("\n ::: ");
                          scanf("%i",&y);
                          if(verify == y){
                            ptr->client.custInfor.pin = verify;          
                          }
                          break;
          case 'n':
                          char NAME[n];
                          //updating name
                          printf("Enter your Pin\n");  printf("\n ::: ");
                          fgets(NAME,n,stdin);
                          printf("Confirm pin");  printf("\n ::: ");
                          scanf("%i",&y);
                          if(verify == y){
                            strcpy(ptr->client.custInfor.name,NAME);          
                          }
                          break;
          case 'w':
                          //withdrawing
                          printf("Enter your Amount to withdraw\n");  printf("\n ::: ");
                          scanf("%f",&new_balance);
                          printf("Confirm operation by pressing ");  printf("\n ::: ");
                          scanf("%i",&verify);
                          if(verify == 1 && new_balance < ptr->client.amount){
                            ptr->client.amount -= new_balance;   
                          }
                          break;
            case 'd':
                          //Deposit
                          printf("|                                                %s                                               |\n",ptr->client.custInfor.name);
                          printf("|-------------------------------------------------------------------------------------------------|\n");
                          printf("|                                            DEPOSIT                                              |\n");
                          printf("Please Enter the amount\n");  printf("\n ::: ");
                          scanf("%f",&new_balance);
                          printf("Confirm operation by pressing ");  printf("\n ::: ");
                          scanf("%i",&verify);
                          if(verify == 1 && new_balance < ptr->client.amount){
                            ptr->client.amount -= new_balance;   
                          }
                          break;                          
         
         default:
                 ptr->client.custInfor = input_data();
          break;
         }
         //return section or kill
         printf(" 1. Main Menu                                                                               0. Cancel");
         printf("\n:::");
         scanf("%i",&x);

         if(x== 1) display(ptr);
          else exit(-1);
     }
     ptr = ptr->next;
    }

  return head;
}


//checking the balance  functions
void balance(pos * head,int accNum){
          pos * ptr = NULL;
          ptr = head;
        
          while(ptr){
              int x = 0;
              if(ptr->client.custInfor.accNum == accNum){
                   printf("\n\n                                          1. CHECK BALANCE                                          \n");                                  
                   printf("___________________________________________________________________________________________________\n\n");
                   printf("                                                %.2f MAD                                           \n ",ptr->client.amount);
                   printf("___________________________________________________________________________________________________\n\n\n");
                   
                   //return section or kill
                   printf(" 1. Main Menu                                                                               0. Cancel");
                   printf("\n:::");
                   scanf("%i",&x);
                   if(x== 1) display(head);
                   else exit(-1);
               }

          }

 
}


void write_file(int count, ...) {
  va_list args;
  va_start(args, count);
  
  //ptr file pointer 
  FILE * ptr ;
  ptr = (FILE * )malloc(sizeof(FILE)); //memory allocation
  
  ptr = fopen("fileName.b",'b');
  
  if(ptr=NULL){
    printf(" Error, insufficient memory ");
  }else
  {
    for (int i = 0; i < count; i++) {
      char data = va_arg(args, char);
      fprintf(ptr,'Data_here');
    }
  }   
  fclose(ptr);
  
  va_end(args);
}


