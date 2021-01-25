#include <stdio.h>
#include <stdlib.h>
int global_var=100;

void func1()
{
    printf("[*] IN: %s\n",__func__);
    printf("Hello World\n");
    void *addr1 = __builtin_extract_return_addr (__builtin_return_address (0));
    printf(" Return addr of %s: %p\n", __func__,addr1);
    void *addr_f1 =  __builtin_frame_address(0);
    printf(" Frame addr of %s: %p \n", __func__,addr_f1);
}


void func3()
{
    printf("[*] IN: %s\n",__func__);
    
    void *addr1 = __builtin_extract_return_addr (__builtin_return_address (0));
    //printf(" Return addr of %s: %p\n", __func__,addr1);
    printf(" ADDRESS1: %p\n",addr1);
    
    void *addr2 = __builtin_extract_return_addr (__builtin_return_address (1));
    //printf(" Return addr of caller of %s (level 1): %p\n", __func__,addr2);
    printf(" ADDRESS2: %p\n",addr2);
    
    
    void *addr_f1 =__builtin_frame_address(0);
    printf(" Frame addr of %s: %p\n", __func__,addr_f1);
    
    void *addr_f2 =__builtin_frame_address(1);
    printf(" Frame addr of caller of %s (1): %p \n", __func__,addr_f2);
    
    void *addr_f3 =  __builtin_frame_address(2);
    printf(" Frame addr of caller's caller of %s (2): %p\n", __func__,addr_f3);

}

void func2(char *s)
{
    printf("[*] IN: %s\n",__func__);
    printf("%s\n",s);
    void *addr1 = __builtin_extract_return_addr (__builtin_return_address (0));
    printf(" Return addr of %s: %p\n", __func__,addr1);
    void *addr_f1 = __builtin_frame_address(0);
    printf(" Frame addr of %s: %p\n", __func__,addr_f1);
    void *addr_f2 = __builtin_frame_address(1);
    printf(" Frame addr of caller of %s (1): %p\n", __func__,addr_f2);
    func3();
}



int main()
{
	int i;
	int *p, *q, *x, *y;
    char hello[]="Hello World!";
    x= (int *)malloc(50);
    y=(int *)malloc(200);
	p=(int*) malloc(10000);
	q=(int*) malloc(100000);
    
    printf("BSS: address of global_var %p\n",&global_var);
	printf("Stack: address of i= %p\n",&i);
	printf("Stack: address of p= %p\n", &p);
	printf("Heap: address of heap object, pointed to by x (size 50)= %p\n", x);
	printf("Heap: address of heap object, pointed to by y (size 200)= %p, diff (y-x): %lu\n", y, (y-x)*sizeof(int));
	printf("Heap: address of heap object, pointed to by p (size 10000)= %p, diff (p-y): %lu\n", p, (p - y)*sizeof(int));
	printf("Heap: address of heap object, pointed to by q (size 100000)= %p, diff (q-p): %lu\n", q, (q - p)*sizeof(int));
    
    printf("Press any key to continue...");
    getchar();
    printf("[*] IN: %s\n",__func__);
    void *addr_f1 = __builtin_extract_return_addr ( __builtin_frame_address(0));
    printf(" Frame addr of %s: %p\n", __func__,addr_f1);
	func1();
    func2(hello);

    return 0;
}
