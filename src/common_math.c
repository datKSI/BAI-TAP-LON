#include <math.h>
#include "../include/common_math.h"

/*
 * NHIỆM VỤ: VIẾT CÁC HÀM TOÁN HỌC CƠ BẢN
 */

// 1. Hàm kiểm tra số Fibonacci
// Logic: Trả về true nếu n là số Fibonacci (0, 1, 1, 2, 3, 5...), ngược lại false.
int isFibonacci(int n){
    if(n==0||n==1) return 1;
    long long fn2=0,fn1=1;
    for(int i=2;i<=92;i++){
        long long fn=fn1+fn2;
        if(fn==n) return 1;
        if(fn>n) return 0;
        fn2=fn1;
        fn1=fn;
    }
    return 0;
}

// 2. Hàm tính tổng ước số thực sự (Proper Divisors)
// Logic: Tính tổng các ước số của n (không bao gồm chính n).
// Ví dụ: n=10 -> ước là 1, 2, 5 -> Tổng = 8.
int sumProperDivisors(int n){
    if(n<=1) return 0;
    int sum=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            sum+=i;
            int j=n/i;
            if(j!=i) sum+=j;
        }
    }
    return sum;
}

// 3. Hàm làm tròn số thực
// Logic: Làm tròn số thực n thành số nguyên gần nhất (theo chuẩn toán học).
int myRound(double n){
    return (int)round(n);
}
