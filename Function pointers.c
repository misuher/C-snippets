//Normal function to make an example
int sum(int n, int m){
    return n+m;
}

//pointer function definition to point owr example:
int (*pfunc)(int,int);

//point to owr example:
pfunct = &sum;

//call sum throught the pointer
int result = (*pfunct)(2,3);

//Passing a function pointer to a function as parameter
int sum2to3(  int (*pfunc)(int,int)  ){
    return (*pfunc)(2,3);
}

//return a function pointer
int  (*pfunc(int parameter1,int  parameter2))(int, int){
    printf("parameters: %d and %d", parameter1, parameter2);
    int (*pfunc)(int, int) = &sum;
    return pfunc;
}

//using typedef creates a function pointer type with the name of the pointer
typedef int (*pfunc)(int,int);

pfunc myfunction(int parameter1,int  parameter2){
    printf("parameters: %d and %d", parameter1, parameter2);
    pfunc myfunctionpointer = &sum;
    return myfunctionpointer;
}