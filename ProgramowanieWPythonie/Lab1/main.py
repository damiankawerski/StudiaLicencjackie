# Gra rzucanie piłką

import math

gravity = 9.81
impact_radius = 1
enemy_dist = 20

def get_input():
    angle = float(input("Enter angle in degrees: "))
    while not 0 < angle < 90:
        print("Invalid angle")
        angle = float(input("Enter angle in degrees: "))
    velocity = float(input("Enter velocity in m/s: "))
    return angle, velocity

def calculate_distance(angle, velocity):
    return ((velocity ** 2) * math.sin(2 * math.radians(angle))) / gravity


def draw_scene(size, pos_1, pos_2, distance):
    scene = "@" + "_" * (size//4*3 - 1) + "@" +  "_" * (size//4 - 1)
    print (scene, len(scene))


def main():
    counter = 1
    first_player = True
    end_game = False
    while not end_game:
        print("Round", counter)
        counter += 1
        angle, velocity = get_input()
        distance = calculate_distance(angle, velocity)
        print("The ball will travel approximately", distance, "meters")
        if abs(distance - enemy_dist) <= impact_radius:
            if first_player:
                print("Player 1 wins!")
            else:
                print("Player 2 wins!")
            end_game = True
        else:
            print("Miss!")
        if first_player:
            first_player = False
        else :
            first_player = True
        draw_scene(80, 0, 0, 0)


main()
