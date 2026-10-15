import pygame
import time
import random

pygame.init()

# Kolory
bialy = (255, 255, 255)
czarny = (0, 0, 0)
czerwony = (255, 0, 0)
zielony = (0, 155, 0)

# Ustawienia okna
szerokosc_okna = 800
wysokosc_okna = 600
okno = pygame.display.set_mode((szerokosc_okna, wysokosc_okna))
pygame.display.set_caption('Snake')

# Ustawienia gry
wielkosc_bloku = 20
predkosc_gry = 15

zegar = pygame.time.Clock()
czcionka = pygame.font.SysFont(None, 30)


def wiadomosc(msg, kolor):
    napis = czcionka.render(msg, True, kolor)
    okno.blit(napis, [szerokosc_okna / 6, wysokosc_okna / 3])


def punkty(punktacja):
    tekst = czcionka.render("Punkty: " + str(punktacja), True, czarny)
    okno.blit(tekst, [5, 5])


def rysuj_weza(wielkosc_bloku, lista_weza):
    for XY in lista_weza:
        pygame.draw.rect(okno, zielony, [XY[0], XY[1], wielkosc_bloku, wielkosc_bloku])


def gra():
    koniec_gry = False
    koniec = False

    # Początkowa pozycja węża
    x = szerokosc_okna / 2
    y = wysokosc_okna / 2

    # Początkowy ruch węża
    x_zmiana = 0
    y_zmiana = 0

    # Lista segmentów węża
    lista_weza = []
    dlugosc_weza = 1

    # Losowa pozycja startowa jedzenia
    jedzenie_x = round(random.randrange(0, szerokosc_okna - wielkosc_bloku) / wielkosc_bloku) * wielkosc_bloku
    jedzenie_y = round(random.randrange(0, wysokosc_okna - wielkosc_bloku) / wielkosc_bloku) * wielkosc_bloku

    while not koniec:

        while koniec_gry == True:
            okno.fill(bialy)
            wiadomosc("Przegrałeś! Naciśnij C-kontynuuj lub Q-wyjdź", czerwony)
            punkty(dlugosc_weza - 1)
            pygame.display.update()

            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        koniec = True
                        koniec_gry = False
                    if event.key == pygame.K_c:
                        gra()
                if event.type == pygame.QUIT:
                    koniec = True
                    koniec_gry = False

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                koniec = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x_zmiana = -wielkosc_bloku
                    y_zmiana = 0
                elif event.key == pygame.K_RIGHT:
                    x_zmiana = wielkosc_bloku
                    y_zmiana = 0
                elif event.key == pygame.K_UP:
                    y_zmiana = -wielkosc_bloku
                    x_zmiana = 0
                elif event.key == pygame.K_DOWN:
                    y_zmiana = wielkosc_bloku
                    x_zmiana = 0

        # Przechodzenie przez ściany zamiast kolizji
        x += x_zmiana
        y += y_zmiana

        # Jeśli wąż wyjdzie poza ekran, pojawia się z drugiej strony
        if x >= szerokosc_okna:
            x = 0
        elif x < 0:
            x = szerokosc_okna - wielkosc_bloku

        if y >= wysokosc_okna:
            y = 0
        elif y < 0:
            y = wysokosc_okna - wielkosc_bloku

        okno.fill(bialy)
        pygame.draw.rect(okno, czerwony, [jedzenie_x, jedzenie_y, wielkosc_bloku, wielkosc_bloku])

        glowa_weza = []
        glowa_weza.append(x)
        glowa_weza.append(y)
        lista_weza.append(glowa_weza)

        if len(lista_weza) > dlugosc_weza:
            del lista_weza[0]

        # Sprawdzenie kolizji z własnym ciałem
        for segment in lista_weza[:-1]:
            if segment == glowa_weza:
                koniec_gry = True

        rysuj_weza(wielkosc_bloku, lista_weza)
        punkty(dlugosc_weza - 1)

        pygame.display.update()

        # Sprawdzenie czy wąż zjadł jedzenie
        if x == jedzenie_x and y == jedzenie_y:
            jedzenie_x = round(random.randrange(0, szerokosc_okna - wielkosc_bloku) / wielkosc_bloku) * wielkosc_bloku
            jedzenie_y = round(random.randrange(0, wysokosc_okna - wielkosc_bloku) / wielkosc_bloku) * wielkosc_bloku
            dlugosc_weza += 1

        zegar.tick(predkosc_gry)

    pygame.quit()
    quit()


gra()