import hashlib

def SHA256(msg):
    sha_signature = hashlib.sha256(msg.encode()).hexdigest()
    return sha_signature

msg = input("enter msg : ")
hashed = SHA256(msg)
print("sha :",hashed)