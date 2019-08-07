fn main() {
  let n = get_n();
  let mut divisibles = get_divisibles(n);
  let result = get_result(&mut divisibles);
  println!("{}", result);
}

fn get_n() -> f64 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  
  input.trim().parse().expect("wanted a number")
}

fn get_divisibles(n: f64) -> Vec<u64> {
  let limit = n.sqrt() as u64;
  let mut divisibles = Vec::new(); 
  for i in 1..limit + 1 {
    let result = n / (i as f64);
    if result.fract() == 0.0 {
      divisibles.push((result as u64) - 1);
      divisibles.push((i as u64) - 1);
    }
  }

  divisibles
}

fn get_result(divisibles: &mut Vec<u64>) -> String {
  divisibles.sort();
  divisibles.dedup();
  
  divisibles.iter().map(|&x| x.to_string()).collect::<Vec<String>>().join(" ")
}
