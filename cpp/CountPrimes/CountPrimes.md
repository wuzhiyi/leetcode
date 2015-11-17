###Count Primes
URL: https://leetcode.com/problems/count-primes/</br>
__Description:__</br>
Count the number of prime numbers less than a non-negative number, ___n___.

####Hint #1

Let's start with a _isPrime_ function. To determine if a number is prime, we need to check if it is not divisible by any number less than n. The runtime complexity of _isPrime_ function would be O(_n_) and hence counting the total prime numbers up to _n_ would be O(_n_^2). Could we do better?

####Hint #2

As we know the number must not be divisible by any number > _n_/2, we can immediately cut the total iterations half by dividing only up to _n_/2. Could we still do better?

####Hint #3

Let's write down all of 12's factors:

	2 × 6 = 12
	3 × 4 = 12
	4 × 3 = 12
	6 × 2 = 12

As you can see, calculations of 4 × 3 and 6 × 2 are not necessary. Therefore, we only need to consider factors up to √_n_ because, if _n_ is divisible by some number _p_, then n = _p_ × _q_ and since _p_ ≤ _q_, we could derive that _p_ ≤ √_n_.</br>
Our total runtime has now improved to O(_n_^1.5), which is slightly better. Is there a faster approach?

	public int countPrimes(int n) {
	   int count = 0;
	   for (int i = 1; i < n; i++) {
	      if (isPrime(i)) count++;
	   }
	   return count;
	}

	private boolean isPrime(int num) {
	   if (num <= 1) return false;
	   // Loop's ending condition is i * i <= num instead of i <= sqrt(num)
	   // to avoid repeatedly calling an expensive function sqrt().
	   for (int i = 2; i * i <= num; i++) {
	      if (num % i == 0) return false;
	   }
	   return true;
	}

####Hint #4

The [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) is one of the most efficient ways to find all prime numbers up to _n_. But don't let that name scare you, I promise that the concept is surprisingly simple.</br>
![img](Sieve_of_Eratosthenes_animation.gif)</br>
Sieve of Eratosthenes: algorithm steps for primes below 121. "[Sieve of Eratosthenes Aniamation](https://commons.wikimedia.org/wiki/File:Sieve_of_Eratosthenes_animation.gif)" by SKopp.</br>
We start off with a table of _n_ numbers. Let's look at the first number, 2. We know all multiples of 2 must not be primes, so we mark them off as non-primes. Then we look at the next number, 3. Similarly, all multiples of 3 such as 3 × 2 = 6, 3 × 3 = 9, ... must not be primes, so we mark them off as well. Now we look at the next number, 4, which was already marked off. What does this tell you? Should you mark off all multiples of 4 as well?

####Hint #5

4 is not a prime because it is divisible by 2, which means all multiples of 4 must also be divisible by 2 and were already marked off. So we can skip 4 immediately and go to the next number, 5. Now, all multiples of 5 such as 5 × 2 = 10, 5 × 3 = 15, 5 × 4 = 20, 5 × 5 = 25, ... can be marked off. There is a slight optimization here, we do not need to start from 5 × 2 = 10. Where should we start marking off?

####Hint #6

In fact, we can mark off multiples of 5 starting at 5 × 5 = 25, because 5 × 2 = 10 was already marked off by multiple of 2, similarly 5 × 3 = 15 was already marked off by multiple of 3. Therefore, if the current number is _p_, we can always mark off multiples of _p_ starting at _p_^2, then in increments of _p_: _p_^2 + _p_, _p_^2 + 2_p_, ... Now what should be the terminating loop condition?

####Hint #7

It is easy to say that the terminating loop condition is _p_ < _n_, which is certainly correct but not efficient. Do you still remember _Hint #3_?

####Hint #8

Yes, the terminating loop condition can be _p_ < √_n_, as all non-primes ≥ √_n_ must have already been marked off. When the loop terminates, all the numbers in the table that are non-marked are prime.</br>
The Sieve of Eratosthenes uses an extra O(n) memory and its runtime complexity is O(_n_ log log _n_). For the more mathematically inclined readers, you can read more about its algorithm complexity on [Wikipedia](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Algorithm_complexity).

	public int countPrimes(int n) {
	   boolean[] isPrime = new boolean[n];
	   for (int i = 2; i < n; i++) {
	      isPrime[i] = true;
	   }
	   // Loop's ending condition is i * i < n instead of i < sqrt(n)
	   // to avoid repeatedly calling an expensive function sqrt().
	   for (int i = 2; i * i < n; i++) {
	      if (!isPrime[i]) continue;
	      for (int j = i * i; j < n; j += i) {
	         isPrime[j] = false;
	      }
	   }
	   int count = 0;
	   for (int i = 2; i < n; i++) {
	      if (isPrime[i]) count++;
	   }
	   return count;
	}

__Code:__

	#include <stdlib.h>
	#include <iostream>
	#include <vector>
	using namespace std;

	int countPrimes(int n) {
		//初始化vector容器，初始值全部为true
	    vector<bool> isPrimer(n, true); 						//1
	    //i从2开始，i的整数积，从isPrimer容器中删去
	    for(int i=2; i*i<n; i++){
	        if (isPrimer[i]){
	            for(int j=i*i; j<n; j+=i){
	                isPrimer[j] = false;
	            }
	        }
	    }
	    //输出vector中，isPrimer标记为true的值
	    int cnt = 0;
	    for(int i=2; i<n; i++){
	        if (isPrimer[i]) { 
	            //cout << i << ", ";
	            cnt++;
	        }
	    }
	    return cnt;
	}


	int main(int argc, char**argv) 
	{
	    int n = 100;
	    if (argc>1){
	        n = atoi(argv[1]);
	    }
	  
	    cout << endl << n << " : " << countPrimes(n) << endl;

	    return 0;
	}

##1 vector<bool>

标准库为 `bool` 类型专门提供了一个特殊 std::vecor，使其空间效率最高。