void merge(int* numArray, int lowerB, int middle, int upperB, int& op_count, int& comp_count)
{
    int sizeLeft = middle - lowerB + 1;
    int sizeRight = upperB - middle;

    // int* leftArray =  new int[sizeLeft];
    // int* rightArray = new int[sizeRight];
    int leftArray[sizeLeft];
    int rightArray[sizeRight];

    for(int i = 0; i < sizeLeft; i++)
    {
        op_count++;
        leftArray[i] = numArray[lowerB + i];
    }
    for(int i = 0; i < sizeRight; i++)
    {
        op_count++;
        rightArray[i] = numArray[middle + 1 + i];
    }

    int i, j, k;
    i = 0; //index of the left array
    j = 0; //index of the right array
    k = lowerB; //index of the main array

    while((i < sizeLeft) && (j < sizeRight))
    {
        comp_count++;
        if(leftArray[i] <= rightArray[j])
        {
            op_count++;
            numArray[k] = leftArray[i];
            i++;
        }
        else
        {
            op_count++;
            numArray[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < sizeLeft)
    {
        op_count++;
        numArray[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < sizeRight)
    {
        op_count++;
        numArray[k] = rightArray[j];
        j++;
        k++;
    }
    // delete[] leftArray;
    // delete[] rightArray;
}

void mergeSort(int* numArray, int lowerB, int upperB, int& op_count, int& comp_count)
{
    if(lowerB >= upperB)
        return;
    
    op_count++;
    int middle = lowerB + (upperB - lowerB)/2;
    mergeSort(numArray, lowerB, middle, op_count, comp_count);
    mergeSort(numArray, middle + 1, upperB, op_count, comp_count);
    merge(numArray, lowerB, middle, upperB, op_count, comp_count);
}