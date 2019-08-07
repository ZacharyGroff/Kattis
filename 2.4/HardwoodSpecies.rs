fn main() {
  let mut map = std::collections::HashMap::new();
  let mut total_trees = 0;
  loop {
    let tree = try_get_input_line();
    if tree == "" {
      break;
    }
    let count = map.entry(tree).or_insert(0);
    *count += 1;
    total_trees += 1;
  }
  let mut count_vec: Vec<(&String, &u64)> = map.iter().collect();
  count_vec.sort_by(|a, b| a.0.cmp(b.0));
  for (species, count) in count_vec {
    let formatted_count = format_count(*count as f64, total_trees as f64);
    println!("{} {}", *species, formatted_count);
  }
}

fn try_get_input_line() -> String {
  let mut input = String::new();
  match std::io::stdin().read_line(&mut input) {
    Ok(_) => return input.trim().to_string(),
    _ => return String::new(),
  }
}

fn format_count(count: f64, total_trees: f64) -> f64 {
  ((count / total_trees) * 100000000.).round() / 1000000.
}
