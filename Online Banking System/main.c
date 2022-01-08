#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user {
    char phone[50];
    char account [50];
    char password [50];
    float balance;
};

int main(){
    struct user usr, usr1;
    FILE *fp;
    char filename[50],phone[50],pword[50];

    int option,choice;
	char cont = 'y';
	float amount;
    printf("\n What do you want to do?");
    printf("\n\n 1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\n Your choice: \t");
    scanf("%d", &option );
    
    if (option == 1)
{ system("clear");
printf("Enter your account number: \t");
scanf("%s", usr.account);
printf("Enter your phone number: \t");
scanf("%s", usr.phone);
printf("Enter your new password: \t");
scanf("%s", usr.password);
usr.balance =0;

strcpy(filename, usr.phone); // Copy String or Char from usr.phone to filename.
fp= fopen(strcat(filename, ".meowmeow"), "w"); //Link(combine) 2 string in C filename.meowmeow
fwrite(&usr, sizeof(struct user),1,fp);
if (fwrite != 0 ) {
	printf("\n\n Account succesfully registered ");
	
}else{
	printf("\n\n Something went wrong please try again! ");
}
fclose(fp);
	}    
	
	
if (option==2) {
	system("clear");
	printf("\n Phone number: \t");
	scanf("%s",phone);
	printf(" Password: \t");
	scanf("%s", pword);
	strcpy(filename,phone);
	fp =fopen(strcat(filename,".meowmeow"),"r");
	if(fp==NULL){
		printf("\n Account number not registered");
	}
	else{
	
	fread(&usr, sizeof(struct user),1,fp);
	fclose(fp);
	if (!strcmp(pword,usr.password)){
		while (cont == 'y'){
			system("clear");
			printf("\n Press 1 to check balance");
			printf("\n Press 2 to deposit an amount");
			printf("\n Press 3 to withdraw an amount");
			printf("\n Press 4 to transfer the balance");
			printf("\n Press 5 to change the password");
			printf("\n\n Your choice: \t");
			scanf("%d", &choice);
			
			switch(choice){
				case 1 :
					printf("\n Your current balance is Eu.%.2f" , usr.balance);
					break;
				
				case 2:
					printf("\n Enter the amount: \t");
					scanf("%f", &amount);
					usr.balance += amount;
					fp = fopen(filename, "w");
					fwrite(&usr, sizeof(struct user), 1, fp);
					if(fwrite != NULL) printf("\n Succesfully deposited. ");
					fclose(fp);
					break;
				
				case 3:
					printf("\n Enter the amount: \t");
					scanf("%f", &amount);
					usr.balance -= amount;
					fp = fopen(filename, "w");
					fwrite(&usr, sizeof(struct user), 1, fp);
					if(fwrite != NULL) printf("\n You have withdrawn Eu.%.2f", amount);
					fclose(fp);
					break;
				
				case 4:
					printf("\n Please enter the phone number to transfer the balance: \t");
					scanf("%s", phone);
					printf("\n Please enter the amount to transfer: \t");
					scanf("%f", &amount);
					strcpy(filename,phone);
					fp=fopen(strcat(filename,".meowmeow"),"r");
					if(fp==NULL) printf("\n Account nukber is not registered");
					else{
					fread(&usr1,sizeof(struct user),1,fp);
					fclose(fp);
					if (amount > usr.balance) printf("\n Insufficient balance");
					else {
						
						fp=fopen(filename,"w");
						usr1.balance += amount;
						fwrite(&usr1, sizeof(struct user),1, fp);
						fclose (fp);
						if(fwrite != NULL) {
							printf("\n You have sucesfully transfered Eu.%.2f to %s", amount, phone );
							strcpy(filename,usr.phone);
							fp=fopen(strcat(filename, ".meowmeow"),"w");
							usr.balance -= amount;
							fwrite(&usr, sizeof(struct user),1,fp);
							fclose(fp);		
					}	
					}
				}
				
					break;
					
				case 5:
					printf("\n Please enter your old password: \t");
					scanf("%s",pword);
					if(!strcmp(pword,usr.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",pword);
							strcpy(usr.password,pword);
							strcpy(filename,usr.phone);
							fp = fopen(strcat(filename,".meowmeow"),"w");
							fwrite(&usr,sizeof(struct user),1,fp);
							fclose(fp);	
							printf("\nPassword succesfullly changed");
						}else printf("\nSorry your password is wrong");
				default:
					break;	
					
					}	
					
					printf("\n Do you want to continue the transaction [y/n] \t");
					scanf("%s", &cont);	
					}	
		}
	
	else{
		printf("\n Invalid password");
		
	}
	
}
		printf("\n\n +++ Thank you for banking with MEOW MEOW +++ \n\n");
}

    return 0;
}

