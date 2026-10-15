from random import choice

n = 60      # rozmiar przestrzeni
k = 30      # liczba generacji
rule = 90  # regula dla slownika

# * - jest komorka
# _ - komorki nie ma

# [choice("_*") for i in range(n)]    lista bakterii swiata
cells = "".join([choice("_*") for i in range(n)])

cells = "_"*(n//2) + "*" + "_"*(n//2-1)
print(cells + "\n")

binary = bin(rule)[2:].zfill(8)     # konwersja reguly na liczbe binarna

# predict = ["***", "**_", "*_*", "*__", "_**", "_*_", "__*", "___"]     klucze
predict = ["".join("*" if s == "1" else "_" for s in bin(i)[2:].zfill(3)) for i in range(7, -1, -1)]

# prerule = ['_', '_', '_', '*', '*', '*', '*', '_']    wartosci
prerule = ["*" if c == "1" else "_" for c in binary]

d = dict(zip(predict, prerule))     # slownik kodowania

for i in range(k):
    # result = ""
    # for j in range(n):
    #     result += d[cells[j - 1] + cells[j] + cells[(j + 1) * (j < n-1)]]
    # cells = result
    cells = "".join(d[cells[j - 1] + cells[j] + cells[(j + 1) * (j < n-1)]] for j in range(n))
    print(cells)