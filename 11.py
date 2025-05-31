from sympy import mod_inverse, isprime
import random
import hashlib
from math import gcd

def generate_prime():
    while True:
        num = random.randint(50, 200)
        if isprime(num):
            return num

def pickPublicKey(phi):
    while True:
        e = random.randint(2, phi - 1)
        if gcd(e, phi) == 1:
            return e

def generate_key():
    p = generate_prime()
    q = generate_prime()
    while p == q:
        q = generate_prime()
    n = p * q
    phi = (p - 1) * (q - 1)
    e = pickPublicKey(phi)
    d = mod_inverse(e, phi)
    if e == d:
        return generate_key()
    return (e, n), (d, n)

def encrypt(message, public_key):
    e, n = public_key
    cipher = []
    for char in message:
        cipher.append(pow(ord(char), e, n))
    return cipher

def decrypt(cipher, private_key):
    d, n = private_key
    message = ''
    for char in cipher:
        message += chr(pow(char, d, n))
    return message

def main():
    pair_key_A = generate_key()
    pair_key_B = generate_key()

    print("Public key of A =", pair_key_A[0])
    print("Private key of A =", pair_key_A[1])
    print("Public key of B =", pair_key_B[0])
    print("Private key of B =", pair_key_B[1])
    
    print("...Sender's Side (A)...")

    message = input("Enter your message: ")
    hash_message = hashlib.sha256(message.encode()).hexdigest()
    concat_message = message + "@" + hash_message
    encrypted_message = encrypt(concat_message, pair_key_B[0])

    encrypted_message_chars = ''
    for num in encrypted_message:
        encrypted_message_chars += chr(num)

    signed_message = encrypt(encrypted_message_chars, pair_key_A[1])
    print("Encrypted & Signed Message Sent to B:")
    print(signed_message)

    print("...Receiver's Side (B)...")

    decrypted_signature = decrypt(signed_message, pair_key_A[0])
    decrypted_input = []
    for char in decrypted_signature:
        decrypted_input.append(ord(char))
    decrypted_message = decrypt(decrypted_input, pair_key_B[1])

    print("Decrypted Message (with hash):")
    print(decrypted_message)

    if "@" in decrypted_message:
        original_message, received_hash = decrypted_message.split("@", 1)
        calculated_hash = hashlib.sha256(original_message.encode()).hexdigest()

        print("Original Message:", original_message)
        print("Received Hash   :", received_hash)
        print("Calculated Hash :", calculated_hash)

        if received_hash == calculated_hash:
            print("Message integrity and authenticity verified.")
        else:
            print("Message has been tampered with.")
    else:
        print("Message format invalid. '@' separator not found. Maybe the message got tampered.")

if __name__ == '__main__':
    main()