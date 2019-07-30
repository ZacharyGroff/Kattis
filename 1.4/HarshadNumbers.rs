fn main() {
  let n: u32 = get_n();
  let smallest: u32 = get_smallest_harshad(n);
  println!("{}", smallest);
}

fn get_n() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");

  input.trim().parse().expect("wanted a number")
}

fn get_sum_of_digits(mut n: u32) -> u32 {
  let mut sum: u32 = 0;
  while n > 0 {
    sum += n % 10;
    n /= 10;
  }
  
  sum
}

fn is_harshad_number(n: u32, sum_of_digits: u32) -> bool {
  n % sum_of_digits == 0
}

fn get_smallest_harshad(mut n: u32) -> u32 {
  loop {
    let sum_of_digits: u32 = get_sum_of_digits(n);
    if is_harshad_number(n, sum_of_digits) {
      return n;
    }
    n += 1;
  }
}
