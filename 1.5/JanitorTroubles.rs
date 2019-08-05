fn main() {
  let input = get_input_line::<f64>().unwrap();
  let semiperimeter: f64 = input.iter().sum::<f64>() / 2.;
  let result = brahmagupta(input[0], input[1], input[2], input[3], semiperimeter);
  println!("{}", result);
}

fn get_input_line<T: std::str::FromStr>() -> Result<Vec<T>, <T as std::str::FromStr>::Err> {
  let mut input = String::new();
  let _ = std::io::stdin().read_line(&mut input);
  
  input.split_whitespace().map(|x| x.parse::<T>()).collect()
}

fn brahmagupta(a: f64, b: f64, c: f64, d: f64, s: f64) -> f64 {
  f64::sqrt((s - a) * (s - b) * (s - c) * (s - d))
}
