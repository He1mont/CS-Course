loop :: [a]
loop = tail loop

ones :: [Int]
ones = 1:ones

-- the sieve of Erathosthenes
primes :: [Int]
primes = sieve [2..]

sieve :: [Int] -> [Int]
sieve (p:xs)
     = p : sieve [x| x<-xs, x `mod` p /= 0]

