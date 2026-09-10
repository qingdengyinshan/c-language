  #include<stdio.h>
  #include<string.h>
  #include<stdlib.h>

  int main(void){
    FILE* f0;
    FILE* f1;
    FILE* f2;

    
    f0 = fopen("C:/Users/Lenovo/Desktop/c language/test2.txt", "w");
    char string0[500];
    printf("please code what you want: ");
    fgets(string0, sizeof(string0), stdin);
    printf("%s", string0);
    fprintf(f0, "%s",string0);
    fclose(f0);
    
    f1 = fopen("C:/Users/Lenovo/Desktop/c language/test2.txt", "r");
    char string1[500];
    if(fgets(string1, sizeof(string1), f1) != NULL){
        printf("You will find : %sin the file test2\n", string1);   
    }else{
        printf("Something has broken down\n");
    }
    
    fclose(f1);
    
    f2 = fopen("C:/Users/Lenovo/Desktop/c language/test2.txt", "a");
    char string2[500];
    char flag;
    int repeat_number = 1;
    int error_flag = 0;

    printf("Would you like to add what you wanna add?(T/F)?");
    scanf(" %c", &flag);
    getchar();
    while(flag != 'T' && flag != 't' && flag != 'F' && flag != 'f'){
        printf("print error!\n");
        printf("Please tell me (T/F):");
        scanf("%c", &flag);
        if(flag != 'T' && flag != 't' && flag != 'F' && flag != 'f'){
            continue;
        }else{
            break;
        }
    }
    
    while(repeat_number == 1){
        if(flag == 'T' || flag == 't'){
            printf("Add please:");
            if(fgets(string2, sizeof(string2), stdin) != NULL){
                fprintf(f2, "%s", string2);
                printf("Something new like : %swill appear in the file test2\n", string2);  
            }else{
                printf("Something has broken down\n");
            }

        printf("Continue?\n");
        printf("If you like to carry on,please input 1.Otherwise,it can be better to choose 0 to stop the talking\n");
        printf("Now it's your turn:");
        scanf("%d", &repeat_number);
        getchar();
        if(repeat_number == 1){
            continue;
        }else if(repeat_number == 0){
            printf("Over");
            break;
        }else{
            error_flag = 0;
            while(error_flag == 0){
            printf("Error!\n");
            printf("Please tell me the number(1/0) again:");
            scanf("%d", &repeat_number);
            getchar();
            if(repeat_number != 1 && repeat_number != 0){
                error_flag = 0;
                continue;
            }else{
                error_flag = 1; 
                break;
            }
            }
        continue;
        }
    }else if(flag == 'F' || flag == 'f'){
            printf("Now you can see file is completed");
        }
    }
    
    fclose(f2); 
    
    return 0;


}