#include <iostream>
#include <chrono>
using namespace std;

double* generateArray(int N){
    
    double *randArray = new double[N];

    for(int i = 0; i < N; i++)
       randArray[i]=rand()%2000-1000.0;

    return randArray;
}

double* generate95Array(int N){
    
    double *randArray = new double[N];

    for(int i = 0; i<(int)(N*0.95)+1; i++){
       randArray[i]=i;
    }

    for(int i = (int)(N*0.95) + 1; i < N; i++){
       randArray[i]=rand()%2000-1000.0;
    }

    return randArray;
}

void insertSortArray(double *a, int N){
    
    int buff = 0;
	int i, j;	

	for (i = 1; i < N; i++)
	{
		buff = a[i];

		for (j = i - 1; j >= 0 && a[j] > buff; j--)
					a[j + 1] = a[j];	

		a[j + 1] = buff;
	}
}

void siftDown(double* numbers, int root, int bottom)
{
    int maxChild;
    int done = 0;
    
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom) 
            maxChild = root * 2;
            
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
            
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}

void triangleSort(double* numbers, int array_size)
{
    
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
        
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

int main()
{

    int Ns[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000 };

    for(int i = 0; i < 11; i++){

	    double *a = generateArray(Ns[i]);
        double *b = generateArray(Ns[i]);

        auto start_1 = chrono::system_clock::now();
        insertSortArray(a, Ns[i]);
        auto end_1 = chrono::system_clock::now();
        chrono::duration<double> elapsed_1 = end_1 - start_1;
        cout << "[Insert sort      | N=" << Ns[i] << "] " << elapsed_1.count() << "s" << endl;

        auto start_2 = chrono::system_clock::now();
        triangleSort(b, Ns[i]);
        auto end_2 = chrono::system_clock::now();
        chrono::duration<double> elapsed_2 = end_2 - start_2;
        cout << "[Triangle sort    | N="<< Ns[i] << "] " << elapsed_2.count() << "s" << endl;



        double *a95 = generate95Array(Ns[i]);
        double *b95 = generate95Array(Ns[i]);

        auto start_1_95 = chrono::system_clock::now();
        insertSortArray(a95, Ns[i]);
        auto end_1_95 = chrono::system_clock::now();
        chrono::duration<double> elapsed_1_95 = end_1_95 - start_1_95;
        cout << "[Insert sort   95%| N=" << Ns[i] << "] " << elapsed_1_95.count() << "s" << endl;

        auto start_2_95 = chrono::system_clock::now();
        triangleSort(b95, Ns[i]);
        auto end_2_95 = chrono::system_clock::now();
        chrono::duration<double> elapsed_2_95 = end_2_95 - start_2_95;
        cout << "[Triangle sort 95%| N="<< Ns[i] << "] " << elapsed_2_95.count() << "s" << endl;

    }
}



// [Insert sort      | N=16000]     0.154062s
// [Triangle sort    | N=16000]     0.002992s
    
   
// [Insert sort   95%| N=16000]     0.028943s
// [Triangle sort 95%| N=16000]     0.001996s
    
   
// [Insert sort      | N=32000]     0.627354s
// [Triangle sort    | N=32000]     0.009984s
    
   
// [Insert sort   95%| N=32000]     0.13978s
// [Triangle sort 95%| N=32000]     0.004388s
    
   
// [Insert sort      | N=64000]     2.46457s
// [Triangle sort    | N=64000]     0.012327s
    
   
// [Insert sort   95%| N=64000]     0.477618s
// [Triangle sort 95%| N=64000]     0.009511s


// [Insert sort      | N=128000]    9.89718s
// [Triangle sort    | N=128000]    0.027309s
    
   
// [Insert sort   95%| N=128000]    1.90592s
// [Triangle sort 95%| N=128000]    0.019923s
    
   
// [Insert sort      | N=256000]    40.2855s
// [Triangle sort    | N=256000]    0.05835s
    
   
// [Insert sort   95%| N=256000]    7.72629s
// [Triangle sort 95%| N=256000]    0.040918s
    
   
// [Insert sort      | N=512000]    162.123s
// [Triangle sort    | N=512000]    0.126008s
    
   
// [Insert sort   95%| N=512000]    31.8375s
// [Triangle sort 95%| N=512000]    0.086635s


// [Insert sort      | N=1024000]   652.579s
// [Triangle sort    | N=1024000]   0.27143s
    
   
// [Insert sort   95%| N=1024000]   130.288s
// [Triangle sort 95%| N=1024000]   0.179405s
