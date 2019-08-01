fn main() {
  let n = get_n();
  let total_area = get_total_area(n);

  println!("{}", total_area);
}

fn get_n() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");

  input.trim().parse().expect("wanted a number")
}

fn get_line() -> (f64, f64) {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  let vec = input.split_whitespace().map(|x| x.parse::<f64>().expect("parse error")).collect::<Vec<f64>>();

  (vec[0], vec[1])
}

fn calculate_area(ms1: f64, ms2: f64, g1: f64, g2: f64) -> f64 {
  (((g1 + g2) / 2.) * (ms2 - ms1)) / 1000.
}

fn get_total_area(n: u32) -> f64{
  let (mut prev_ms, mut prev_glucose) = get_line();
  let mut total_area: f64 = 0.;
  
  for _ in 1..n {
    let (curr_ms, curr_glucose) = get_line();
    let area = calculate_area(prev_ms, curr_ms, prev_glucose, curr_glucose);

    total_area += area;
    prev_ms = curr_ms;
    prev_glucose = curr_glucose;
  }

  total_area
}
