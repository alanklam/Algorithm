//  This C++ program calculate the expected value of the product of the results of rolling
//  n dice at the same time.
//  Uses recussive call to solve the problem. Complexity = O(log(n))
//
//  Created by Kin Lam on 10/29/16.
//  Copyright (c) 2016 Kin Lam. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;

int summation (int n ) {
    if (n<3) {
        return 0;
    } else {
        int sum = 0;
        for (int i=2; i<=(n-1); i++ ){
            sum+=5*i+1;
        }
        return sum;
    }
}


long double expectedproduct (int n, int sum, long double* mapresult)
{
    int index = summation(n)+sum-n;
    if ( mapresult[index]==0 ) {
      long double result = 0;
      int count = 0;
      if ( n==2 ) {
          count=0;
          for (int i=1; i<=6; i++) {
              if ( (sum-i>=1) && (sum-i<=6) )  {
              result+=i*(sum-i);
              count++;
              }
          }
          result=result/count;
      } else
      {
          count=0;
          for (int i = 1; i<=6; i++) {
           if ( (sum-i>=n-1) && (sum-i<=6*(n-1)) ) {
              result+=i*expectedproduct(n-1,sum-i,mapresult);
              count++;
           }
          }
          result=result/count;
      }
      mapresult[index] = result;
      return result;
    } else {
      return mapresult[index];
    }
}


int main() {
    int n; int sum; long double expectvalue;
    double duration;
    std::clock_t start;
    start = std::clock();
    
    
    
    std::cout << "Enter n and sum:";
    std::cin>>n>>sum;
    const int memspace = summation(n+1);
// use dynamic array to store results that have already been calculate
    long double* mapresult = new long double[memspace] ();
    
    expectvalue=expectedproduct(n,sum,mapresult);
    std::cout << "Expected product =" << expectvalue<<endl;
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<< duration<<endl;
    
    
    delete[] mapresult;
    return 0;
}
