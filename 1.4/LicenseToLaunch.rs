fn main() {
  ignore_len_line();
  let vec: Vec<u32> = get_test_case();
  let min_index: u32 = get_min_index(vec);
  println!("{}", min_index);
}

fn ignore_len_line() {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
}

fn get_test_case() -> Vec<u32> {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");

  input.split_whitespace().map(|x| x.parse::<u32>().expect("parse error")).collect::<Vec<u32>>()
}

fn get_min_index(vec: Vec<u32>) -> u32 {
  let mut min: u32 = std::u32::MAX;
  let mut min_index: u32 = 0;
  for i in 0..vec.len() {
    if vec[i] < min {
      min = vec[i]; 
      min_index = i as u32;
    }
  }

  min_index
}
