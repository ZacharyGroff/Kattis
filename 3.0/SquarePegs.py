import math

def get_houses():
  circle_radii = list(map(int, input().split()))
  squares_sides = list(map(int, input().split()))
  for square_side in squares_sides:
    square_radius = square_side * (math.sqrt(2) / 2)
    circle_radii.append(square_radius)
  return circle_radii

def num_filled_plots(plots, houses):
  result = 0
  for plot in plots:
    for house in houses:
      if plot > house:
        result += 1
        houses.remove(house)
        break
  return result

def main():
  num_plots, num_circles, num_squares = map(int, input().split())
  plots = list(map(int, input().split()))
  houses = get_houses()

  plots.sort()
  houses.sort()

  print(num_filled_plots(plots, houses))

if __name__ == '__main__':
  main()
