#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
* structor for product
*/ 
struct product
{
	// init var
    int code;
	
	// init var
	char *name;
    
	// init var
	int date_expire;
	
	// init var
    int price;
    
    // init var
    int qty;
};

// initial var for store product
struct product itm[100];

// number for itm
int n;

// init var
int i;

// init var
int InMenu;

// init function
void menu();

// init function
void initStock();

// init function
void findProduct();

// init function
void updateStock();

// init function
void currentStock();

// init function
void resetMenu();

// init function
struct product productByCode(int c);

// init function
struct product productByCodeAndQty(int c,int qty);


// init function
struct product productByName(char* c);

void checkout();

/**
read data from file
*/
void readProduct(){
	// file pointer	
	FILE* filePointer;
	
	//init var
	int bufferLength = 30;
	
	// init var array
	char line[bufferLength];
	
	//open file
	filePointer = fopen("store.txt", "r");
	
	//init var
	int kk=0;
	
	// loop while and read data from stream
	while(fgets(line, bufferLength, filePointer)) {
	    //init var
		char *ch;
		
		//init var
		int jj=0;		
		
		//split text
		ch = strtok(line, ",");
		
		// loop while if not null data
		while(ch != NULL) 
		{
			
			if(jj==0){
				itm[kk].code = atoi(ch);
			}
			
			if(jj==1){
				itm[kk].name = ch;
				//printf("%s",itm[kk].name);
			}
			
			if(jj==2){
				itm[kk].qty = atoi(ch);
			}
			
			if(jj==3){
				itm[kk].price = atoi(ch);
			}
			
			if(jj==4){
				itm[kk].date_expire = atoi(ch);
			}
			
			jj++;
			
			ch = strtok(NULL, ",");
			
			
		}// .End while
		

		kk++;
		
	} //.End while
	
	// close file pointer
	fclose(filePointer);
	
	// print text on screen 
	printf("Load Store Item To Memory Allready. Press Enter To Main Menu \n");
	
} // .End readProduct()


/**
* Find struct data in array
*/
struct product productByCode(int c) 
{
	// init var
	struct product p;
	
	// init var
	int j;
	
	// init var
	int num_length = (sizeof itm / sizeof itm[0]);
	
	//loop for num array
	for(j = 0; j < num_length;j++)
	{
		
		if(itm[j].code == c)
		{
			p = itm[j]; 
		} // .end if
		
	} // .End for
	
	return p;
}; // .End productByCode()

struct product productByCodeAndQty(int c,int qty) 
{
	// init var
	struct product p;
	
	// init var
	int j;
	
	// init var
	int num_length = (sizeof itm / sizeof itm[0]);
	
	//loop for num array
	for(j = 0; j < num_length;j++)
	{
		
		if(itm[j].code == c)
		{
			itm[j].qty -= qty; 
			p = itm[j];
		} // .end if
		
	} // .End for
	
	return p;
}; // .End productByCode()


/**
* find stuct data in array by product name
*/
struct product productByName(char* c)
{
	// init var
	struct product p;
	
	// init var
	int j;
	
	// init var 
	int num_length = (sizeof itm / sizeof itm[0]);
	printf("product num_length %d:",num_length);
	// loop for num array
	for(j = 0; j < num_length;j++)
	{
		if(strcmp(itm[j].name,c)==0)
		{
			printf("Found Item: %s" , itm[j].name);
		}
	}
}



// clear input menu
void resetMenu()
{
	
	InMenu = 0;
	
} // .ENd resetMenu


void menu()
{
	// clear screen
    system ("cls");
    
    // print text on screen 
    printf("\n SELECT MENU BY INPUT NUMBER TO PROCESS TASK");
    printf("\n --------------------------------------------------------\n");
    
    // print text on screen 
    printf("\n1.) init Stock");
    
    // print text on screen 
    printf("\n2.) Show Current Stock");
    
	// print text on screen 
    printf("\n3.) Find Product In Stock");
    
    // print text on screen 
    printf("\n4.) Find Product By Name In Stock");
    
    // print text on screen 
    printf("\n5.) Checkout Product In Stock");
    
	// print text on screen 
    printf("\n9.) Exit Program\n");
    
} //.End menu()




/**
*	display stock from memory
*/
void currentStock() {
	system ("cls");
	
	printf("             *** GOODS STOCK *** \n");
    printf("------------------------------------------------------------------\n");
    printf("NO.|    NAME           |   CODE   |  QUANTITY |  PRICE|  Date Expired \n");
    printf("------------------------------------------------------------------\n");
    int j=0;
    int num_length = (sizeof itm / sizeof itm[0]);
	for(j = 0; j < num_length;j++)
	{
		if(itm[j].code != 0)
		{
			printf("%d     %-10s        %-5d          %-5d     %-5d      %-5d      \n", j + 1, itm[j].name, itm[j].code, itm[j].qty,itm[j].price,itm[j].date_expire);
		}
	}

    printf("------------------------------------------------------------------\n");
} // .End showStock
	

/**
* find data in arry by code char
*/
void findProduct(){
	
	// clear screen
	system("cls");
	
	// call function
	currentStock();
	
	// init var
	int code;
	
	// init var struct
	struct product tmp_product;
	
	// show text on screen
	printf("Enter code of product to find:\n");
	
	// input keyboard
	scanf("%d",&code);
	
	// call function
	tmp_product = productByCode(code);
	
	printf("=== Found Product ===\n");
	printf("Code:%d\n",tmp_product.code);	
	printf("Name:%s\n",&tmp_product.name);
	printf("Qty:%d\n",tmp_product.qty);
	printf("Date Expired:%d\n",tmp_product.date_expire);
	printf("Price:%d\n",tmp_product.price);
} // .End

/**
* find data in arry by code char
*/
void findProductByName(){
	
	// clear screen
	system("cls");
	
	
	// call function
	currentStock();
	
	printf("=== Find Product by name ===\n");
	
	
	// init var
	char code[5];
	
	// init var struct
	struct product tmp_product;
	
	// show text on screen
	printf("Enter name of product to find:\n");
	
	// input keyboard
	scanf("%s",code);
	
	printf("name product %s :",code);
	// call function
	
	tmp_product = productByName(code);
	
	printf("=== Found Product ===\n");
	printf("Code:%d\n",tmp_product.code);	
	printf("Name:%s\n",tmp_product.name);
	printf("Qty:%d\n",tmp_product.qty);
	printf("Date Expired:%d\n",tmp_product.date_expire);
	printf("Price:%d\n",tmp_product.price);
	
} // .End




void checkout(){
	
	system("cls");
	
	currentStock();
	
	int code,qty;
	
	struct product tmp_product;
	
	printf("Enter code of product to find:\n");
	

	scanf("%d",&code);
	

	printf("Enter qty:\n");
	

	scanf("%d",&qty);
	

	tmp_product = productByCodeAndQty(code,qty);
	
	printf("=== Found Product ===\n");
	printf("Code:%d\n",tmp_product.code);	
	printf("Name:%s\n",&tmp_product.name);
	printf("Qty:%d\n",tmp_product.qty);
	printf("Date Expired:%d\n",tmp_product.date_expire);
	printf("Price:%d\n",tmp_product.price);
} 


/**
* Main program will start here.
*/
int main(int argc, char *argv[]) {
	
	// call function
	resetMenu();
	
	
	
	// infinity loop
	for(;;){
		// clear screen
		system("cls");
		
		// call function
		menu();
		
		// input keyboard
		scanf("%d",&InMenu);
	
		switch(InMenu) {
			case 1: 
				// call function
				readProduct();
				
				break;
		
			case 2: 
				// call function
				currentStock();
				
				break;
			
			case 3: 
				// call function
				findProduct();
				
				break;
			
			case 4: 
				// call function
				findProductByName();
				
				break;
				
			case 5:
				// call function
				checkout();
				break;
				
			case 9:
				// show text on screen
		        printf("Press Enter To Exit Program.\n");
		
		        // wait user press any key
		        getch();
		        // exit and return main program
		        return 0;
				break;
			
		}
		
		//call function
		resetMenu();
		
		// show text on screen
		printf("Press Enter To Main Menu\n");
		
		// wait user press any key
		getch();
			
	}//.End For(;;)
    
	return 0;		
}// .End Main
