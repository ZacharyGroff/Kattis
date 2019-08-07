fn main() {
  let tree_map = get_trees();
  
  let mut tree_vec: Vec<(&String, &u64)> = tree_map
    .iter()
    .collect();
  tree_vec.sort_by(|a, b| a.0.cmp(b.0));

  let total_trees: u64 = sum_trees(&tree_vec);
  print_trees(&tree_vec, total_trees);  
}

fn get_trees() -> std::collections::HashMap<String, u64> {
  let mut map = std::collections::HashMap::new();
  loop {
    let tree = try_get_input_line();
    if tree == "" {
      break;
    }
    let count = map.entry(tree).or_insert(0);
    *count += 1;
  }

  map
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

fn sum_trees(tree_vec: &Vec<(&String, &u64)>) -> u64 {
  tree_vec
    .iter()
    .map(|x| x.1)
    .sum()
}

fn print_trees(tree_vec: &Vec<(&String, &u64)>, total_trees: u64) {
  for (species, count) in tree_vec {
    let formatted_count = format_count(**count as f64, total_trees as f64);
    println!("{} {}", *species, formatted_count);
  }
}
