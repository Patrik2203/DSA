int min(int *arr, int n){
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    int i = 0;
    while(true){
        if(arr[i] == min){
            arr[i] = 101;
            break;
        }
        i++;
    }
    return min;
}
int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    int sum = 0;
    for(int i = 0; i < seatsSize; i++){
        int min1 = min(seats, seatsSize);
        int min2 = min(students, studentsSize);

        sum += abs(min1 - min2);
    }
    return sum;
     
}
