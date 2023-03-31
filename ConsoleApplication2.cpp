#include <iostream>
using namespace std;
// array integers to hold values
int arr[20];
int cmp_count = 0; // number of comparison
int mov_count = 0; // number of movment
int n;

void input()
{
    while (true)
    {
        cout << "Masukan panjang element array : ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\n Masukan penjnag array 20" << endl;
    }
    cout << " \n ==================";
    cout << "\n Enter array Element";
    cout << "\n ===================";

    for (int i = 0; i < n; i++)

    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];
    }
}
// swap the element at_index x with element at y

void swap(int x, int y)
{
    int temp;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void q_short(int low, int high)
{
    int pivot, i, j;
    if (low > high)
        return; // langkah 1

    // partition the lisr into two parts
    // one containing element less than or equal to
    // othercontaining element

    i = low + 1;      // langkah 3
    j = high;         // langkah 4
    pivot = arr[low]; // langkah 2

    while (i <= j) // lengkah 10
    {
        // search for element greater than pivot
        while ((arr[i] <= pivot) && (i <= high)) // lengkah 10
        {
            i++; // lengkah 16
            cmp_count++;
        }
        cmp_count++;
        // search for element less than or equal to pivot
        while ((arr[j] > pivot) && (j >= low)) // lengkah 7
        {
            j--; // lengkah 8
            cmp_count++;
        }
    }
    cmp_count++;
    if (i < j) // lengkah 9
        // if greater element is on left the element
    {
        // swap the element at index i with the element of index j
        swap(i, j);
        mov_count++;
    }
    // sort the list on the left of pivot using quick sort
    q_short(low, j - 1); // lengkah 12
    // sort the list on the right of pivot using quick sort
    q_short(j + 1, high); // lengkah 13
}

void display()
{
    cout << "\n =================" << endl;
    cout << "\n Sorted Array :    " << endl;
    cout << "\n ==================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n Number of comparisons: " << cmp_count << endl;
    cout << "\n Number of data movement: " << mov_count << endl;
}

int main()
{
    input();
    // sort array using quicksort
    q_short(0, n - 1);
    display();
    system("pause");
    return 0;
}