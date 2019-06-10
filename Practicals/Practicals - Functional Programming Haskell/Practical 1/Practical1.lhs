Practical 1: Factoring Numbers

Here is a simple method for finding the smallest prime factor of a positive
integer:

> factor :: Integer -> (Integer, Integer)
> factor n = factorFrom 2 n

> factorFrom :: Integer -> Integer -> (Integer, Integer)
> factorFrom m n | r == 0    = (m,q)
>                | otherwise = factorFrom (m+1) n
>    where (q,r) = n `divMod` m

for example

*Main> factor 7654321
(19,402859)

because

*Main> 19 * 402859
7654321

Repeatedly extracting the smallest factor will return a list
of prime factors:

> factors :: Integer -> [Integer]
> factors n = factorsFrom 2 n

> factorsFrom :: Integer -> Integer -> [Integer]
> factorsFrom m n | n == 1    = []
>                 | otherwise = p:factorsFrom p q
>    where (p,q) = factorFrom m n

for example

*Main> factor 123456789
(3,41152263)
*Main> factors 123456789
[3,3,3607,3803]


Exercise 1
----------

factor 0 = (2,0)
factor 1 = will continue computing as the remainder will never be 0 (no output)

Exercise 2
----------

Exercise 3
----------

Suppose that n = a*b, with the condition that a<=b. Now, suppose that a is the smallest factor of n
Suppose that a is bigger than sqrt(n) and less than n. If this is true, then b should be a number
between a and n. So, both a and b are strictly bigger than sqrt(n). a>sqrt(n), b>=a, b>sqrt(n), so
a*b>sqrt(n)*sqrt(n)=n, so it will exceed n. Hence we came to a contradiction. The smallest factor of n
cannot be bigger than sqrt(n) and smaller than n.

> factor1 :: Integer -> (Integer, Integer)
> factor1 x = factorFrom1 2 x

> factorFrom1 :: Integer->Integer->(Integer,Integer)
> factorFrom1 m n
>     | r==0        = (m,q)
>     | n<=m*m      = (1,n)
>     | otherwise   = factorFrom1 (m+1) n
>   where (q,r) = divMod n m

If more equations' guards are true, then their order counts as the program will use the first
that is true.
In the worst case, the maximum number of recursions would be sqrt(n). This happens if n is either
a perfect square of a prime number, or a prime number. This way, n has no factor between 2 and sqrt(n)
and the program will compute all these values.

Exercise 4
----------

If we use q<m instead of n<=m*m it is the same thing because : q is actually n/m and when q will
exceed m it would mean that q is lower than sqrt(n) and m is greater than sqrt(n). (n<=m*m is
sqrt(n)<=m).so q<m equivalent with (since n=q*m+r) q>sqrt(n) and that with m<sqrt(n) <=> sqrt(n)<=m )
It is more efficient because instead of multiplying and than comparing, we can just compare

> factor2 :: Integer -> (Integer,Integer)
> factor2 x = factorFrom2 2 x

> factorFrom2 :: Integer -> Integer -> (Integer,Integer)
> factorFrom2 m n
>     | r==0      = (m,q)
>     | q<m       = (1,n)
>     | otherwise = factorFrom2 (m+1) n
>   where (q,r) = divMod n m

*Main> factor2 666013
(1,666013)
(0.01 secs, 436,048 bytes)

*Main> factor2 1000000007
(1,1000000007)
(0.05 secs, 14,489,080 bytes)

*Main> factor2 (666013*666013)
(666013,666013)
(0.73 secs, 303,772,344 bytes)


Exercise 5
----------

> factor3 :: Integer -> (Integer,Integer)
> factor3 x
>   | (x `mod` 2 ==0 ) = (2,x `div` 2)
>   | otherwise        = factorFrom3 3 x

> factorFrom3 :: Integer -> Integer -> (Integer,Integer)
> factorFrom3 m n
>     | r==0      = (m,q)
>     | q<m       = (1,n)
>     | otherwise = factorFrom3 (m+2) n
>   where (q,r) = divMod n m

I expect this version to be twice as fast as the previous ones (as i will only take half of
the numbers)

Exercise 6
----------

*Main> factor3 (1000000007)
(1,1000000007)
(0.03 secs, 7,275,928 bytes)

*Main> factor3 (666013*666013)
(666013,666013)
(0.36 secs, 151,923,264 bytes)

*Main> factor3 (12432893)
(11,1130263)
(0.00 secs, 69,760 bytes)

Exercise 7
----------

> factor4 :: Integer -> (Integer,Integer)
> factor4 x
>   | (x `mod` 2 == 0) = (2,x `div` 2)
>   | (x `mod` 3 == 0) = (3,x `div` 3)
>   | otherwise        = factorFrom4 5 x 2

> factorFrom4 :: Integer -> Integer -> Integer -> (Integer,Integer)
> factorFrom4 m n s
>       | (r==0)    = (m,q)
>       | (q<m)     = (1,n)
>       | otherwise = factorFrom4 (m+s) n (6-s)
>   where (q,r) = divMod n m

*Main> factor4 1000000007
(1,1000000007)
(0.02 secs, 5,635,224 bytes)

*Main> factor4 (1000000007*666013)
(666013,1000000007)
(0.29 secs, 117,291,960 bytes)

*Main> factor4 (666013*666013)
(666013,666013)
(0.29 secs, 117,287,592 bytes)

Exercise 8
----------

The problem with such an idea is that we need to find the prime numbers and store them, and to do that
we would use at least as many resources in terms of time and memory.

Exercise 9
----------

> factors2 :: Integer -> [Integer]
> factors2 x
>   | (x `mod` 2 == 0) = 2:factors2 (x `div` 2)
>   | (x `mod` 3 == 0) = 3:factors2 (x `div` 3)
>   | otherwise = factorsFrom2 5 x

> factorsFrom2 :: Integer -> Integer -> [Integer]
> factorsFrom2 m n
>     | (n == 1)        = []
>     | (p == 1)       	= [q]
>     | otherwise       = p:factorsFrom2 p q
>   where (p,q) = factorFrom4 m n (if (m-1) `mod` 6 == 0 then 4 else 2)

*Main> factors2 (666013*666013*666019*666667*666013*666019)
[666013,666013,666013,666019,666019,666667]
(0.54 secs, 163,501,320 bytes)

*Main> factors2 (123456789123123445)
[5,11,17,131,1007933943937]
(0.76 secs, 216,948,136 bytes)

*Main> factors2 (666013*2*4*5)
[2,2,2,5,666013]
(0.01 secs, 254,752 bytes)

Exercise 10
-----------

*Main> factors 666013
[666013]
(0.98 secs, 330,415,856 bytes)

*Main> factors2 666013
[666013]
(0.00 secs, 248,952 bytes)


*Main> factors (666013*13*19*12*12)
[2,2,2,2,3,3,13,19,666013]
(0.98 secs, 330,435,656 bytes)

*Main> factors2 (666013*13*19*12*12)
[2,2,2,2,3,3,13,19,666013]
(0.01 secs, 269,176 bytes)


*Main> factors (666013*13*19*12*12*666667*13)
[2,2,2,2,3,3,13,13,19,666013,666667]
(0.99 secs, 330,771,528 bytes)

*Main> factors2 (666013*13*19*12*12*666667*13)
[2,2,2,2,3,3,13,13,19,666013,666667]
(0.50 secs, 143,961,560 bytes)


*Main> factors (123321123321)
[3,11,37,101,101,9901]
(0.02 secs, 5,000,120 bytes)

*Main> factors2 (123321123321)
[3,11,37,101,101,9901]
(0.00 secs, 114,072 bytes)

Obviously, factors2 is much faster than factors.
Time to solve Jevons' problem:

	factors   : 0.15s
	factors 2 : 0.07s

OPTIONAL PROBLEMS
-----------------
-----------------

Exercise 11
-----------

> fermat :: Integer -> (Integer,Integer)
> fermat x = search (isqrt(x)) 0 x

> search :: Integer -> Integer -> Integer -> (Integer,Integer)
> search p q n
>		| r < 0  = search (p+1) q n
>		| r > 0  = search p (q+1) n
>		| r == 0 = (p-q,p+q)
> 	where r = p*p - q*q - n

Exercise 12
-----------

> isqrt :: Integer -> Integer
> isqrt = truncate . sqrt . fromInteger

Exercise 13
-----------

Jevon's Problem

*Main> fermat 8616460799
(89681,96079)
(0.02 secs, 1,766,776 bytes)

Factors of 1963272347809

*Main> fermat 1963272347809
(241679,8123471)
(13.08 secs, 3,339,917,752 bytes)

Exercise 14
-----------

> fermat2 :: Integer -> (Integer,Integer)
> fermat2 x = search2 s 0 x (s*s-x)
>	where s = isqrt(x)

> search2 :: Integer -> Integer -> Integer -> Integer -> (Integer,Integer)
> search2 p q n r
>               | r < 0  = search2 (p+1) q n (r+2*p+1)
>               | r > 0  = search2 p (q+1) n (r-2*q-1)
>               | r == 0 = (p-q,p+q)

*Main> fermat2 8616460799
(89681,96079)
(0.01 secs, 1,687,488 bytes)

*Main> fermat2 1963272347809
(241679,8123471)
(6.13 secs, 3,089,578,464 bytes)

Exercise 15
-----------

> isqrt2 :: Integer -> Integer
> isqrt2 0 = 0
> isqrt2 x
>		| x < 4 		        = 1
>		| (m*m) <= x && (m+1)*(m+1) > x = m
>		| otherwise 		        = m+1
> 	where m = isqrt2 (x-1)

Given that n and m are positive integers, it means that if m*m <= n then m <= sqrt(n) and if m <= sqrt(n) then m*m <= n. In other words, if there is an inequality between positive numbers, the same inequality holds for the square of those numbers and also for their square roots.

*Main> isqrt2 666013
816
(3.08 secs, 577,892,304 bytes)
*Main> isqrt2 (1000*1000)
1000
(4.74 secs, 867,640,952 bytes)
*Main> isqrt2 (10000)
100
(0.05 secs, 8,729,808 bytes)

l < l+1 < r
l < r-1 < r
2l < l+r < 2r
l < (l+r) div 2 < r

Exercise 16
-----------

> split :: Integer ->  (Integer,Integer) -> (Integer,Integer)
> split n (l,r)
> 		| m*m <= n  = (m,r)
>		| otherwise = (l,m)
>	where m = (l+r) `div` 2

Exercise 17
-----------

It would take aproximately log2 (n) steps to reach the desired number.

> isqrt3 :: Integer -> Integer
> isqrt3 n = fst (bs n (1,n) )

> bs :: Integer -> (Integer,Integer) -> (Integer,Integer)
> bs x (l,r)
> 	| l+1 == r  = (l,r)
> 	| otherwise = bs x (split x (l,r))

*Main> isqrt3 (100000*100000)
100000
(0.01 secs, 89,440 bytes)
*Main> isqrt3 (100000000*100000000)
100000000
(0.01 secs, 103,712 bytes)
*Main> isqrt3 (10000000000*10000000000)
10000000000
(0.01 secs, 117,584 bytes)
*Main> isqrt3 (10^100)
100000000000000000000000000000000000000000000000000
(0.01 secs, 406,752 bytes)

Exercise 18
-----------

> upperbound :: Integer -> Integer -> Integer
> upperbound n b
> 	| b > n     = b
>	| otherwise = upperbound n (b*2)

> isqrt4 :: Integer -> Integer
> isqrt4 x = fst ( bs x (1, upperbound x 1) )

The change is not worthy as the upperbound is greater or equal to n and the binary search is not influenced by that, and even more, its number of steps being log2 n can actually be increased. All this added to the steps required to compute the upper bound.

*Main> isqrt4 (10^100)
100000000000000000000000000000000000000000000000000
(0.02 secs, 458,560 bytes)
*Main> isqrt4 (10000000000*10000000000)
10000000000
(0.01 secs, 121,632 bytes)
