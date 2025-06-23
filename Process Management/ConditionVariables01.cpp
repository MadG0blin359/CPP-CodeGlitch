#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
using namespace std;

pthread_mutex_t my_lock;
pthread_cond_t my_cond;
int condition = 0;

void* my_function1(void*) {
    pthread_mutex_lock(&my_lock);
    // work on shared variable
     cout << "check" << gettid() << endl;
    condition = 1;
    pthread_mutex_unlock(&my_lock);
    pthread_cond_signal(&my_cond);
    return NULL;
}

void* my_function2(void*) {
    pthread_mutex_lock(&my_lock);
    while (condition <= 0)
        pthread_cond_wait(&my_cond, &my_lock);
    // work on shared variable
     cout << "test" << gettid() << endl;
    pthread_mutex_unlock(&my_lock);
    return NULL;
}

int main(int argc, char* argv[]) {
	cout << "Total Arguments: " << argc << endl;
	cout << "File Name: " << argv[0] << endl;
	cout << "Argument 1: " << argv[1] << endl;
	cout << "Argument 2: " << argv[2] << endl;
	
	int arg1 = stoi(argv[1]);
	string arg2 = argv[2];
	
	cout << "\narg1: " << arg1;
	cout << "\narg2: " << arg2 << endl;
	
	
    pthread_mutex_init(&my_lock, NULL);
    pthread_cond_init(&my_cond, NULL);
    
    pthread_t tid[2];
    
    srand(time(NULL));
    cout << rand() % 15;
    int *id;
    id = new int[5];
    delete[] id;
    
    pthread_create(&tid[0], NULL, &my_function1, NULL);
    pthread_create(&tid[1], NULL, &my_function2, NULL);
    
    for (int i = 0; i < 2; i++) {
        pthread_join(tid[i], NULL);
    }
    
    pthread_mutex_destroy(&my_lock);
    pthread_cond_destroy(&my_cond);
    return 0;
}
