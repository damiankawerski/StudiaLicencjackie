from collections import Counter
import matplotlib.pyplot as plt
import numpy as np

letters = list('aąbcćdeęfghijklłmnńoóprrsśtuvwxyzźż')

def calculate_density_from_file(filename):
    with open(filename, 'r', encoding="utf-8") as f:
        content = f.read().lower()

    counter = Counter(c for c in content if c in letters)

    letter_density = {letter: counter.get(letter, 0) for letter in letters}

    return dict(sorted(letter_density.items(), key=lambda item: item[1], reverse=True))

letter_density = calculate_density_from_file('pan-tadeusz.txt')
cipher_density = calculate_density_from_file('szyfr.txt')


print(letter_density)
print(cipher_density)

def decipher():
    global cipher_density
    global letter_density
    mapping = {}

    cipher_letters_sorted = list(cipher_density.keys())
    original_letters_sorted = list(letter_density.keys())
    
    
    
    print(cipher_letters_sorted)
    print(original_letters_sorted)

    for c, o in zip(cipher_letters_sorted, original_letters_sorted):
        mapping[c] = o


    del mapping['o']
    mapping['o'] = 'z'
    del mapping['i']
    mapping['r'] = 'o'
    del mapping['ś']
    mapping['ś'] = 'r'
    del mapping['g']
    mapping['g'] = 'w'
    del mapping['a']
    mapping['a'] = 'n'
    


    with open('szyfr.txt', 'r', encoding='utf-8') as f:
        content = f.read().lower()

    with open('deszyfrat.txt', 'w', encoding='utf-8') as d:
        for char in content:
            d.write(mapping[char] if char in mapping else char)


                

decipher()

print(len(cipher_density))
print(len(letter_density))





def show_histogram(data_dict, title):
    letters = list(data_dict.keys())
    frequencies = list(data_dict.values())

    plt.figure(figsize=(10, 5))
    plt.bar(letters, frequencies)
    plt.title(title)
    plt.xlabel("Litera")
    plt.ylabel("Częstotliwość")
    plt.grid(True)
    plt.show()


show_histogram(letter_density, "Letter_Density")
show_histogram(cipher_density, "Cipher_Density")