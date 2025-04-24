#include <iostream>

int searchArray(int array[], int size, int myNum);
int getUserinput();

int main(){

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof (numbers) / sizeof(numbers[0]);
    int index;
    int myNum = getUserinput();

    index = searchArray(numbers, size, myNum);

    if (index < 0)
    {
        std :: cout << "Not Found in this array" << std :: endl;
    }
    else
    {
        std :: cout << "Found " << myNum << " in index : " << index << std :: endl;
    }
    

    return 0;
}

int searchArray(int array[], int size, int myNum){
    
    for (int i = 0; i < size; i++)
    {
        if (array[i] == myNum)
        {
            return i;
        }
    }
    return -1;
}

int getUserinput(){
    int myNum;

    std :: cout << "Enter Element To search for : ";
    std :: cin >> myNum;
    //std ::cin.clear();
    //fflush(stdin);

    return myNum;
}
