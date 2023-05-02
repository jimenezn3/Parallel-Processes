#include <iostream>
#include <omp.h>

using namespace std;
void Foo(int, double[1000]);

int main(){

	double A[1000];
	omp_set_num_threads(4);
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		Foo(id, A);
	}
	cout << "All done" << endl;
	return 0;
}

void Foo(int myID, double MyA[1000]){
	cout << "thread: " << myID << endl;
	return;
}
