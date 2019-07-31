fn main() {
  let p: u32 = get_p();
  for i in 0..p {
    let n: u32 = get_test_case();
    let (s1, s2, s3) = run_test_case(n);
    println!("{} {} {} {}", i+1, s1, s2, s3);
  }
}

fn get_p() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  input.trim().parse().expect("wanted a number")
}

fn get_test_case() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  let vec = input.split_whitespace().map(|x| x.parse::<u32>().expect("parse error")).collect::<Vec<u32>>();

  vec[1]
}

fn run_test_case(n: u32) -> (u32, u32, u32) {
  let s1: u32 = get_s1(n);
  let s2: u32 = get_s2(n);
  let s3: u32 = get_s3(n);
 
  (s1, s2, s3)
}

fn get_s1(n: u32) -> u32 {
  (1..n+1).fold(0, |a, b| a + b)
}

fn get_s2(mut n: u32) -> u32 {
  let mut sum: u32 = 0;
  let mut count: u32 = 1;
  while n > 0 {
    if count % 2 == 1 {
      sum += count;
      n -= 1;
    }
    count += 1;
  }

  sum
}

fn get_s3(mut n: u32) -> u32 {
  let mut sum: u32 = 0;
  let mut count: u32 = 1;
  while n > 0 {
    if count % 2 == 0 {
      sum += count;
      n -= 1;
    }
    count += 1;
  }

  sum
}
