text = input("Text: ")

letters = 0
words = len(text.split())
sentences = text.count('.') + text.count('?') + text.count('!')

for char in text.lower():
    if (ord(char) >= 97 and ord(char) <= 122):
        letters += 1

L = letters * 100 / words
S = sentences * 100 / words
# Coleman-Liau index is computed using the formula
index = round(0.0588 * L - 0.296 * S - 15.8)

# Finally outputs the result to the user
if (index < 1):
    print("Before Grade 1")

elif (index >= 16):
    print("Grade 16+")

else:
    print(f"Grade {index}")