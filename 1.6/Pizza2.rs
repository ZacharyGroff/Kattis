fn main() {
  let (r, c) = get_input();
  let result = calculate(r, c);
  println!("{:.6}", as_percentage(result));
}

fn get_input() -> (f64, f64) {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  let vec = input.split_whitespace().map(|x| x.parse::<f64>().expect("parse error")).collect::<Vec<f64>>();

  (vec[0], vec[1])
}

fn calculate(r: f64, c: f64) -> f64 {
  f64::powf(r - c, 2.) / f64::powf(r, 2.)
}

fn as_percentage(result: f64) -> f64 {
  100. * result
}
