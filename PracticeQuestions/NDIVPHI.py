#Author: RAGHUKUL RAMAN
#spoj NDIVPHI
#pay attention to the code :P

# m/phi(m) is product of all p1*p2/(p1-1)(p2-1) where p1 and p2 are prime factors of m
# so to maximise m/phi(m) the number should have maximim prime factors
# and those factors should be mimimum
# for n = 32 answer is 2*3*5 as for all other number p/(p-1) whould be less

prime = [True for i in range(110)]
p = 2
while p * p < 100:
    if prime[p]:
        for i in range(2 * p, 110, p):
            prime[i] = False
    p += 1
primeSum = [2]
count = 0
for i in range(3, 110):
    if prime[i]: #array to store product of primes
        primeSum.append(i * primeSum[count])
        count += 1
for i in range(20):
    t = raw_input()
    try:
        t = int(t)
    except:
        "Please enter a number"
    if t == 1: #for all inputs we we index just less than number
        print 1
        continue
    index = 0
    for i in range(len(primeSum)):
        if primeSum[i] > t:
            index = i
            break
    print primeSum[index - 1]
