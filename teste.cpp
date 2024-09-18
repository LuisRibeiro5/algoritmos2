#include <iostream>
#include <algorithm>

int main(){
    int arr[] = {2,0,9,8,3,2,7,5,1,9};
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if(arr[j] < arr[j + 1]){
                std::swap(arr[j],arr[j + 1]);
            }
        }
        
    }
    
    
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << ", ";
    }
    

    return 0;
}

