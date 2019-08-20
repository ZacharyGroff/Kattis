def handle_query(records, columns, is_last_query):
  print(" ".join(columns))
  column_number = columns.index(input())
  sorted_records = sorted(records, key=lambda x: x[column_number])
  for record in sorted_records:
    print(" ".join(record))
  if not is_last_query:
    print()
  return sorted_records

def main():
  columns = input().split()
  records = []
  num_records = int(input())
  for record in range(num_records):
    records.append(input().split())
  num_queries = int(input())
  for query in range(num_queries):
    records = handle_query(records, columns, True if query == num_queries-1 else False)
      

if __name__ == "__main__":
  main()
