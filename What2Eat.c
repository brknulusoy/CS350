#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main()
{
int num_people;
printf("Enter the number of people: ");
scanf("%d", &num_people);

int Kebab = 0;
int Burger = 0;
int Pasta = 0;
int Lahmacun= 0;
int Salad = 0;
int Threshold = 10;

char food_name[10];

char *short_list[5] = {};
char **ptr = short_list;

printf("Here is a list of food to choose from: \n Kebab, Burger, Pasta, Lahmacun, Salad \n");

for(int i=0;i<num_people;i++){
    printf("Please enter your preferences in order starting with capital letter: \n");
    for(int k=0;k<5;k++){
        scanf("%s",food_name);
	if(strcmp(food_name , "Kebab") == 0){
	    Kebab = Kebab + (5-k);
	} else if (strcmp(food_name , "Burger") == 0){
	    Burger += Burger + (5-k);
	} else if (strcmp(food_name  , "Pasta") == 0){
	    Pasta = Pasta + (5-k);
	} else if (strcmp(food_name , "Lahmacun") == 0){
	    Lahmacun = Lahmacun + (5-k);
	} else if (strcmp(food_name , "Salad") == 0){
	    Salad = Salad + (5-k);
	}
    }
}

int ind = -1;

if(Kebab >= Threshold){
    ind++;
    ptr[ind] = "Kebab";
} if (Burger >= Threshold) {
    ind++;
    ptr[ind] = "Burger";
} if (Pasta >= Threshold) {
    ind++;
    ptr[ind] = "Pasta";
} if (Lahmacun >= Threshold) {
    ind++;
    ptr[ind] = "Lahmacun";
} if (Salad >= Threshold) {
    ind++;
    ptr[ind] = "Salad";
}

if(ind > -1){
    Kebab = 0;
    Burger = 0;
    Pasta = 0;
    Lahmacun= 0;
    Salad = 0;

    printf("Please select from this short list: \n");
    for(int j = 0;j<ind+1;j++){
	printf("Food %d : %s \n", j+1, ptr[j]);
    }
    for(int m=0;m<num_people;m++){
        printf("Please enter the food you preffer in order starting with capital letter: \n");
        for(int p=0;p<ind+1;p++) {
	    scanf("%s",food_name);
	    if(strcmp(food_name , "Kebab") == 0){
                Kebab = Kebab + (5-p);
            } else if (strcmp(food_name , "Burger") == 0){
                Burger = Burger + (5-p);
            } else if (strcmp(food_name  , "Pasta") == 0){
                Pasta = Pasta + (5-p);
            } else if (strcmp(food_name , "Lahmacun") == 0){
                Lahmacun = Lahmacun + (5-p);
            } else if (strcmp(food_name , "Salad") == 0){
                Salad = Salad + (5-p);
            }
	}
    }

printf("The foods points are as follows: \n Kebab: %d \n Burger: %d \n Pasta: %d \n Lahmacun: %d \n Salad: %d \n", Kebab, Burger, Pasta, Lahmacun, Salad);

char top_food[10];
int max_val = 0;

if(Kebab > max_val){
    strcpy(top_food, "Kebab");
    max_val = Kebab;
} if (Burger > max_val){
    strcpy(top_food, "Burger");
    max_val = Burger;
} if (Pasta > max_val){
    strcpy(top_food, "Pasta");
    max_val = Pasta;
} if (Lahmacun > max_val){
    strcpy(top_food, "Lahmacun");
    max_val = Lahmacun;
} if (Salad > max_val){
    strcpy(top_food, "Salad");
    max_val = Salad;
}

printf("The food that is going to be ordered is %s \n", top_food);

} else {
    printf("You are eating at home/dorm today! \n");
}

return 0;
}
