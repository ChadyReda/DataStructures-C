#include <stdio.h>
#include <stdlib.h>

void func (int n) {
   if (n > 0) {
    func(n - 1);    
    printf("%d\n", n);
   } 
}


int main() {
    func(3);
    return 0;
}
