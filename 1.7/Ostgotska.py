inp = input().split()
num_containing_ae = sum([1 for i in inp if "ae" in i])
if num_containing_ae / len(inp) >= 0.4:
  print("dae ae ju traeligt va")
else:
  print("haer talar vi rikssvenska")
