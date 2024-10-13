//Cooper Wright | Lab05 | EECS 348

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global array months
char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int monthSaleReport(char *sales[12]){ 
    printf("Monthly Sales Report for 2024\n\nMonth\t\tSales\n"); //print header
    for (int j = 0 ; j < 12 ; j++){ //loop the sales
        printf("%s", months[j]);
        char *tabs;
        if (j == 1 || j == 8 || j == 10 || j == 11){ //fix tabs for longer months
            tabs = "\t";
        } else{
            tabs = "\t\t";
        }
        printf("%s",tabs);
        printf("%s", sales[j]);
    }
    return 0;
}

int salesSummaryReport(float sales[12]){
    float max = 0;
    float min = 1000000.00; //large number for starting min
    float average = 0;
    char* maxMonth;
    char* minMonth;

    for (int j = 0 ; j < 12 ; j++){ //loop sales and compare
        if (sales[j] > max){
            max = sales[j];
            maxMonth = months[j];
        }
        if (sales[j] < min){
            min = sales[j];
            minMonth = months[j];
        }
        average = average + sales[j]; //add all sales
    }

    average = average / 12; //then divide by 12 for average

    printf("\n\nSales summary report:\n\n");
    printf("Minimum sales: ");
    printf("%f ", min);
    printf("(");
    printf("%s", minMonth);
    printf(")\n");

    printf("Maximum sales: ");
    printf("%f ", max);
    printf("(");
    printf("%s", maxMonth);
    printf(")\n");

    printf("Average sales: ");
    printf("%f ", average);

    return 0;
}

int movingAverageReport(float sales[12]){
    float maverage;
    printf("\n\nSix-month moving average report:\n\n");

    for (int j = 0 ; j < 7 ; j++){ //loop through sales (only 7 times for 6 month interval moving averages)
        maverage = (sales[j] + sales[j+1] + sales[j+2] + sales[j+3] + sales[j+4] + sales[j+5]) / 6; //calculate average

        printf("%s-%s\t", months[j], months[j+5]);
        printf("%f\n", maverage);
    }

    return 0;
}

int salesReportHtoL(float sales[12]){
    float sortedSales[12];
    float currentMax;
    int currentMaxIndex;
    char* tabs;

    printf("\nSales report (highest to lowest):\n\nMonth\t\tSales");

    for (int j = 0 ; j < 12 ; j++){ //loop 12 sales outer for outputting each
        currentMax = 0.0;
        currentMaxIndex = 0;
        
        for (int l = 0 ; l < 12 ; l++){ //loop sales for finding the highest value left
            if (sales[l] > currentMax){
                currentMax = sales[l];
                currentMaxIndex = l;
            }
        }

        if (currentMaxIndex == 1 || currentMaxIndex == 8 || currentMaxIndex == 10 || currentMaxIndex == 11){ //fix the tabs again
            tabs = "\t";
        } else{
            tabs = "\t\t";
        }

        printf("\n%s%s$%f", months[currentMaxIndex] , tabs , currentMax); 
        sales[currentMaxIndex] = 0; //set the max we just used to 0 so it isnt reused
    }

    return 0;
}


int main(){
    FILE *file = fopen("code1Input.txt", "r"); //open file
    int i = 0;
    char line[32]; 
    char* lines[12];
    while (fgets(line, sizeof(line), file) != NULL){  //loop file lines     
        lines[i] = malloc(strlen(line));
        strcpy(lines[i], line);
        i++;
    }

    monthSaleReport(lines); //run function

    float linesFloats[12];
    for (int k = 0 ; k < 12 ; k++){ //change the array of stings we have to floats for math in later functions
        linesFloats[k] = atof(lines[k]);
    }
    
    salesSummaryReport(linesFloats); //run function

    movingAverageReport(linesFloats); //run function

    salesReportHtoL(linesFloats); //run function

    fclose(file); //close file
    return 0;
}