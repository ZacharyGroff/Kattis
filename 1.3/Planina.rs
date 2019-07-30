fn main() {
  let n: u32 = get_n();
  let points: u32 = calculate_points(n);
  println!("{}", points);
}

fn get_n() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  input.trim().parse().expect("wanted a number")
}

fn calculate_points(n: u32) -> u32 {
  u32::pow(u32::pow(2, n) + 1, 2)
}
