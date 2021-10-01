//Java program for the fractional knapsack problem

public class FractionalKnapsack{
    //the method to get the maximum possible total value given the knapsack capacity
    public static double maxValue(int [][] arr, int cap){
        //declaring variables to store values temporarily in the bubble sort
        int temp1, temp2;

        //value of each item is divided by its weight while traversing the array
        //performing a bubble sort to sort the array in descending order of their value to weight ratios
        for(int i=0; i<(arr.length-1); i++){
            for(int j=0; j<(arr.length-i-1); j++){
                if((arr[j][0]/arr[j][1]) < (arr[j+1][0]/arr[j+1][1])){
                    temp1 = arr[j][0];
                    temp2 = arr[j][1];
                    arr[j][0] = arr[j+1][0];
                    arr[j][1] = arr[j+1][1];
                    arr[j+1][0] = temp1;
                    arr[j+1][1] = temp2;
                }
            }
        }

        //initializing variables to store maximum possible total value (maxVal) and current total weight (w)
        double maxVal=0;
        int w=0;

        //loop to find the maximum possible total value
        for(int i=0; i<arr.length; i++){
            //if sum of current total weight (w) and selected weight (arr[i][1]) is less than or equal to
            //knapsack capacity (cap), then it is possible to take the whole item
            if((w+arr[i][1]) <= cap){
                //calculating current total weight and current maximum possible total value
                w += arr[i][1];
                maxVal += arr[i][0];
            }

            //else, it is not possible to take the whole item. Only a fraction of the item can be considered.
            else{
                //getting the remaining weight needed
                int remainder = cap - w;

                //finding the fraction of the item that can be taken
                double fraction = (double)remainder/arr[i][1];

                //calculating current total weight and current maximum possible total value
                w += remainder;
                maxVal += (arr[i][0] * fraction);
            }
        }

        //returning the maxVal as the result
        return maxVal;
    }

    public static void main(String [] args){
        //initializing a 2D array to store values and weights of each item {value, weight}
        int [][] items = {{80,40}, {150,30}, {100,10}};

        //initializing the knapsack capacity
        int capacity = 50;

        //printing the maximum possible total value of the problem
        System.out.println("Maximum possible total value in the knapsack = " + maxValue(items, capacity));
    }
}