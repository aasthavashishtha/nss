import hashlib

def sha256_hash(text):
    # Encode the string to bytes, then hash
    sha_signature = hashlib.sha256(text.encode()).hexdigest()
    return sha_signature

# Example usage
message = input("Enter a message: ")
hashed = sha256_hash(message)
print("SHA-256 hash:", hashed)
