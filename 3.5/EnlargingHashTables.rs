fn main() {
  let inputs = get_inputs();
  for input in inputs {
    let closest_prime = find_closest_prime(input*2);
    if is_prime(input) {
      println!("{}", closest_prime);
    } else {
      println!("{} ({} is not prime)", closest_prime, input);
    }
  }
}

fn get_inputs() -> Vec<u32> {
  let mut inputs: Vec<u32> = Vec::new();
  loop {
    let input = get_input_line();
    if input == 0 {
      break
    }
    inputs.push(input);
  }

  inputs
}

fn get_input_line() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");

  input.trim().parse().expect("wanted a number")
}

fn is_prime(n: u32) -> bool {
  let mut prime: bool = true;
  if n == 2 {
    return prime;
  }

  let ceil: u32 = (n as f64).sqrt() as u32 + 1;
  for i in 2..ceil {
    if n % i == 0 {
      prime = false;
    }
  }

  prime
}

fn find_closest_prime(mut n: u32) -> u32 {
  while !is_prime(n) {
    n += 1;
  }

  n
}
