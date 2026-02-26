#include <stdio.h> 


//function takes in data and figures out max min and average
void analyze_actuator(int* data, int length, int* min_pos, int* max_pos, float* avg_pos){
    int current_sum = 0;
    for (int i = 0; i < length; i++) {
        current_sum += data[i];
        if (data[i] < *min_pos) {
            *min_pos = data[i];
        } else if (data[i] > *max_pos) {
            *max_pos = data[i];
        }
    }
    *avg_pos = (float) current_sum/length;
}

//takes in the intital list to find inital min max etc (might move this into main function later)
void minmaxavgfinder() {

}


//formats userinput to add to the array
void takeinusrinput() {

}



int main(){
    int data[10] = {118, 122, 125, 115, 120,
        119, 124, 117, 121, 119};
    int len_data = 10;
    int min_pos = 120;
    int max_pos = 120;
    float avg_pos = 0;
    analyze_actuator(data, len_data, &min_pos, &max_pos, &avg_pos);
    printf("max position is: %d, min position is: %d, average is: %.2f", max_pos, min_pos, avg_pos);
    return 0;
}