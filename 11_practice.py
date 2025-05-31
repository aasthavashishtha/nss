from sympy import mod_inverse , isprime
import hashlib
import random
from math import gcd

def generate_prime():
    while True:
        num = random.randint(50, 200)
        if (isprime(num)) :
            return num
        
def pickPublicKey(phi):
    while True:
        e = random.randint(2,phi-1)
        if(gcd(e,phi)==1) :
            return e

def generate_key() :
    p = generate_prime()
    q = generate_prime()
    n = p*q
    phi = (p-1)*(q-1)
    e = pickPublicKey(phi)
    d = mod_inverse(e,phi) 
    if(e == d):
        return generate_key()
    return (e,n) , (d,n)

def encrypt(msg , public_key) :
    e,n = public_key
    cipher = []
    for char in msg :
        cipher.append(pow(ord(char),e,n))
    return cipher

def decrypt(msg, orivate_key) :
    d,n = orivate_key
    result = ""
    for char in msg :
        result += chr(pow(char,d,n))

def main() :
    pair_key_A = generate_key()
    pair_key_B = generate_key()
    msg = input("enter msg")
    print("..sender..")
    hashed = hashlib.sha256(msg.encode()).hex.diegest()
    concat_msg = msg+"@"+hashed
    enctypted_msg = encrypt(concat_msg, pair_key_B[0])
    newmsg = ""
    for num in enctypted_msg :
        newmsg += chr(num)

    signed_msg = encrypt(newmsg, pair_key_A[1])
    print(signed_msg)

    print("..receiver..")
    decryptedsg = decrypt(signed_msg, pair_key_A[0])
    newarr = []
    for char in decryptedsg:
        newarr.append(ord(char))

    signeddecrypt = decrypt(newarr, pair_key_B[1])

    if "@" in signeddecrypt : 
        ori , hashednew = signeddecrypt.split("@",1)
        cretedhash

