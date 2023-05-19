#include <stdio.h>

void main(void){

    char arr[50];
    int arr_num[50],num=0,i,j,index_num=0,index_operant=0,result=0;
    char arr_operant[50];

    printf("enter string eq :");
    scanf("%s",arr);

    /*-------------------------[sorting-number]-----------------*/
    for(i=0;i<50;i++){
            if(arr[i]>='0'&&arr[i]<='9'){
                    for(j=i;(arr[j]>='0'&&arr[j]<='9');j++){
                        num=(num*10)+(arr[j]-48);
                        i++;
                    }
                arr_num[index_num]=num;
                index_num++;
                num=0;
            }
    }
    /*-------------------------[clear_locations_that_not_storint_num]-----------------*/
    for(i=index_num;i<50;i++){
        arr_num[i]=0;
    }
    /*-------------------------[sorting-oprtant]-----------------*/
    for(i=0;i<50;i++){
        if(arr[i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/'||arr[i]=='='){
                arr_operant[index_operant]=arr[i];
                index_operant++;
                if(arr[i]=='-'){
                    arr_num[index_operant]=-arr_num[index_operant];
                }
            }
    }
    /*-------------------------[clear_locations_that_not_storint_operant]-----------------*/
    for(i=index_operant;i<50;i++){
        arr_operant[i]=0;
    }
    /*-------------------------[print-2_array]-----------------*/
    for(i=0;i<50;i++){
        printf("arr[%d]=%c",i,arr[i]);
        printf("\tarr_num[%d]=%d",i,arr_num[i]);
        printf("\tarr_operant[%d]=%c\n",i,arr_operant[i]);
    }
    /*-------------------------[handling mul & div]-----------------*/
    printf("\nindex_num=%d",index_num);
    printf("\tindex_operant=%d\n",index_operant);

    for(i=0;i<index_operant;i++){
        if(arr_operant[i]=='*'){
            arr_num[i+1]=arr_num[i]*arr_num[i+1];
            arr_num[i]=0;
        }else if(arr_operant[i]=='/'&&arr_num[i+1]!=0){
            arr_num[i+1]=arr_num[i]/arr_num[i+1];
            arr_num[i]=0;
        }
    }


    /*-------------------------[print-2_array]-----------------*/
    for(i=0;i<50;i++){
        printf("arr[%d]=%c",i,arr[i]);
        printf("\tarr_num[%d]=%d",i,arr_num[i]);
        printf("\tarr_operant[%d]=%c\n",i,arr_operant[i]);
    }

    /*-------------------------[calculating & print resuls]-----------------*/
    result=arr_num[0];
    for(i=0;i<index_operant;i++){
        result=result+arr_num[i+1];
    }

    printf("\n\n\t\tresult=%d",result);



}
