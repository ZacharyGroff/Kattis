def print_result(lines, eof):
    lines = sorted(lines)
    max_len = len(max(lines, key=len))
    for line in lines:
      whitespace = ' ' * (max_len - len(line))
      print("{}{}".format(whitespace, line[::-1]))
    if not eof:
      print()

def main():
  while 1:
    lines = []
    try:
      while 1:
        line = input()
        if line.strip():
          lines.append(line[::-1])
        else:
          print_result(lines, False)
          break
    except(EOFError):
      print_result(lines, True)
      break

if __name__ == "__main__":
  main()
