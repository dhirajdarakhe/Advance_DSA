// DHIRAJ LAXMAN DARAKHE
// 21118 (com)
// PICT, PUNE


// HEAP SORT
#include <bits/stdc++.h>
using namespace std;
class HeapSort
{
public:
    int *harr;
    int *harrUnsoerted;
    int *harrsoerted;
    int heap_size;
    int capacity;
    HeapSort(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[capacity];
        harrUnsoerted = new int[capacity];
        harrsoerted = new int[capacity];
    }
    void Insert()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "\nEnter Data : ";
            int element;
            cin >> element;
            harr[i] = element;
            harrUnsoerted[i] = element;
            heap_size++;
        }
        heap_size = capacity;
        return;
    }
    int Right(int i)
    {
        return (2 * i) + 2;
    }
    int Left(int i)
    {
        return (2 * i) + 1;
    }
    int Parent(int i)
    {
        return (i - 1) / 2;
    }
    void MinHeapify(int i)
    {
        int L = Left(i);
        int R = Right(i);
        int smallest = i;
        if (L < heap_size && harr[L] < harr[smallest])
            smallest = L;
        if (R < heap_size && harr[R] < harr[smallest])
            smallest = R;
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
    int MinExtract()
    {
        if (heap_size <= 0)
        {
            cout << "\nMinHeap Tree is Empty ";
        }
        if (heap_size == 1)
        {
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
        return root;
    }
    void PrintUnsortedArray()
    {
        cout << "\nUnsorted Data  : ";
        cout << " [ ";
        for (int i = 0; i < capacity; i++)
        {
            cout << harrUnsoerted[i] << " ";
        }
        cout << "] ";
        cout << "\n";
        return;
    }
    void Makesorted()
    {
        for (int i = capacity / 2 - 1; i >= 0; --i)
        {
            MinHeapify(i);
        }
        for (int i = 0; i < capacity; i++)
        {
            int ans = MinExtract();
            harrsoerted[i] = ans;
        }
    }
    void PrintSortedArray()
    {
        cout << "\nSorted Data : ";
        cout << " [ ";
        for (int i = 0; i < capacity; i++)
        {
            // int ans = MinFExtract();
            cout << harrsoerted[i] << " ";
        }
        cout << "] ";
        cout << "\n";
    }
};
int main()
{
    int s;
    cout << "\nEnter the Size of Array : ";
    cin >> s;
    HeapSort obj(s);
    int flag = 1, flag2 = 1;
    int option, val;
    do
    {
        cout << "\n\n \t**  MENU ** "
             << "\nWhich operation do you want to perform "
             << "\nSelect the Operation Number Or Enter 0 to Exit the Program "
             << "\n 1. Insert "
             << "\n 2. PrintUnsorted Array "
             << "\n 3. PrintSorted Array "
             << "\n 0. Exit ";
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            flag = 0;
            obj.Insert();
            break;
        case 2:
            if (flag)
            {
                cout << "\nPlease Firstly Insert the Data in the MinHeap Tree ";
                break;
            }
            obj.PrintUnsortedArray();
            break;
        case 3:
            if (flag)
            {
                cout << "\nPlease Firstly Insert the Data in the MinHeap Tree ";
                break;
            }
            if (flag2)
            {
                obj.Makesorted();
                flag2 = 0;
            }
            obj.PrintSortedArray();
            break;
        default:
            cout << "\nEnter the correct option ";
            break;
        }
    } while (option != 0);
    return 0;
}