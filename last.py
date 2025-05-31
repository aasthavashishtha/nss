from sympy import mod_inverse, isprime
import hashlib
from math import gcd
import random

def generate_prime():
    while True :
        num = random.randint(50,200)
        if(isprime(num)):
            return num
        
def pickpublickey(phi):
    while True:
        e = random.randint(2,phi-1)
        if(gcd(e,phi)==1) :
            return e

def generate_key():
    p = generate_prime()
    q = generate_prime()
    n = p*q
    phi = (p-1)*(q-1)
    e = pickpublickey(phi)
    d = mod_inverse(e,phi)
    if(e == d):
        return generate_key()
    return (e,n) , (d,n)

def encrypt(msg, )

        