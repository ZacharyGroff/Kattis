fn main() {
  let mut k: u64 = 1;
  let (l, mut n) = get_input();
  loop {
    let leftover: u64 = l % n;
    if leftover % n == 0 {
      break;
    }
    n -= leftover;
    k += 1;
  }
  println!("{}", k);
}

fn get_input() -> (u64, u64) {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  let vec = input.split_whitespace().map(|x| x.parse::<u64>().expect("parse error")).collect::<Vec<u64>>();

  (vec[0], vec[1])
}
