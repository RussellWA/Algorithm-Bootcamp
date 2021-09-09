#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// =========
// FUNCTIONS
// =========

void menu();
void week();
void show();
void add();
void edit();
void remove();
void search();
int binary(struct Days ds[], int x, int target);
void split(struct Days dy[], int left, int right, int ch);
void sort(struct Days dy[], int x, int ch);
void merge(struct Days dy[], int left, int mid, int right, int ch);
void time();

// ==========================================
// STRUCT (PLACEHOLDER FOR HOURS AND ACTIONS)
// ==========================================

struct Days{
	double hours; // Stores the time of schedule
	char action[50]; // Stores the activity at the current schedule
};

// =============
// MAIN FUNCTION
// =============

int main() {	

	int choice;
	
	do{
    
	    char string[100000];
		
		
		FILE *art = fopen("ascii.txt", "r"); // Open ascii art file
	
		while(fscanf(art, "%[^\n]\n", string) != EOF){
			printf("%s\n", string); // Displays ascii art
		}
		
		fclose(art);
	
		menu(); // Shows menu
		scanf("%d", &choice);
		system("@cls||clear");

		switch (choice){
      
    		case 1:{
	    		show(); // Shows all existing schedules
      			break;
			}
      
			case 2:{
	        	add(); // Adds a schedule
          		break;
	      	}
	
        	case 3:{
      			edit(); // Edits a schedule
      			break;
			}
      
       		case 4:{
      			remove(); // Removes a schedule
     	 		break;
			}
			case 5:{
				search(); // Search a specific schedule with the time
				break;
      		}
    	}
  	}	
	while(choice != 6);
}

// =================================================
// FUNCTION (DISPLAYING ALL FEATURES IN THE PROGRAM)
// =================================================

void menu(){
		
	printf("_____________________________________\n");
	printf("| 1.| Show all schedules             |\n");
	printf("|---|--------------------------------|\n");
	printf("| 2.| Add schedule                   |\n");
	printf("|---|--------------------------------|\n");
	printf("| 3.| Edit schedule                  |\n");
	printf("|---|--------------------------------|\n");
	printf("| 4.| Remove schedule                |\n");
	printf("|---|--------------------------------|\n");
	printf("| 5.| Search specific schedule time  |\n");
	printf("|---|--------------------------------|\n");
	printf("| 6.| Exit                           |\n");
	printf("======================================\n");
    puts("");
    time(); // Displays current date and time
    puts("");
    printf("Choose a number of the feature: ");
		

}

// ========================================
// FUNCTION (DISPLAYING ALL DAYS IN A WEEK)
// ========================================

void week(){
		
	printf("_________________\n");
	printf("| 1.| Monday    |\n");
	printf("| 2.| Tuesday   |\n");
	printf("| 3.| Wednesay  |\n");
	printf("| 4.| Thursday  |\n");
	printf("| 5.| Friday    |\n");
	printf("| 6.| Saturday  |\n");
	printf("| 7.| Sunday    |\n");
	printf("=================\n");
	puts("");

}

// =======================================
// FILE PROCESSING (SHOWING ALL SCHEDULES)
// =======================================

void show(){
	
	int c = 0;
	int count = 1;
	struct Days dy[50];
	
	system("@cls||clear");
	
	FILE *f1 = fopen("week/monday.txt", "r");
	printf("===============================\n");
	printf("Monday's Schedule :\n");
	
	while(fscanf(f1, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
    	printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on monday
		c++;
		count++;
	}
	
	printf("\n");
	count = 1;
    fclose(f1);
    
    FILE *f2 = fopen("week/tuesday.txt", "r");
    printf("____________________\n");
	printf("Tuesday's Schedule :\n");
	
	while(fscanf(f2, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on tuesday
    	c++;
		count++;
	}
	
  	printf("\n");
	count = 1;
    fclose(f2);
    
    FILE *f3 = fopen("week/wednesday.txt", "r");
    printf("______________________\n");
	printf("Wednesday's Schedule :\n");
	
	while(fscanf(f3, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on wednesday
		c++;
		count++;
	}
  	printf("\n");
	count = 1;
    fclose(f3);
    
    FILE *f4 = fopen("week/thursday.txt", "r");
    printf("_____________________\n");
	printf("Thursday's Schedule :\n");
	
	while(fscanf(f4, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on thursday
		c++;
		count++;
	}
	
  	printf("\n");
	count = 1;
    fclose(f4);
    
    FILE *f5 = fopen("week/friday.txt", "r");
    printf("___________________\n");
	printf("Friday's Schedule :\n");
	
	while(fscanf(f5, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on friday
		c++;
		count++;
	}
	
  	printf("\n");
	count = 1;
    fclose(f5);
    
    FILE *f6 = fopen("week/saturday.txt", "r");
    printf("_____________________\n");
	printf("Saturday's Schedule :\n");
	
	while(fscanf(f6, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on saturday
		c++;
		count++;
	}
	
	printf("\n");
	count = 1;
    fclose(f6);
    
	FILE *f7 = fopen("week/sunday.txt", "r");
	printf("___________________\n");
	printf("Sunday's Schedule :\n");
	
	while(fscanf(f7, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
		
		printf("%d. %.2f %s\n", count, dy[c].hours, dy[c].action); // Displays all schedule on sunday
		c++;
		count++;
	}
	
  	printf("\n");
  	printf("===============================\n");
	count = 1;
    fclose(f7);
    
    printf("Press Enter key to continue!\n");
    while(getchar()!='\n');
    getchar(); // Recieves the enter key from stdin
    system("@cls||clear");
}

// ============================================
// FILE PROCESSING (ADDING A SCHEDULE TO A DAY)
// ============================================

void add(){
	
	int c = 0;
	struct Days ds;
	struct Days dy[50];
  
	while(1){
	  	int choose;
	    week();
	    printf("Which day would you like to choose? (Number)\n");
		scanf("%d", &choose); // Inputs user's chosen day
		system("@cls||clear");
    
	    FILE *fadd;
	    
	    if(choose == 1){
	    	fadd = fopen("week/monday.txt", "a");
		}
		
		else if(choose == 2){
			fadd = fopen("week/tuesday.txt", "a");
		} 
		
		else if(choose == 3){
			fadd = fopen("week/wednesday.txt", "a");
		} 
		
		else if(choose == 4){
			fadd = fopen("week/thursday.txt", "a");
		} 
		
		else if(choose == 5){
			fadd = fopen("week/friday.txt", "a");
		} 
		
		else if(choose == 6){
			fadd = fopen("week/saturday.txt", "a");
		} 
		
		else if(choose == 7){
			fadd = fopen("week/sunday.txt", "a");
		} 
		
		else{
	      	printf("Invalid input\n");
			add();
		} 
		
    	int chs = choose;
      	puts("What time? (ex: 6.35 = 6 past 35 AM, 18.35 = 6 past 35 PM)");
		scanf("%lf", &ds.hours); // Inputs user's activity time
      	
      	puts("");
      	
	  	puts("What to do? (ex: study)");
	  	getchar();
    	scanf("%[^\n]", &ds.action); // Inputs user's activity
    	system("@cls||clear");
    	
      	fprintf(fadd,"%lf %s\n", ds.hours, ds.action); // Appends user's previous inputs to file
      	fclose(fadd);
	    
	    FILE *fadd1;
	    FILE *fadd2;
	    
	    if(choose == 1){
			fadd1 = fopen("week/monday.txt", "a+");
			fadd2 = fopen("week/monday.txt", "r");
		} 
	    else if(choose == 2){
			fadd1 = fopen("week/tuesday.txt", "a+");
			fadd2 = fopen("week/tuesday.txt", "r");
		} 
	    else if(choose == 3){
			fadd1 = fopen("week/wednesday.txt", "a+");
			fadd2 = fopen("week/wednesday.txt", "r");
				
		} 
	    else if(choose == 4){
			fadd1 = fopen("week/thursday.txt", "a+");
			fadd2 = fopen("week/thursday.txt", "r");
				
		} 
	    else if(choose == 5){
			fadd1 = fopen("week/friday.txt", "a+");
			fadd2 = fopen("week/friday.txt", "r");
		} 
	    else if(choose == 6){
			fadd1 = fopen("week/saturday.txt", "a+");
			fadd2 = fopen("week/saturday.txt", "r");
		} 
	    else if(choose == 7){
			fadd1 = fopen("week/sunday.txt", "a+");
			fadd2 = fopen("week/sunday.txt", "r");
		} 
		else{
	      	printf("Invalid input\n");
			add();
		} 
		  
    	while(fscanf(fadd2, "%lf %[^\n]\n", &dy[c].hours, dy[c].action) != EOF){
	        c++;
	    }
	      
	    if (c > 1){
	    	sort(dy, c, chs); // Sorts the schedule's time from early to late
	    }
	      
	    else{
	        fclose(fadd1);
	    }
	      
	    int stuff = 0;
	    int c2 = 1;
	      	
	    puts("Here is your new schedule :\n"); // Displays updated schedule
	    
	  	while(fscanf(fadd1, "%lf %[^\n]\n", &dy[stuff].hours, dy[stuff].action) != EOF){
	  		
	  		printf("%d. %.2f %s\n", c2, dy[stuff].hours, dy[stuff].action); // Displays updated schedule
	    	stuff++;
	    	c2++;
	    }
	    
	      
	    fclose(fadd1);
			 
		puts("");
		 
        puts("Would you like to add again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	system("@cls||clear");
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		add();
		}
		
		else if (strcmp(jwb, n) == 0){
			break;
		}
		
		else{
			puts("Invalid input");
		}

      	break;
    }
    
}

// =======================================================
// FILE PROCESSING (UPDATING A SPECIFIC SCHEDULE IN A DAY)
// =======================================================

void edit(){
  
  	int choose;
  
  	while(1){

		week();
		printf("Which day would you like to choose? (Number)\n"); 
		scanf("%d", &choose); // Inputs user's chosen day
		system("@cls||clear");
		
		int chs = choose;
		int c1 = 1;
		int c = 1;
		int lin;
		int counter = 0;
		struct Days ds[50];
		struct Days dy[50];
		struct Days tmp;
		
		FILE *fp;
		
		if(choose == 1){
			fp = fopen("week/monday.txt", "r");
		}
		
		else if(choose == 2){
			fp = fopen("week/tuesday.txt", "r+");
		}
		
		else if(choose == 3){
			fp = fopen("week/wednesday.txt", "r+");
		}
		
		else if(choose == 4){
			fp = fopen("week/thursday.txt", "r+");
		}
		
		else if(choose == 5){
			fp = fopen("week/friday.txt", "r+");
		}
		
		else if(choose == 6){
			fp = fopen("week/saturday.txt", "r+");
		}
		
		else if(choose == 7){
			fp = fopen("week/sunday.txt", "r+");
		}
		
		  
		while(fscanf(fp, "%lf %[^\n]\n", &ds[counter].hours, ds[counter].action) != EOF){ // Getting all schedules from txt file (each schedule is within a single line)
		
			printf("%d. %.2f %s\n", c, ds[counter].hours, ds[counter].action); // Shows all current schedules within the chosen day
			counter++;
			c++;
		}
		  
		puts("Which schedule would you like to change? (Insert schedule number)");
		scanf("%d", &lin); // Inputs user's choice of schedule to be changed
		system("@cls||clear");
		
		  
		puts("What time? (ex: 6.35 = 6 past 35 AM, 18.35 = 6 past 35 PM)");
		scanf("%lf", &tmp.hours); // Inputs user's updated activity time
		
		puts("");
		
		puts("What to do? (ex: study)");
		getchar(); 
		scanf("%[^\n]", &tmp.action); // Inputs user's updated activity
		
		puts("");
    
	    while(1){
	    	
	        char cnm[10];
	        puts("Are you sure you want to update? (YES OR NO) (ALL CAPS)"); // Confirms user's changes within the schedule
	        scanf("%s", &cnm); // Inputs user's confirmation
	        system("@cls||clear");
	    	int len = strlen(cnm);
			bool ans = (len % 2 == 0);
			
			
	    	if (ans == 0){
	    		break;
			}
		
			else if (ans == 1){
				main();
				break;
			}
			
			else{
				continue;
			}
		}
    
    	puts("Here is your new schedule :\n"); // Displays updated schedule
    
    	FILE *fc;
    
	    if(choose == 1){
	    	fc = fopen("week/monday.txt", "w+");
		}
	
		else if(choose == 2){
	    	fc = fopen("week/tuesday.txt", "w+");
		}
		
		else if(choose == 3){
	    	fc = fopen("week/wednesday.txt", "w+");
		}
		
		else if(choose == 4){
	    	fc = fopen("week/thursday.txt", "w+");
		}
		
		else if(choose == 5){
	    	fc = fopen("week/friday.txt", "w+");
		}
		
		else if(choose == 6){
	    	fc = fopen("week/saturday.txt", "w+");
		}
		
		else if(choose == 7){
	    	fc = fopen("week/sunday.txt", "w+");
		}
		
	   	for (int i = 1; i <= counter; i++){
	        if (i == lin){
	            fprintf(fc, "%lf %s\n", tmp.hours, tmp.action);
	            c1++;
	        }
	        
	        else{
	            fprintf(fc, "%lf %s\n", ds[i-1].hours, ds[i-1].action);
	            c1++;
	        }
	    }
	    
	  	fclose(fp);
		fclose(fc);
	        
	    FILE *fa;
	    FILE *ff;
		
		if(choose == 1){
			fa = fopen("week/monday.txt", "a+");
			ff = fopen("week/monday.txt", "r");
		}
		
		else if(choose == 2){
			fa = fopen("week/tuesday.txt", "a+");
			ff = fopen("week/tuesday.txt", "r");
		}
		
		else if(choose == 3){
			fa = fopen("week/wednesday.txt", "a+");
			ff = fopen("week/wednesday.txt", "r");
		}
		
		else if(choose == 4){
			fa = fopen("week/thursday.txt", "a+");
			ff = fopen("week/wednesday.txt", "r");
		}
		
		else if(choose == 5){
			fa = fopen("week/friday.txt", "a+");
			ff = fopen("week/wednesday.txt", "r");
		}
		
		else if(choose == 6){
			fa = fopen("week/saturday.txt", "a+");
			ff = fopen("week/wednesday.txt", "r");
		}
		
		else if(choose == 7){
			fa = fopen("week/sunday.txt", "a+");
			ff = fopen("week/wednesday.txt", "r");
		}
        
      	int count = 0;
      	while(fscanf(fa, "%lf %[^\n]\n", &dy[count].hours, dy[count].action) != EOF){
        	count++;
    	}
    
     	if (count > 1){
        	sort(dy, count, chs); // Sorts the updated schedule's time from early to late
      	}
      
      	else{
        	fclose(fa);
      	}
      	
      	int stuff = 0;
      	int c2 = 1;
      	
      	
      	while(fscanf(ff, "%lf %[^\n]\n", &dy[stuff].hours, dy[stuff].action) != EOF){
      		
      		printf("%d. %.2f %s\n", c2, dy[stuff].hours, dy[stuff].action); // Displays updated schedule
        	stuff++;
        	c2++;
      	}
      	
      	fclose(ff);
      	fclose(fa);
      	
      	puts("");
      	
        puts("Would you like to edit again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	system("@cls||clear");
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		edit();
		}
		
		else if (strcmp(jwb, n) == 0){
			break;
		}
		
		else{
			puts("Invalid input");
		}

        break;
    }
}

// =======================================================
// FILE PROCESSING (REMOVING A SPECIFIC SCHEDULE IN A DAY)
// =======================================================

void remove(){
	int choose;
  
	while(1){
		
	    week();
	    printf("Which day would you like to choose? (Number)\n");
	    scanf("%d", &choose); // Inputs user's chosen day
	    system("@cls||clear");
	    
	    FILE *fp;
	    
	    if(choose == 1){
	    	fp = fopen("week/monday.txt", "r");
		}
		
		else if(choose == 2){
	    	fp = fopen("week/tuesday.txt", "r");
		}
		
		else if(choose == 3){
	    	fp = fopen("week/wednesday.txt", "r");
		}
		
		else if(choose == 4){
	    	fp = fopen("week/thursday.txt", "r");
		}
		
		else if(choose == 5){
	    	fp = fopen("week/friday.txt", "r");
		}
		
		else if(choose == 6){
	    	fp = fopen("week/saturday.txt", "r");
		}
		
		else if(choose == 7){
	    	fp = fopen("week/sunday.txt", "r");
		}
		
	  	int c1 = 1;
	    int c = 1;
	    int lin;
	    int counter = 0;
		int count = 0;
		
	  	struct Days ds[50];
	  	struct Days tmp;
	  	
		while(fscanf(fp, "%lf %[^\n]\n", &ds[counter].hours, ds[counter].action) != EOF){ // Getting all schedules from txt file (each schedule is within a single line)
	    	printf("%d. %.2f %s\n", c, ds[counter].hours, ds[counter].action); // Shows all current schedules within the chosen day
	    	counter++;
	    	c++;
		}
	  
	    puts("Which schedule would you like to remove? (Insert schedule number)");
	    scanf("%d", &lin); // Inputs user's choice of schedule to be removed
	    
	    puts("");
	    
	    while(1){
	    	
	        char cnm[10];
	        puts("Are you sure you want to remove? (YES OR NO) (ALL CAPS)"); // Confirms user's changes within the schedule
	        scanf("%s", &cnm); // Inputs user's confirmation
	        system("@cls||clear");
	    	int len = strlen(cnm);
			bool ans = (len % 2 == 0);
			
			
	    	if (ans == 0){
	    		break;
			}
			else if (ans == 1){
				main();
				break;
			}
			else{
				continue;
			}
		}
	        
	    puts("Here is your new schedule :\n"); // Displays updated schedule
	    
	    FILE *fc;
	    
	    if(choose == 1){
	    	fc = fopen("week/monday.txt", "w+");
		}
		
		else if(choose == 2){
	    	fc = fopen("week/tuesday.txt", "w+");
		}
		
		else if(choose == 3){
	    	fc = fopen("week/wednesday.txt", "w+");
		}
		
		else if(choose == 4){
	    	fc = fopen("week/thursday.txt", "w+");
		}
		
		else if(choose == 5){
	    	fc = fopen("week/friday.txt", "w+");
		}
		
		else if(choose == 6){
	    	fc = fopen("week/saturday.txt", "w+");
		}
		
		else if(choose == 7){
	    	fc = fopen("week/sunday.txt", "w+");
		}
	
		for (int i = 1; i <= counter; i++){
	        if (i == lin){
	           continue;
	        }
	        
	        else{
	            fprintf(fc, "%lf %s\n", ds[i-1].hours, ds[i-1].action); // Writes updated schedule to file
	            printf("%d. %.2f %s\n", c1, ds[i-1].hours, ds[i-1].action); // Displays updated schedule
	            c1++;
	        }
	    }
	    
      	fclose(fp);
    	fclose(fc);
        
        printf("\n");
        
        puts("Would you like to remove again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	system("@cls||clear");
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		remove();
		}
		
		else if (strcmp(jwb, n) == 0){
			break;
		}
		
		else{
			puts("Invalid input");
		}
		
        break;
    }
}

// =============================================
// SCHEDULE SEARCH SYSTEM BASED ON SPECIFIC TIME
// =============================================

void search(){
	
  	int trg;
	double num;

	puts("What time would you like to search in the schedule? (ex: 1835 = 6 past 35 PM)");
	scanf("%lf", &num); // Inputs a specific time of schedule to be searched
	system("@cls||clear");
  
	trg = num*100;
	
	int choose;
	week();
    printf("Which day would you like to choose? (Number)\n");
    scanf("%d", &choose); // Inputs user's chosen day
    system("@cls||clear");
    
    FILE *fp;
    
    if(choose == 1){
    	fp = fopen("week/monday.txt", "r");
	}
	
	else if(choose == 2){
    	fp = fopen("week/tuesday.txt", "r");
	}
	
	else if(choose == 3){
    	fp = fopen("week/wednesday.txt", "r");
	}
	
	else if(choose == 4){
    	fp = fopen("week/thursday.txt", "r");
	}
	
	else if(choose == 5){
    	fp = fopen("week/friday.txt", "r");
	}
	
	else if(choose == 6){
    	fp = fopen("week/saturday.txt", "r");
	}
	
	else if(choose == 7){
    	fp = fopen("week/sunday.txt", "r");
	}
    
    int c = 1;
    int counter = 0;
    struct Days ds[50];
    
    while(fscanf(fp, "%lf %[^\n]\n", &ds[counter].hours, ds[counter].action) != EOF){ // Getting all schedules from txt file (each schedule is within a single line)
    	counter++;
    	c++;
	}
	
	binary(ds, c, trg); // Binary Search System
    
    int idx = binary(ds, c, trg);
    
    if (binary(ds, c, trg) == -1){ // Condition if there is no match
    	puts("No schedule at this time in this day\n");
    	
    	puts("Would you like to search again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	system("@cls||clear");
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		search();
		}
		
		else if (strcmp(jwb, n) == 0){
		}
		
		else{
			puts("Invalid input");
		}
	}
	
	else{ // Condition if there is a match
	    puts("Here is the schedule:");
	    puts("");
	    printf("%s\n", ds[idx].action);
	    
	    puts("");
	    
    	puts("Would you like to search again? (YES or NO) (ALL CAPS)");
    	
    	char jwb[10];
    	scanf("%s", jwb);
    	system("@cls||clear");
    	char y[] = {"YES"};
    	char n[] = {"NO"};
    	
    	
    	if (strcmp(jwb, y) == 0){
    		search();
		}
		
		else if (strcmp(jwb, n) == 0){
		}
		
		else{
			puts("Invalid input");
		}
	}
    
}

// ====================
// BINARY SEARCH SYSTEM
// ====================

int binary(struct Days ds[50], int x, int target){
	int min = 0;
	int max = x - 1;
	while(min <= max){
		int mid = (min + max) / 2;
		
		if (target < (ds[mid].hours*100)){
			max = mid - 1;
		}
		else if (target > (ds[mid].hours*100)){
			min = mid + 1;
		}
		else if (target == (ds[mid].hours*100)){
			return mid;
		}
	}
	return -1;
}

// ===========
// SORT SYSTEM
// ===========

void sort(struct Days dy[100], int x, int ch){
	split(dy, 0, x - 1, ch);
}

// ============
// SPLIT SYSTEM
// ============

void split(struct Days dy[50], int left, int right, int ch){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    split(dy, left, mid, ch);
    split(dy, mid + 1, right, ch);

    merge(dy, left, mid, right, ch);
}

// =================
// MERGE SORT SYSTEM 
// =================

void merge(struct Days dy[50], int left, int mid, int right, int ch){
	
	FILE *fm;
	
	if (ch == 1){
		fm = fopen("week/monday.txt", "r");
	}
	else if (ch == 2){
		fm = fopen("week/tuesday.txt", "r");
	}
	else if (ch == 3){
		fm = fopen("week/wednesday.txt", "r");
	}
	else if (ch == 4){
		fm = fopen("week/thursday.txt", "r");
	}
	else if (ch == 5){
		fm = fopen("week/friday.txt", "r");
	}
	else if (ch == 6){
		fm = fopen("week/saturday.txt", "r");
	}
	else if (ch == 7){
		fm = fopen("week/sunday.txt", "r");
	}
	
	int count = 0;
	
	while(fscanf(fm, "%lf %[^\n]\n", &dy[count].hours, dy[count].action) != EOF){
    	count++;
    }
	
	long int sizeL = mid - left + 1;
	long int sizeR = right - mid;
	
	struct Days arrL[sizeL];
	struct Days arrR[sizeR];
	
	for (int i = 0; i < sizeL; i++){
		arrL[i] = dy[i + left];
	}
	
	for (int j = 0; j < sizeR; j++){
		arrR[j] = dy[j + mid + 1];
	}
	
	int idx = left;
	int idxL = 0;
	int idxR = 0;
	
    while(idxL < sizeL && idxR < sizeR){
        if(arrL[idxL].hours < arrR[idxR].hours){
            dy[idx] = arrL[idxL];
            idx++;
            idxL++;
        }
        else{
            dy[idx] = arrR[idxR];
            idx++;
            idxR++;
        }
    }

    while(idxL < sizeL){
        dy[idx] = arrL[idxL];
        idx++;
        idxL++;
    }

    while(idxR < sizeR){
        dy[idx] = arrR[idxR];
        idx++;
        idxR++;
    }
    
    FILE *fs;
    
	if (ch == 1){
		fs = fopen("week/monday.txt", "w+");
	}
	else if (ch == 2){
		fs = fopen("week/tuesday.txt", "w+");
	}
	else if (ch == 3){
		fs = fopen("week/wednesday.txt", "w+");
	}
	else if (ch == 4){
		fs = fopen("week/thursday.txt", "w+");
	}
	else if (ch == 5){
		fs = fopen("week/friday.txt", "w+");
	}
	else if (ch == 6){
		fs = fopen("week/saturday.txt", "w+");
	}
	else if (ch == 7){
		fs = fopen("week/sunday.txt", "w+");
	}
	
	for (int k = 0; k < count; k++){
		fprintf(fs, "%lf %s\n", dy[k].hours, dy[k].action);
	}
	fclose(fs);
	fclose(fm);
}

void time(){
 
    time_t x;
 
    time(&x);
 
    printf("Today is %s", ctime(&x));
}
