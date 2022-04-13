#include<stdlib.h>
#include<stdio.h>

#define CHOICE_CREATE 1
#define CHOICE_DISPLAY 2
#define CHOICE_INSERT 3
#define CHOICE_DELETE 4
#define CHOICE_EXIT 0

unsigned int menu(){
    unsigned int choice = CHOICE_DELETE + 1;
    while(choice > CHOICE_DELETE){
        printf("enter the choice:\n");
        printf("\t %u - create array\n", CHOICE_CREATE);
        printf("\t %u - display the array elements\n", CHOICE_DISPLAY);
        printf("\t %u - insert the element at position\n", CHOICE_INSERT);
        printf("\t %u - delete an element at position\n", CHOICE_DELETE);
        printf("\t %u - exit\n", CHOICE_EXIT);
        printf("\tchoice:");
        scanf("%d", &choice);
        if(choice > CHOICE_DELETE){
            printf("ERROR:invalid chice\n");
        }
    }
    return choice;
}

int arr[4],size;

int fn_create(){
    printf("enter the size of array\n");
    scanf("%d", &size);
    printf("enter the elements to array\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

int fn_display(){
    for(size_t i = 0;i < size;i++){
        printf("element value = %d at element location = %zu\n",i,arr[i]);
    }
}

int fn_insert(){
    int loc,elem;
    printf("\nspecify the location at which value to be inserted from range 0-%d:",size - 1);
    scanf("%d",&loc);
    printf("\nenter the element to inserted:");
    scanf("%d",&elem);
    for(int i = size - 1;i >= loc;i--)
        arr[i + 1] = arr[i];
        arr[loc] = elem;
        size = size + 1;
}


int fn_delete(){
    int loc,elem;
    printf("\nenter the location from (0-%d) the element to be deleted:",size-1);
    scanf("%d",&loc);
    elem = arr[loc];
    for(int i = loc;i < size -1;i++)
        arr[i] = arr[i +1];
    size = size - 1;
    printf("deleted the %d from the location %d",elem,loc);
}

int fn_exit(int *arr){
    if(arr!=NULL){
    }
}


int main(){
    int choice;

    while(choice != 5){
        choice = menu();
        switch(choice){
           case CHOICE_CREATE : fn_create();
           break;
           case CHOICE_INSERT : fn_insert();
           break;
           case CHOICE_DELETE : fn_delete();
           break;
           case CHOICE_DISPLAY : fn_display();
           break;
           case CHOICE_EXIT :  exit (0);
           default:
           printf("invalid choice");
           break;
        }
    }
}
